
#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H

#include "BinaryExpression.h"
#include "NullExpressionException.h"

namespace core
{
	template <class T>
	class BinaryShadowExpression :public BinaryExpression<T>
	{
	private:
		BinaryExpression<T>* target;
	public:
		BinaryShadowExpression() {};
		virtual ~BinaryShadowExpression() {};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};
	template<class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (target == NULL)
			throw new NullExpressionException("target is null");
		return target->evaluate(l, r);
	}
}
#endif


