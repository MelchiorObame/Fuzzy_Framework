#pragma once
#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"

namespace core
{
	template <class T>
	class ValueModel : public Expression<T>
	{
	public:
		ValueModel();
		ValueModel(const T& _v);
		virtual ~ValueModel() {};

		virtual T evaluate() const;
		virtual void setValue(const T& v) const;

	private:
		T value;
	};
}
#endif // !VALUEMODEL_H

