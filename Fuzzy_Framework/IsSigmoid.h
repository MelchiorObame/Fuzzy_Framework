#ifndef ISSIGMOID_H
#define ISSIGMOID_H

#include "Is.h"

namespace fuzzy
{	template<class T>
	class IsSigmoid:public Is<T>
	{
	public:
		T pente, inflection;
	public:
		IsSigmoid() {};
		IsSigmoid(T _pente, T _inflection=0) :pente(_pente), inflection(_inflection) {}
		virtual ~IsSigmoid() {};

		virtual T evaluate(core::Expression<T>* o) const;
	};

	template<class T>
	inline T IsSigmoid<T>::evaluate(core::Expression<T>* o) const
	{
		T val = o->evaluate();
		return ( 1/(1+ std::exp(-pente*(val-inflection))));
	}
}
#endif // !ISSIGMOID_H
