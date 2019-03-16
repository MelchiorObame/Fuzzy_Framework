#ifndef ISGAUSSIAN_H
#define ISGUASSIAN_H

#include "Is.h"
#include <math.h>

namespace fuzzy
{
	template<class T>
	class IsGaussian :public Is<T>
	{
	public:
		IsGaussian() {};
		IsGaussian(T _mean, T _stdDev) :mean(_mean), stdDev(_stdDev) {}
		virtual ~IsGaussian() {};
		virtual T evaluate(core::Expression<T>* o) const;

	private:
		T mean, stdDev;
	};
	template<class T>
	inline T IsGaussian<T>::evaluate(core::Expression<T>* o) const
	{
		T val = o->evaluate();
		return exp( -pow((val-mean),2) / (2*pow(stdDev,2)) );
	}
}
#endif // !ISGAUSSIAN_H
