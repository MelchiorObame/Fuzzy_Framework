#include "stdafx.h"

#include "Expression.h"
#include "AggMax.h"
#include "AggPlus.h"
#include "AndMin.h"
#include "AndMult.h"
#include "NotMinus1.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "ThenMin.h"
#include "ThenMult.h"
#include "ValueModel.h"

#include "IsTriangle.h"
#include "IsTrapeze.h"
#include "IsGaussian.h"
#include "IsRectangle.h"
#include "IsSigmoid.h"

#include "CogDefuzz.h"
#include "SugenoDefuzz.h"
#include "SugenoConclusion.h"
#include "SugenoThen.h"

#include "FuzzyFactory.h"

using namespace core;
using namespace fuzzy;
using namespace std;

void ValueModelTest() {
	ValueModel<float> val(0.4f);
	assert(0.4f == val.evaluate());
}

void AndMinTest()
{
	AndMin<int> op;
	ValueModel<int> value1(6), value2(2);
	ValueModel<int> min = op.evaluate(&value1, &value2);
	assert(min.evaluate() == 2);
}

void AndMultTest()
{
	AndMult<float> op;
	ValueModel<float> value1(0.4f), value2(0.7f);
	ValueModel<float> result = op.evaluate(&value1, &value2);
	assert(result.evaluate() == 0.4f*0.7f);

}

void OrMaxTest()
{
	OrMax<int> op;
	ValueModel<int> value1(3), value2(2);
	ValueModel<int> result = op.evaluate(&value1, &value2);
	assert(result.evaluate() == 3);
}

void OrPlusTest()
{
	OrPlus<int> op;
	ValueModel<int> value1(3), value2(5);
	ValueModel<int> result = op.evaluate(&value1, &value2);
	assert(result.evaluate() == 8);
}

void ThenMinTest() {
	ThenMin<int> op;
	ValueModel<int> value1(12), value2(1);
	ValueModel<int> result = op.evaluate(&value1, &value2);
	assert(result.evaluate() == 1);
}

void ThenMultTest() {
	ThenMult<int> op;
	ValueModel<int> value1(3), value2(2);
	ValueModel<int> result = op.evaluate(&value1, &value2);
	assert(result.evaluate() == 6);
}

void AggPlusTest() {
	AggPlus<float> opAggPlus;
	ValueModel<float> value1(0.4f), value2(0.7f);
	ValueModel<float> result = opAggPlus.evaluate(&value1, &value2);
	assert(result.evaluate() == 1.1f);
}

void AggMaxTest() {
	AggMax<float> op;
	ValueModel<float> value1(0.4f), value2(0.7f);
	ValueModel<float> result = op.evaluate(&value1, &value2);
	assert(result.evaluate() == 0.7f);
}

void NotMinus1Test() {
	NotMinus1<float> op;
	ValueModel<float> value(0.7f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate() == 0.3f);
}

void IsTriangleTest() {
	float min, mid, max;
	min = 0.3f;
	mid = 0.6f;
	max = 2.0f;
	IsTriangle<float> op(min, mid, max);
	ValueModel<float> value(0.9f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate() == (max - value.evaluate()) / (max - mid));
}

void IsRectangleTest() {
	float start, end;
	start = 2.0f;
	end = 4.0f;
	IsRectangle<float> op(start, end);
	ValueModel<float> value(1.0f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate() == 0);
}

void IsTrapezeTest() {
	float start, ltop, rtop, end;
	start = 1.0f, ltop = 3.0f, rtop = 5.0f, end = 6.0f;
	IsTrapeze<float> op(start, ltop, rtop, end);
	ValueModel<float> value(2.0f);
	ValueModel<float> result = op.evaluate(&value);
	ValueModel<float> valueMid(4.0f);
	ValueModel<float> resultMid = op.evaluate(&valueMid);
	ValueModel<float> value3(5.3f);
	ValueModel<float> result3 = op.evaluate(&value3);
	assert(result.evaluate() == (value.evaluate() - start) / (ltop - start));
	assert(resultMid.evaluate() == 1);
	assert(result3.evaluate() == (end - value3.evaluate()) / (end - rtop));
}

void IsGaussianTest()
{
	float mean, stdDev;
	mean = 3.4f, stdDev = 0.7f;
	IsGaussian<float> op(mean, stdDev);
	ValueModel<float> value(1.2f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate() == exp(-pow((value.evaluate() - mean), 2) / (2 * pow(stdDev, 2))));
}

void IsSigmoidTest()
{
	float pente, inflection;
	pente = 0.7f, inflection = 2.0f;
	IsSigmoid<float> op(pente, inflection);
	ValueModel<float> value(1.5f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate() == 1 / (1 + exp(-pente * (value.evaluate() - inflection))));
}

void TestUnaryOperation() {
	ValueModelTest();
	NotMinus1Test();
	IsTriangleTest();
	IsRectangleTest();
	IsTrapezeTest();
	IsGaussianTest();
	IsSigmoidTest();
}

void TestBinaryOperation() {
	AndMinTest();
	AndMultTest();
	OrPlusTest();
	OrMaxTest();
	ThenMinTest();
	ThenMultTest();
	AggPlusTest();
	AggMaxTest();
}

void testMamdaniDuCours()
{
	//operators
	NotMinus1<float>        opNot;
	AndMin<float>           opAnd;
	OrMax<float>            opOr;
	ThenMin<float>          opThen;
	AggPlus<float>          opAgg;
	CogDefuzz<float>        opDefuzz;

	//fuzzy expression factory
	FuzzyFactory<float> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	//membership function
	//service
	IsTriangle<float> poor(-5,0,5);
	IsTriangle<float> good(0,5,10);
	IsTriangle<float> excellent(5,10,15);

	//tips
	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);

	//values
	ValueModel<float> service(0);
	ValueModel<float> food(0);
	ValueModel<float> tips(0);

	Expression<float> *r =
		f.NewAgg(
			f.NewAgg(
				f.NewThen(
						f.NewIs(&poor, &service),
						f.NewIs(&cheap, &tips)
				),
				f.NewThen(
					f.NewIs(&good, &service),
					f.NewIs(&average, &tips)
				)
			),
			f.NewThen(
					f.NewIs(&excellent, &service),
					f.NewIs(&generous, &tips)
			)
		);

	//defuzzification
	core::Expression<float> *system = f.NewDefuzz(&tips, r, 0, 25, 1);

	//apply input
	float s;

	while (true)
	{
		cout << "service : ";
		cin >> s;
		service.setValue(s);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
}

void testMamdani() {
	//operators
	NotMinus1<float>        opNot;
	AndMin<float>           opAnd;
	OrMax<float>            opOr;
	ThenMin<float>          opThen;
	AggPlus<float>          opAgg;
	CogDefuzz<float>        opDefuzz;

	//fuzzy expession factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	//membership function
	//service
	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);
	//food
	IsTriangle<float> rancid(-5, 0, 5);
	IsTriangle<float> delicious(5, 10, 15);
	//tips
	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);

	//values
	ValueModel<float> service(0);
	ValueModel<float> food(0);
	ValueModel<float> tips(0);

	Expression<float> *r =
		f.NewAgg(
			f.NewAgg(
				f.NewThen(
					f.NewOr(
						f.NewIs(&poor, &service),
						f.NewIs(&rancid, &food)
					),
					f.NewIs(&cheap, &tips)
				),
				f.NewThen(
					f.NewIs(&good, &service),
					f.NewIs(&average, &tips)
				)
			),
			f.NewThen(
				f.NewOr(
					f.NewIs(&excellent, &service),
					f.NewIs(&delicious, &food)
				),
				f.NewIs(&generous, &tips)
			)
		);

	//defuzzification
	Expression<float> *system = f.NewDefuzz(&tips, r, 0, 25, 1);
	float s, fo;
	while (true)
	{
		std::cout << "service : ";
		std::cin >> s;
		service.setValue(s);
		std::cout << "food : ";
		std::cin >> fo;
		food.setValue(fo);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
}

void testSugenoDefuzz()
{
	//operators
	NotMinus1<float>     opNot;
	AndMin<float>       opAnd;
	OrMax<float>        opOr;
	SugenoThen<float>   opThen;
	AggMax<float>       opAgg;
	SugenoDefuzz<float> opSugDefuzz;

	std::vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	coef.push_back(1);

	//affectation du tableau de coefficient à notre tableau
	SugenoConclusion<float> opSugConclusion = SugenoConclusion<float>(&coef);

	//fuzzy expession factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opSugDefuzz, &opSugConclusion);

	//membership function
	// service
	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);
	// food
	IsTriangle<float> rancid(-5, 0, 5);
	IsTriangle<float> delicious(5, 10, 15);
	//tips
	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);
	//values
	ValueModel<float> service(0);
	ValueModel<float> tips(0);
	ValueModel<float> food(0);

	//output : ces variables vont stocker le résultat de SugenoConclusion (zi)
	std::vector<const Expression<float>*> SugConclu_service_food;
	SugConclu_service_food.push_back(&service);
	SugConclu_service_food.push_back(&food);

	std::vector<const Expression<float>*> SC_service;
	SC_service.push_back(&service);

	//rules
	Expression<float> *r =
		f.NewThen(
			f.NewOr(
				f.NewIs(&poor, &service),
				f.NewIs(&rancid, &food)
			),
			f.NewNConclusion(&SugConclu_service_food)
		);

	Expression<float> *r1 =
		f.NewThen(
			f.NewIs(&good, &service),
			f.NewNConclusion(&SC_service)
		);

	Expression<float> *r2 =
		f.NewThen(
			f.NewOr(
				f.NewIs(&excellent, &service),
				f.NewIs(&delicious, &food)
			),
			f.NewNConclusion(&SugConclu_service_food)
		);

	std::vector<const Expression<float>*> operands;
	operands.push_back(r);
	operands.push_back(r1);
	operands.push_back(r2);
	
	//defuzzification
	Expression<float> *system = f.NewSugeno(&operands);
	float s, foo;
	while (true)
	{
		std::cout << "service : ";
		std::cin >> s;
		service.setValue(s);
		std::cout << "food : ";
		std::cin >> foo;
		food.setValue(foo);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
}

void temperatureHumidity() {
	//operators
	NotMinus1<float>        opNot;
	AndMin<float>           opAnd;
	OrMax<float>            opOr;
	ThenMin<float>          opThen;
	AggPlus<float>          opAgg;
	CogDefuzz<float>        opDefuzz;

	//fuzzy expession factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);


	float mean, stdDev;
	mean = 3.4f, stdDev = 0.7f;
	float pente, inflection;
	pente = 0.7f, inflection = 2.0f;
	//membership function
	//temperature  :: on la prend comme confortable par defaut
	IsGaussian<float> cosy(mean, stdDev);
	IsSigmoid<float> hight(pente, inflection);
	//humidity
	IsSigmoid<float> hightHumidity(0.7f, 3.0f);
	IsGaussian<float> mediumHumidity(mean, stdDev);
	IsTriangle<float> lowHumidity(-5, 0, 4);
	//présence au terrain
	IsTrapeze<float> faible(0 ,2, 4, 6);
	IsSigmoid<float> forte(1.4f, 3.0f);

	//values
	ValueModel<float> temperature(0);
	ValueModel<float> humidity(0);
	ValueModel<float> frequentation(0);

	Expression<float> *rules =
		f.NewAgg(
			f.NewAgg(
				f.NewThen(
					f.NewAnd(
						f.NewIs(&cosy, &temperature),
						f.NewIs(&lowHumidity, &humidity)
					),
					f.NewIs(&faible, &frequentation)
				),
				f.NewThen(
					f.NewOr(
						f.NewIs(&hight, &temperature),
						f.NewIs(&hightHumidity, &humidity)
					),
					f.NewIs(&faible, &frequentation)
				)
			), 
			f.NewThen(
				f.NewAnd(
					f.NewIs(&cosy, &temperature),
					f.NewIs(&mediumHumidity, &humidity)
				),
				f.NewIs(&forte, &frequentation)
			)
		);

	//defuzzification
	Expression<float> *system = f.NewDefuzz(&frequentation, rules, 0, 25, 1);
	float temp, hum;
	while (true)
	{
		cout << "temperature : ";
		cin >> temp;
		temperature.setValue(temp);
		cout << "humidity : ";
		cin >> hum;
		humidity.setValue(hum);
		std::cout << "frequentation -> " << system->evaluate() *4<<" % "<< std::endl;
	}
}

int main(int argc, _TCHAR* argv[])
{
	cout << "~ Fuzzy Framework ~" << endl;
	cout << "Testing ...\n";
	TestUnaryOperation();
	TestBinaryOperation();
	cout << ">> All Test :ok" << "\n" <<endl;

	unsigned select;
	cout << "choose system :" << endl;
	cout << "\t" << "0: Mamdani Exemple du cours" << endl;
	cout << "\t" << "1: Mamdani" << endl;
	cout << "\t" << "2: Sugeno" << endl;
	cout << "\t" << "3: TEMPERATURE AND HUMIDITY" << endl;
	cout << "\t" << "::=> ";
	cin >> select;

	if (select == 0) {
		cout << "---- MAMDANI EXEMPLE DU COURS ----" << endl;
		testMamdaniDuCours();
	}

	if (select == 1)
	{
		cout << "---- MAMDANI ----" << endl;
		testMamdani();
	}

	else if (select == 2) {
		cout << "---- SUGENO ----" << endl;
		testSugenoDefuzz();
	}

	else if (select == 3) {
		cout << "---- TEMPERATURE AND HUMIDITY ----" << endl;
		temperatureHumidity();
	}
	return 0;
}
