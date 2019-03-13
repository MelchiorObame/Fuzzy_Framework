#ifndef THENMIN_H
#define THENMIN_H

#include "Then.h"

namespace fuzzy
{
	template <class T>
	class ThenMin : public Then<T>
	{
	public:
		ThenMin() {};
		virtual ~ThenMin() {};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T ThenMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T l_Evaluation = l->evaluate();
		T r_Evaluation = r->evaluate();
		return (l_Evaluation <= r_Evaluation) ? l_Evaluation : r_Evaluation;
	}

}

#endif