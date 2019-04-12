#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "Agg.h"

namespace fuzzy
{
	template <class T>
	class AggPlus: public Agg<T>
	{
	public:
		AggPlus() {};
		virtual ~AggPlus() {};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		return  l->evaluate() + r->evaluate();
	}
}

#endif  //!AGGPLUS_H