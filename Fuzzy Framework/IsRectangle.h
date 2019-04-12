#ifndef ISRECTANGLE_H
#define ISRECTANGLE_H

#include "Is.h"

namespace fuzzy
{
	template<class T>
	class IsRectangle : public Is<T>
	{
	private:
		T start, end;
	public:
		IsRectangle() {};
		IsRectangle(T _start, T _end) :start(_start), end(_end) {};
		virtual ~IsRectangle() {};

		virtual T evaluate(core::Expression<T>* o) const;
	};

	template<class T>
	inline T IsRectangle<T>::evaluate(core::Expression<T>* o) const
	{
		T val = o->evaluate();
		if (val >= start && val <= end)
			return 1;
		return 0;
	}

}
#endif // !ISRECTANGLE_H
