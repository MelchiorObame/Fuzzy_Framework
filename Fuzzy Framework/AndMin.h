#ifndef ANDMIN_H
#define ANDMIN_H

#include "And.h"

namespace fuzzy
{
	template <class T>
	class AndMin: public And<T>
	{
	public:
		AndMin() {};
		virtual ~AndMin() {};

		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AndMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T l_Eval = l->evaluate()    ,r_Eval = r->evaluate();
		return (l_Eval <= r_Eval) ? l_Eval : r_Eval;
	}
}

#endif  //!ANDMIN_H