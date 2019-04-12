#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "Evaluator.h"

namespace fuzzy
{
	template <class T>
	class MamdaniDefuzz: public core::BinaryExpression<T>
	{
	public:
		typedef std::pair<std::vector<T>, std::vector<T>> Shape;

		MamdaniDefuzz():min(0), max(0), step(0) {};
		MamdaniDefuzz(const T& min, const T& max, const T& step): min(min), max(max), step(step) {};
		~MamdaniDefuzz() {};

		virtual void setMin(const T& _min)   { min = _min; }
		virtual void setStep(const T& _step) { step = _step; }
		virtual void setMax(const T& _max)   { max = _max; }

		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;

	protected:
		virtual T Defuzz(const Shape&) const = 0;

	private:
		T min, max, step;
	};

	template <class T>
	T MamdaniDefuzz<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		Evaluator<T> e;
		Evaluator<T>::Shape s = e.BuildShape(min, max, step, (core::ValueModel<T>*) left, right);
		return Defuzz(s);
	}
}

#endif