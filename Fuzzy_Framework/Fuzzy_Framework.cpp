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



int main()
{
	cout << "::Test du Framework::\n";
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
	
   
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
