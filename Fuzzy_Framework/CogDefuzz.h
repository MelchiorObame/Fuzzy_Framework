#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h"

namespace fuzzy
{
	template<class T>
	class CogDefuzz:public MamdaniDefuzz<T>
	{
	public:
		CogDefuzz() {};
		virtual ~CogDefuzz() {};
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template<class T>
	inline T CogDefuzz<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		return T();
	}
}

#endif // !COGDEFUZZ_H
