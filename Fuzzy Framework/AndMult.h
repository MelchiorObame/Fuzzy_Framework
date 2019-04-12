#ifndef ANDMULT_H
#define ANDMULT_H

#include "And.h"

namespace fuzzy
{
	template <class T>
	class AndMult: public And<T>
	{
	public:
		AndMult() {};
		virtual ~AndMult() {};

		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AndMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T l_Eval = l->evaluate(),     r_Eval = r->evaluate();
		return l_Eval * r_Eval;
	}
}

#endif //!ANDMULT_H