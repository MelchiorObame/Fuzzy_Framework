#ifndef AGGMAX_H
#define AGGMAX_H

#include "Expression.h"
#include "Agg.h"


namespace fuzzy
{
	template <class T>
	class AggMax : public Agg<T>
	{
	public:
		AggMax() {};
		virtual ~AggMax() {};
		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
		T l_Evaluation = left->evaluate();
		T r_Evaluation = right->evaluate();
		return (l_Evaluation >= r_Evaluation) ? l_Evaluation : r_Evaluation;
	}
}
#endif // !AGGMAX_H
