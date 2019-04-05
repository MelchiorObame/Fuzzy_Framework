#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "BinaryExpressionModel.h"
#include "UnaryExpressionModel.h"
#include "NaryExpressionModel.h"


namespace core {
	template<class T>
	class ExpressionFactory
	{
	private:
		Memory memory;
	protected:
		virtual Expression<T> * Hold(Expression<T>*);   //    ajoute dans le memory
	public:
		typedef std::set<Expression<T>*> Memory;

		ExpressionFactory() {};
		virtual ~ExpressionFactory()	;

		virtual UnaryExpression<T>* NewUnary(UnaryExpression<T>*, Expression<T>) const;
		virtual BinaryExpression<T>* NewBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*) const;
		virtual NaryExpression<T>* NewNary(NaryExpression<T>*, std::vector<const Expression<T>*>*) const;

	};



	template<class T>
	inline Expression<T>* ExpressionFactory<T>::Hold(Expression<T>* o)
	{
		memory.insert(o);   //ajout dans la memoire
		return o;
	}

	template<class T>
	inline ExpressionFactory<T>::~ExpressionFactory() // vider la mémoire 
	{
		for (Memory::iterator it = memory.begin(); it != memory.end(); it++) {
			delete *it;
		}
	}

	template<class T>
	inline UnaryExpression<T>* ExpressionFactory<T>::NewUnary(UnaryExpression<T>* ope, Expression<T> o) const
	{
		return new UnaryExpressionModel(ope,o);
	}

	template<class T>
	inline BinaryExpression<T>* ExpressionFactory<T>::NewBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) const
	{
		return new BinaryExpressionModel(ope, l,r);
	}

	template<class T>
	inline NaryExpression<T>* ExpressionFactory<T>::NewNary(NaryExpression<T>* ope, std::vector<const Expression<T>*>* operands) const
	{
		return new NaryExpressionModel(operands, ope);
	}

}

#endif // !EXPRESSIONFACTORY_H


