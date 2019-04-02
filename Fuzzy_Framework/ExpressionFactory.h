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
		virtual Expression<T>* newUnary(UnaryExpression<T>*  _operateur, Expression<T>* _operand) const;
		virtual Expression<T>* newBinary(BinaryExpression<T>* _ope, Expression<T>* _left, Expression<T>* _right) const;
	private:
		Expression<T>* memory;
		UnaryExpression<T>* operateur;
		Expression<T>* operand;
		Expression<T>* left;
		Expression<T>* right;
		BinaryExpression<T>* ope;
	};
	template<class T>
	inline ExpressionFactory<T>::ExpressionFactory(Expression<T>* memory) :memory(_memory)
	{
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::Hold(Expression<T>*) const
	{

	}

	template<class T>
	inline Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* _operateur, Expression<T>* _operand) const
	{
		return new UnaryExpressionModel(operateur, operand);
	}

	template<class T>
	inline Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* _ope, Expression<T>* _left, Expression<T>* _right) const
	{
		return new UnaryExpressionModel(operateur, operand);
	}



	
}

#endif 

