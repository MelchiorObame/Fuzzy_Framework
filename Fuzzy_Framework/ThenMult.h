#ifndef THENMULT_H
#define THENMULT_H

#include "Then.h"
#include "Expression.h"

namespace fuzzy
{
	template <class T>
	class ThenMult : public Then<T>
	{
	public:
		ThenMult() {};
		virtual ~ThenMult() {};

		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};


	template <class T>
	T ThenMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		return left->evaluate()*right->evaluate();
	}

}

#endif