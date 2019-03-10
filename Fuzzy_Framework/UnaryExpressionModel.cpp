#include "pch.h"
#include "UnaryExpressionModel.h"
#include "NullExpressionException.h"



template<class T>
core::UnaryExpressionModel<T>::UnaryExpressionModel()
{
}

template<class T>
core::UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* _operand, UnaryExpression<T>* _operateur):operand(_operand),operateur(_operateur)
{
}

template<class T>
core::UnaryExpressionModel<T>::~UnaryExpressionModel()
{
}

template<class T>
T core::UnaryExpressionModel<T>::evaluate() const
{
	if (operand == NULL)
		throw new NullExpressionException("operand is null");
	return evaluate(operand);
}

template<class T>
T core::UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
{
	if (operateur == NULL)
		throw new NullExpressionException("operand is null");
	return operateur.evaluate(o);
}
