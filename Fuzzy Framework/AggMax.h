#ifndef AGGMAX_H
#define AGGMAX_H

#include "Agg.h"

namespace fuzzy
{
	template <class T>
	class AggMax: public Agg<T>
	{
	public:
		AggMax() {};
		virtual ~AggMax() {};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T l_Evaluation = l->evaluate();
		T r_Evaluation = r->evaluate();
		return (l_Evaluation >= r_Evaluation) ? l_Evaluation : r_Evaluation;
	}
}

#endif  //!AGGMAX_H