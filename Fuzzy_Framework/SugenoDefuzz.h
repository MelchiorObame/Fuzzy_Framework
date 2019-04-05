#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "NaryExpression.h"

namespace fuzzy
{
	template<class T>
	class SugenoDefuzz: public core::NaryExpression<T>
	{
	public:
		SugenoDefuzz() {};
		virtual ~SugenoDefuzz() {};
		virtual T evaluate(std::vector <const core::Expression<T>*>*) const;
	};

	template<class T>
	inline T SugenoDefuzz<T>::evaluate(std::vector<const core::Expression<T>*>* operands) const
	{
		
		std::vector<const core::Expression<T>*>::const_iterator iterator_operand = operands->begin();
		T num = 0;
		T denum = 0;

		// calcul somme de la sortie : 
		for (; iterator_operand != operands->end(); iterator_operand++)
		{
			core::BinaryExpressionModel<T>*  bem = (core::BinaryExpressionModel<T>*)  (*iterator_operand);
			core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->getOpe();
			SugenoThen<T>*					 sth = (SugenoThen<T>*) bse->getTarget();

			T wi= sth->getPremiseValue();

			num += (*iterator_operand)->evaluate()  ;      // si l'iterator est de type NaryExpression , il fera directement le SugenoConclusion Zi 
			//num += (*iterator_operand)->evaluate() * wi;

			denum += sth->getPremiseValue();
		}
		if (denum != 0)
			return num / denum;
		return 0;
	}
}


#endif // !SUGENODEFUZZ_H
