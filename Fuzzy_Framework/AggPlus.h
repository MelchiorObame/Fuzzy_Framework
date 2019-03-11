#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "Expression.h"
#include "Agg.h"

namespace fuzzy
{

	template<class T>
	class AggPlus : public Agg<T>
	{
	public:
		AggPlus() {};
		virtual ~AggPlus() {};
		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		return  left->evaluate()+ right->evaluate();
	}
}
#endif //! AGGPLUS_H