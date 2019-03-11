#ifndef ORMAX_H
#define ORMAX_H

#include "Or.h"
#include "Expression.h"


namespace fuzzy
{
	template <class T>
	class OrMax : public Or<T>
	{
	public:
		OrMax() {};
		virtual ~OrMax() {};
		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T OrMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
		T l_Evaluation = left->evaluate();
		T r_Evaluation = right->evaluate();
		return (l_Evaluation >= r_Evaluation) ? l_Evaluation : r_Evaluation;
	}
}
#endif