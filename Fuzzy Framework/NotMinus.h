#ifndef NOTMINUS_H
#define NOTMINUS_H

#include "Not.h"

namespace fuzzy
{
	template <class T>
	class NotMinus: public Not<T>
	{
	public:
		NotMinus() {};
		virtual ~NotMinus() {};
		virtual T evaluate(core::Expression<T>*) const;
	};

	template <class T>
	T NotMinus<T>::evaluate (core::Expression<T>* operand) const
	{
		return 1-operand->evaluate();
	}
}

#endif