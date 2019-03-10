#pragma once
#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "Expression.h"
#include "BinaryExpression.h"
#include "NullExpressionException.h"

namespace core
{
	template <class T>
	class BinaryExpressionModel :public BinaryExpression<T>, public Expression<T>
	{

	public:
		BinaryExpressionModel(BinaryExpression<T>* _operateur, Expression<T>* _left, Expression<T>* _right);
		BinaryExpressionModel();
		virtual ~BinaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>* l, Expression<T>* r) const;

	private:
		Expression<T>* left;
		Expression<T>* right;
		BinaryExpression<T>* operateur;

	};
}

#endif // !BINARYEXPRESSIONMODEL_H


