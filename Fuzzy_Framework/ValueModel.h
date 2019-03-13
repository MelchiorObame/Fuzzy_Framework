#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"

namespace core
{
	template <class T>
	class ValueModel : public Expression<T>
	{
	public:
		ValueModel() {};
		ValueModel(const T& _valeur) :value(_valeur) {};
		virtual ~ValueModel() {};

		void setValue(const T&);
		virtual T evaluate() const;

	private:
		T value;
	};

	template <class T>
	void ValueModel<T>::setValue(const T& v) {
		this->value = v;
	}

	template <class T>
	T ValueModel<T>::evaluate() const
	{
		return value;
	}
}
#endif