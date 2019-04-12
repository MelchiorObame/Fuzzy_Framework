#ifndef THENMULT_H
#define THENMULT_H

#include "Then.h"

namespace fuzzy
{
	template <class T>
	class ThenMult: public Then<T>
	{
	public:
		ThenMult() {};
		virtual ~ThenMult() {};

		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T ThenMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		return l->evaluate() * r->evaluate();
	}
}

#endif  //!THENMULT_H