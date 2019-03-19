#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "NaryExpression.h"
#include <vector>

namespace fuzzy
{
	template<class T>
	class SugenoConclusion:public core::NaryExpression<T>
	{
	private:
		const std::vector<T> *coeff;

	public:
		SugenoConclusion(std::vector<T> _coeff) :coeff(_coeff) {};
		SugenoConclusion() {};
		virtual ~SugenoConclusion() {};
		virtual T evaluate(std::vector < const core::Expression<T>*>*) const;
	};



	template<class T>
	inline T SugenoConclusion<T>::evaluate(std::vector<const core::Expression<T>*>* operands) const
	{
		return T();
	}

}

#endif // !SUGENOCONCLUSION_H
