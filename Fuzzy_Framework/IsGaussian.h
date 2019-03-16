#ifndef ISGAUSSIAN_H
#define ISGUASSIAN_H

#include "Is.h"

namespace fuzzy
{
	template<class T>
	class IsGaussian :public Is<T>
	{
	public:
		IsGaussian() {};
		virtual ~IsGaussian() {};
	};
}
#endif // !ISGAUSSIAN_H
