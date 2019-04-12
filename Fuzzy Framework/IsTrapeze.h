#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "Is.h"

namespace fuzzy
{
	template<class T>
	class IsTrapeze :public Is<T>
	{
	private:
		T start, ltop, rtop, end;
	public:
		IsTrapeze() {};
		IsTrapeze(T _start, T _ltop, T _rtop, T _end) :start(_start), ltop(_ltop), rtop(_rtop), end(_end) {};
		virtual ~IsTrapeze() {};

		virtual T evaluate(core::Expression<T>*) const;
	};


	template<class T>
	inline T IsTrapeze<T>::evaluate(core::Expression<T>* o) const
	{
		T val = o->evaluate();
		if (val >= start && val <= ltop)
			return (val - start) / (ltop - start);
		if (val >= rtop && val <= end)
			return (end - val) / (end - rtop);
		if (val >= ltop && val <= rtop)
			return 1;
		return 0;
	}

}

#endif // !ISTRAPEZE_H
