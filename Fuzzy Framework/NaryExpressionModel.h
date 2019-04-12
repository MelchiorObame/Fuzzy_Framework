#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H

#include "NullExpressionException.h"

namespace core
{
	template <class T>
	class NaryExpressionModel: public NaryExpression<T>, public Expression<T>
	{
	private:
		std::vector<const Expression<T>*>* operands;
		NaryExpression<T>* operateur;

	public:
		NaryExpressionModel() {};
		NaryExpressionModel(NaryExpression<T>* _operateur, std::vector<const Expression<T>*>* _operands):operateur(_operateur), operands(_operands) {};
		virtual ~NaryExpressionModel() {};
		virtual T evaluate() const;
		virtual T evaluate(std::vector<const Expression<T>*>* operands) const;
	};

	template <class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operands->empty()) 
			throw new NullExpressionException("Operands vector is empty");
		return evaluate(operands);
	}

	template <class T>
	T NaryExpressionModel<T>::evaluate(std::vector<const Expression<T>*>* operands) const
	{
		if (operateur == NULL)
			throw new NullExpressionException("Operateur is Null");
		return operateur->evaluate(operands);
	}
}

#endif  //!NARYEXPRESSIONMODEL_H
