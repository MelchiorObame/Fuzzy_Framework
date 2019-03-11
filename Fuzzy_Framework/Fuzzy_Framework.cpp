// Fuzzy_Framework.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "ValueModel.h"
#include "AndMin.h"
#include"AndMult.h"

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
	ValueModel<float>* v1 = new ValueModel<float>(0.1f);
	ValueModel<float>* v2 = new ValueModel<float>(0.6f);
	cout << "AndMult(" << v1->evaluate() << ", " << v2->evaluate() << ") -> " << op.evaluate(v1, v2) <<endl;
}

int main()
{
	cout << "_____  Test du Framework  _____\n";
	ValueModelTest();
	//AndMinTest();
	//AndMultTest();
	
   
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
