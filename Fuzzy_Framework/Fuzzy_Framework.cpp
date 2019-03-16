// Fuzzy_Framework.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"

#include <iostream>
#include "ValueModel.h"
#include "AndMin.h"
#include"AndMult.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "ThenMin.h"
#include "ThenMult.h"
#include "AggMax.h"
#include "AggPlus.h"
#include "IsTriangle.h"
#include "NotMinus1.h"
#include "IsRectangle.h"
#include "IsTrapeze.h"
#include "IsGaussian.h"


using namespace core;
using namespace fuzzy;
using namespace std;

void ValueModelTest() {
	ValueModel<float> val (0.4f);
	assert(0.4f == val.evaluate());
}

void AndMinTest()
{
	AndMin<float> op;
	ValueModel<float> value1(0.4f), value2(0.7f);
	ValueModel<float> min = op.evaluate(&value1, &value2);
	assert(min.evaluate() == 0.4f);
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
	assert(result.evaluate()==0.3f);
}

void IsTriangleTest() {
	float min, mid, max;
	min = 0.3f;
	mid = 0.6f;
	max = 2.0f;
	IsTriangle<float> op(min,mid,max);
	ValueModel<float> value(0.9f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate() == (max - value.evaluate()) / (max - mid));
}

void IsRectangleTest() {
	float start, end;
	start = 2.0f;
	end = 4.0f;
	IsRectangle<float> op(start,end);
	ValueModel<float> value(1.0f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate()==0);
}

void IsTrapezeTest() {
	float start,ltop,rtop,end;
	start = 1.0f ,  ltop = 3.0f,   rtop = 5.0f,  end = 6.0f;
	IsTrapeze<float> op(start,ltop,rtop, end);
	ValueModel<float> value(2.0f);
	ValueModel<float> result = op.evaluate(&value);
	ValueModel<float> valueMid(4.0f);
	ValueModel<float> resultMid = op.evaluate(&valueMid);
	ValueModel<float> value3(5.3f);
	ValueModel<float> result3 = op.evaluate(&value3);
	assert(result.evaluate() == (value.evaluate() - start)/(ltop - start));
	assert(resultMid.evaluate() == 1);
	assert(result3.evaluate() == (end-value3.evaluate())/(end -rtop));
}

void IsGaussianTest()
{
	float mean, stdDev;
	mean = 3.4f, stdDev = 0.7f;
	IsGaussian<float> op(mean, stdDev);
	ValueModel<float> value(1.2f);
	ValueModel<float> result = op.evaluate(&value);
	assert(result.evaluate()== exp(-pow((value.evaluate()-mean),2)/(2*pow(stdDev, 2))));
}


int main()
{
	cout << "Testing ...\n";
	ValueModelTest();
	AndMinTest();
	AndMultTest();
	OrPlusTest();
	OrMaxTest();
	ThenMinTest();
	ThenMultTest();
	AggPlusTest();
	AggMaxTest();
	NotMinus1Test();
	IsTriangleTest();
	IsRectangleTest();
	IsTrapezeTest();
	IsGaussianTest();
	cout << "-> All Test :ok" << endl;
	
   
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
