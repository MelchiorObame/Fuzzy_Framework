#include "pch.h"
#include "ValueModel.h"



template<class T>
core::ValueModel<T>::ValueModel()
{
}

template<class T>
core::ValueModel<T>::ValueModel(const T & _v):value(_v)
{
}

template<class T>
T core::ValueModel<T>::evaluate() const
{
	return value;
}

template<class T>
void core::ValueModel<T>::setValue(const T & v) const
{
	this->value = v;
}

