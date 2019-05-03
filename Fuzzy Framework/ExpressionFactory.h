#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"

namespace core
{
	template <class T>
	class ExpressionFactory
	{
	public:
		typedef std::set<Expression<T>*> Memory;

		ExpressionFactory() {};
		virtual ~ExpressionFactory();

		UnaryExpressionModel<T>* NewUnary(UnaryExpression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* NewBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		NaryExpressionModel<T>* NewNary(NaryExpression<T>*, std::vector<const Expression<T>*>*);

	private:
		Memory memory;

	protected:
		Expression<T>* Hold(Expression<T>*);   //ajoute dans la mémoire et renvoie l'expression
	};


	template <class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		for (Memory::iterator it = memory.begin(); it != memory.end(); it++)
			delete *it;
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::Hold(Expression<T>* o)
	{
		memory.insert(o);
		return o;
	}

	template <class T>
	UnaryExpressionModel<T>* ExpressionFactory<T>::NewUnary(UnaryExpression<T>* ope, Expression<T>* o) //retour + copie dans la mémoire
	{
		return (UnaryExpressionModel<T>*) Hold(new UnaryExpressionModel<T>(ope, o));
	}

	template <class T>
	BinaryExpressionModel<T>* ExpressionFactory<T>::NewBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r)
	{
		return (BinaryExpressionModel<T>*) Hold(new BinaryExpressionModel<T>(ope, l, r));
	}

	template <class T>
	NaryExpressionModel<T>* ExpressionFactory<T>::NewNary(NaryExpression<T>* operateur, std::vector<const Expression<T>*>* operands)
	{
		return (NaryExpressionModel<T>*) Hold(new NaryExpressionModel<T>(operateur, operands));
	}


}

#endif