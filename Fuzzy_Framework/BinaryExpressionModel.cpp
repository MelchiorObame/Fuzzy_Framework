#include "pch.h"
#include "BinaryExpressionModel.h"


template<class T>
core::BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _operateur, Expression<T>* _left, Expression<T>* _right):operateur(_operateur),left(_left),right(_right)
{
}

template<class T>
core::BinaryExpressionModel<T>::BinaryExpressionModel()
{
}

template<class T>
T core::BinaryExpressionModel<T>::evaluate() const
{
	if (left == NULL)
		throw new NullExpressionException("left is null");
	if (right == NULL)
		throw new NullExpressionException("right is null");
	return evaluate(left, right);
}

template<class T>
T core::BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const
{
	if (operateur == NULL)
		throw new NullExpressionException("operator is null");
	return operateur->evaluate(l, r);
}

