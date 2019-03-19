#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "BinaryExpression.h"

namespace fuzzy
{
	template<class T>
	class MamdaniDefuzz: public core::BinaryExpression<T>
	{
	public:
		MamdaniDefuzz() {};
		virtual ~MamdaniDefuzz() {};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};


	template<class T>
	inline T MamdaniDefuzz<T>::evaluate(core::Expression<T>*, core::Expression<T>*) const
	{
		return T();
	}

}
#endif // !MAMDANIDEFUZZ_H
