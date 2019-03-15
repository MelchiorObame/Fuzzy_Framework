#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"
#include "NullExpressionException.h"

namespace core
{
	template<class T>
	class UnaryShadowExpression :public UnaryExpression<T>
	{
	private:
		UnaryExpression<T>* target;
	public:

		UnaryShadowExpression() {};
		virtual ~UnaryShadowExpression() {};
		virtual T evaluate(Expression<T>*) const;
	};


	template<class T>
	inline T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const
	{
		if (target != NULL)
			return target->evaluate(o);
		throw new NullExpressionException("target is Null");
	}
}

#endif // !UNARYSHADOWEXPRESSION_H

