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
	ValueModel<float>* val = new ValueModel<float>(0.4f);
	cout << "ValueModel ="<<val->evaluate() << endl;
}

void AndMinTest()
{
	AndMin<float> op;
	ValueModel<float>* value1 = new ValueModel<float>(0.4f);
	ValueModel<float>* value2 = new ValueModel<float>(0.7f);
	cout << "AndMin(" << value1->evaluate() << ", " << value2->evaluate() << ") -> " << op.evaluate(value1, value2) << endl;
}

void AndMultTest()
{
	AndMult<float> op;
	ValueModel<float>* val1 = new ValueModel<float>(0.1f);
	ValueModel<float>* val2 = new ValueModel<float>(0.6f);
	cout << "AndMult(" << val1->evaluate() << ", " << val2->evaluate() << ") -> " << op.evaluate(val1, val2) <<endl;
}

void OrMaxTest()
{
	OrMax<int> op;
	ValueModel<int>* val1 = new ValueModel<int>(3);
	ValueModel<int>* val2 = new ValueModel<int>(1);
	cout << "OrMax(" << val1->evaluate() << ", " << val2->evaluate() << ")-> " << op.evaluate(val1, val2) << endl;
}

void OrPlusTest()
{
	OrPlus<int> op;
	ValueModel<int>* val1 = new ValueModel<int>(3);
	ValueModel<int>* val2 = new ValueModel<int>(1);
	cout << "OrPlus(" << val1->evaluate() << ", " << val2->evaluate() << ")-> " << op.evaluate(val1, val2) << endl;
}

void ThenMinTest() {
	ThenMin<int> operateur;
	ValueModel<int>* val1 = new ValueModel<int>(3);
	ValueModel<int>* val2 = new ValueModel<int>(1);
	cout << "ThenMin(" << val1->evaluate() << ", " << val2->evaluate() << ")-> " << operateur.evaluate(val1, val2) << endl;
}

void ThenMultTest() {
	ThenMult<int> operateur;
	ValueModel<int>* val1 = new ValueModel<int>(3);
	ValueModel<int>* val2 = new ValueModel<int>(1);
	cout << "ThenMult(" << val1->evaluate() << ", " << val2->evaluate() << ")-> " << operateur.evaluate(val1, val2) << endl;
}

void AggPlusTest() {
	AggPlus<float> opAggPlus;
	ValueModel<float>* val1 = new ValueModel<float>(1.7f);
	ValueModel<float>* val2 = new ValueModel<float>(0.6f);
	cout << "AggPlus(" << val1->evaluate() << ", " << val2->evaluate() << ")-> " << opAggPlus.evaluate(val1, val2) << endl;
}

void AggMaxTest() {
	AggMax<float> opAggMax;
	ValueModel<float>* val1 = new ValueModel<float>(1.7f);
	ValueModel<float>* val2 = new ValueModel<float>(0.6f);
	cout << "AggMax(" << val1->evaluate() << ", " << val2->evaluate() << ")-> " << opAggMax.evaluate(val1, val2) << endl;
}

void NotMinus1Test() {
	NotMinus1<float> opNotMinus1;
	ValueModel<float>* value = new ValueModel<float>(0.7f);
	cout << "NotMinus1(" << value->evaluate() << ")-> " << opNotMinus1.evaluate(value)<<endl;
}

void IsTriangleTest() {
	float min, mid, max;
	min = 0.3f;
	mid = 0.6f;
	max = 2.0f;
	IsTriangle<float> opIsTriangle(min,mid,max);
	ValueModel<float>* value = new ValueModel<float>(0.9f);
	cout << "IsTriangle(" << value->evaluate() << ")-> " << opIsTriangle.evaluate(value)<<endl;
}



int main()
{
	cout << "_____  Test du Framework  _____\n";
	//ValueModelTest();
	
	//AndMinTest();
	//AndMultTest();
	//OrPlusTest();
	//OrMaxTest();
	//ThenMinTest();
	//ThenMultTest();
	//AggPlusTest();
	//AggMaxTest();
	NotMinus1Test();
	IsTriangleTest();   //reste à definir evaluation de IsTriangle
	
   
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
