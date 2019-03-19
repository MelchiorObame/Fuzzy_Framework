#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

#include <vector>
#include "NaryExpression.h"
#include "Expression.h"
#include "NullExpressionException.h"

namespace core
{
	template<class T>
	class NaryShadowExpression:public NaryExpression<T>
	{
	private:
		NaryExpression<T>* target;

	public:
		NaryShadowExpression() {};
		NaryShadowExpression(NaryExpression<T>* _target): target(_target) {};
		virtual ~NaryShadowExpression() {};

		virtual T evaluate(std::vector< const Expression<T>*>* operands) const;
		void SetTarget(NaryExpression<T>*);
		virtual NaryExpression<T>* GetTarget() const;
	};


	template<class T>
	inline T NaryShadowExpression<T>::evaluate(std::vector<const Expression<T>*>* operands) const
	{
		if (target == NULL)
			throw new NullExpressionException("target null");
		return target->evaluate(operands);
	}

	template<class T>
	inline void NaryShadowExpression<T>::SetTarget(NaryExpression<T>* _target)
	{
		target = _target;
	}

	template<class T>
	inline NaryExpression<T>* NaryShadowExpression<T>::GetTarget() const
	{
		return target;
	}

}


#endif // !NARYSHADOWEXPRESSION_H
