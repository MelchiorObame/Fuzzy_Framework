#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"
#include "Expression.h"

namespace fuzzy
{
	template<class T>
	class SugenoThen: public Then<T>
	{
	private:
		mutable T premiseValue;
	public:
		SugenoThen(T _premiseValue = 0) :premiseValue(_premiseValue) {};
		virtual ~SugenoThen() {};

		virtual T evaluate(core::Expression<T>* , core::Expression<T>*) const;
		virtual T getPremiseValue() const;
	};



	template<class T>
	inline T SugenoThen<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		premiseValue = l->evaluate();
		return premiseValue * r->evaluate();
	}

	template<class T>
	inline T SugenoThen<T>::getPremiseValue() const
	{
		return this->premiseValue;
	}

}
#endif // !SUGENOTHEN_H
