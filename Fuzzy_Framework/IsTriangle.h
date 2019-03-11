#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "Expression.h"
#include "Is.h"
#include "UnaryExpression.h"


namespace fuzzy
{
	template <class T>
	class IsTriangle : public Is<T>
	{
	public:
		IsTriangle() {};
		IsTriangle(T _min, T _mid, T _max);
		virtual ~IsTriangle() {};
		virtual T evaluate(core::Expression<T>*) const;

	private:
		T min, mid, max;
	};

	template<class T>
	inline IsTriangle<T>::IsTriangle(T _min, T _mid, T _max) : min(_min), mid(_mid), max(_max)
	{
	}

	template <class T>
	T IsTriangle<T>::evaluate(core::Expression<T>* o) const
	{

		return 0;
	}
}

#endif