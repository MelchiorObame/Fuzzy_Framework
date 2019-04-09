#ifndef MANDANIDEFUZZ_H
#define MANDANIDEFUZZ_H
#include"BinaryExpression.h"

namespace core {
	template <class T>
	class MandaniDefuzz : public BinaryExpression<T>
	{
	public:
		MandaniDefuzz(const T&, const T&, const T&);
		T evaluate(Expression<T>* l, Expression<T>* _r) const;
		virtual T defuzz(const typename Evaluator<T>::Shape&) const = 0;
		virtual ~MandaniDefuzz() {};
	};
	template<class T>
	MandaniDefuzz<T>::MandaniDefuzz(const T& _min, const T& _max, const T& _step) :
		min(_min), max(_max), step(_step)
	{
	}

	template<class T>
	T MandaniDefuzz<T>::evaluate(Expression<T>* s, Expression<T>* var) const
	{
		return defuzz(Evaluator<T>::BuildShape(min, max, step, (ValueModel<T>*)s, var));
	}

}

#endif

