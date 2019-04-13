#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H
#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
namespace core {
	template <class T>
	class ExpressionFactory 
	{
	public:
		ExpressionFactory(Expression<T>* _memory) ;
		ExpressionFactory() {};
		virtual ~ExpressionFactory() {};
		virtual Expression<T>* Hold(Expression<T>*) const;
		virtual Expression<T>* newUnary(UnaryExpression<T>* , Expression<T>*) const;
		virtual Expression<T>* newBinary(BinaryExpression<T>* , Expression<T>* , Expression<T>*) const;
	private:
		Expression<T>* memory;
		Expression<T> *expr;
	};
	template<class T>
	inline ExpressionFactory<T>::ExpressionFactory(Expression<T>* memory) :memory(_memory)
	{
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::Hold(Expression<T> *ex) const
	{
		*expr = *ex;
		return expr;
	}

	template<class T>
	inline Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* _operateur, Expression<T>* _operand) const
	{
		return new UnaryExpressionModel(_operateur, _operand);
	}

	template<class T>
	inline Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* _ope, Expression<T>* _left, Expression<T>* _right) const
	{
		return new UnaryExpressionModel(_operateur, _left, _right);
	}



	
}

#endif 

