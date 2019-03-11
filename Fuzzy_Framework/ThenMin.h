#ifndef THENMIN_H
#define THENMIN_H

#include "Then.h"
#include "Expression.h"

namespace fuzzy
{
	template <class T>
	class ThenMin : public Then<T>
	{
	public:
		ThenMin() {};
		virtual ~ThenMin() {};

		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T ThenMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		T l_Evaluation = left->evaluate();
		T r_Evaluation = right->evaluate();
		return (l_Evaluation <= r_Evaluation) ? l_Evaluation : r_Evaluation;
	}

}

#endif