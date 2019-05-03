#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "NaryExpression.h"

namespace fuzzy
{
    template <class T>
    class SugenoConclusion : public core::NaryExpression<T>
    {
	private:
		const std::vector<T> *coeff;

    public:
		SugenoConclusion(std::vector<T>* _coeff): coeff(_coeff) {};
		SugenoConclusion() {};
		virtual ~SugenoConclusion() {};

        virtual T evaluate(std::vector<const core::Expression<T>*>*) const;
    };

    template <class T>
    T SugenoConclusion<T>::evaluate(std::vector<const core::Expression<T>*>* operands) const
    {
		std::vector<T>::template const_iterator iter_coeff = coeff->begin();
		std::vector<const core::Expression<T>*>::template const_iterator iter_expr = operands->begin();
		T  result = 0;

		//calcul de Zi : combinaison linéaire .
		while (iter_coeff != coeff->end() && iter_expr != operands->end()) {
			T eval = (*iter_expr)->evaluate();  // evaluation de la regle courante
			result += (*iter_coeff)*eval;		//multiplication par le coefficient associé
			iter_expr++;
			iter_coeff++;
		}
		return result;
    }
}

#endif
