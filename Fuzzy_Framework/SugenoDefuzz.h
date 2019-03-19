#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H


#include "NaryExpression.h"
#include "Expression.h"

namespace fuzzy
{
	template<class T>
	class SugenoDefuzz: public core::NaryExpression<T>
	{
	public:
		SugenoDefuzz() {};
		virtual ~SugenoDefuzz() {};
		virtual T evaluate(std::vector < const core::Expression<T>* > *) const;

	};


	template<class T>
	inline T SugenoDefuzz<T>::evaluate(std::vector<const core::Expression<T>*>*) const
	{

		return T();
	}

}


#endif // !SUGENODEFUZZ_H
