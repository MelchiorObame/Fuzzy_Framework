#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "NullExpressionException.h"

namespace core
{
	template <class T>
	class UnaryExpressionModel: public UnaryExpression<T>, public Expression<T>
	{
	public:
		UnaryExpressionModel() {};
		UnaryExpressionModel(UnaryExpression<T>* _operateur, Expression<T>* _operande): operateur(_operateur), operand(_operande) {};
		virtual ~UnaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(Expression*) const;

	private:
		UnaryExpression<T>* operateur;
		Expression<T>* operand;
	};

	template <class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if (operand == NULL)
			throw new NullExpressionException("operand is null");
		return evaluate(operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
	{
		if (operateur == NULL)
			throw new NullExpressionException("operator is null");
		return operateur->evaluate(o);
	}
}

#endif   //!UNARYEXPRESSIONMODEL_H