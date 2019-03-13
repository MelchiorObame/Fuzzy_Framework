#ifndef ORPLUS_H
#define ORPLUS_H

#include "Or.h"

namespace fuzzy
{
	template<class T>
	class OrPlus : public Or<T>
	{
	public:
		OrPlus() {};
		virtual ~OrPlus() {};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T OrPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		return r->evaluate() + l->evaluate();
	}
}
#endif