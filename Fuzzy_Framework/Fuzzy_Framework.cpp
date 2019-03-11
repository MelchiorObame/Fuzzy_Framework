// Fuzzy_Framework.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "ValueModel.h"

using namespace core;
using namespace std;

void ValueModelTest() {
	ValueModel<float>* val = new ValueModel<float>(0.4f);
	cout << "ValueModel fait" << endl;
}

int main()
{
	ValueModelTest();
    std::cout << "Hello World!\n"; 
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
