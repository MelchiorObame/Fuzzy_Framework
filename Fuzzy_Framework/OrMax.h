#ifndef ORMAX_H
#define ORMAX_H

#include "Or.h"

namespace fuzzy
{
	template <class T>
	class OrMax : public Or<T>
	{
	public:
		OrMax() {};
		virtual ~OrMax() {};
		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T OrMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
		T l_Evaluation = l->evaluate();
		T r_Evaluation = r->evaluate();
		return (l_Evaluation >= r_Evaluation) ? l_Evaluation : r_Evaluation;
	}
}
#endif