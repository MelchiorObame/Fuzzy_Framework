#ifndef NOTMINUS1_H
#define NOTMINUS1_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "Not.h"


namespace fuzzy
{
	template <class T>
	class NotMinus1 : public Not<T>
	{
	public:
		NotMinus1() {};
		virtual ~NotMinus1() {};
		T evaluate(core::Expression<T>* operand) const;
	};


	template <class T>
	T NotMinus1<T>::evaluate(core::Expression<T>* operand) const
	{
		return 1-operand->evaluate();
	}
}

#endif //!NOTMINUS1_H