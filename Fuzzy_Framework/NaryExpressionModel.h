#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H


#include <vector>
#include "Expression.h"
#include "NullExpressionException.h"
#include "NaryExpression.h"

namespace core
{
	template<class T>
	class NaryExpressionModel:public NaryExpression<T>, public Expression<T>
	{
	private:
		std::vector<const Expression<T>*>* operands;
		NaryExpression<T>* operateur;

	public:
		NaryExpressionModel() {};
		NaryExpressionModel(std::vector<const Expression<T>*>* _operands, NaryExpression<T>* _operateur):operands(_operands),operateur(_operateur) {};
		virtual ~NaryExpressionModel() {};
		virtual T evaluate() const;
		virtual T evaluate(std::vector<const Expression<T>*>* operands) const ;
	};


	template<class T>
	inline T NaryExpressionModel<T>::evaluate() const
	{	
		if (operands->empty())
			throw new NullExpressionException("Operandes vector is null");
		return this.evaluate(operands);
	}

	template<class T>
	inline T NaryExpressionModel<T>::evaluate(std::vector<const Expression<T>*>* operands) const
	{
		if (operateur == NULL)
			throw new NullExpressionException("Operateur null");
		return operateur.evaluate(operands);
	}
}

#endif // !NARYEXPRESSIONMODEL_H
