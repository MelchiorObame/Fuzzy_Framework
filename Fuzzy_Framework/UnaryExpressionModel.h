#pragma once
#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core
{
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T>
	{
	public:
		UnaryExpressionModel();
		UnaryExpressionModel(UnaryExpression<T>* _operand, UnaryExpression<T>*  _operateur);
		virtual ~UnaryExpressionModel();

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>* o) const;

	private:
		UnaryExpression<T>* operateur;
		Expression<T>* operand;
	};
}
#endif // !UNARYEXPRESSIONMODEL_H

