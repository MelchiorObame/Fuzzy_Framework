#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "NullExpressionException.h"

namespace core
{
	template <class T>
	class BinaryExpressionModel :public BinaryExpression<T>, public Expression<T>
	{

	public:
		BinaryExpressionModel(BinaryExpression<T>* _operateur, Expression<T>* _left, Expression<T>* _right);
		BinaryExpressionModel() {};
		virtual ~BinaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>* l, Expression<T>* r) const;

		BinaryExpression<T>* GetOpe();
		void SetOpe(BinaryExpression<T>* op);

	private:
		Expression<T>* left;
		Expression<T>* right;
		BinaryExpression<T>* operateur;

	};

	template<class T>
	inline BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _operateur, Expression<T>* _left, Expression<T>* _right):operateur(_operateur),left(_left),right(_right)
	{
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const
	{	
		if (left == NULL)
			throw new NullExpressionException("left is null");
		if (right == NULL)
			throw new NullExpressionException("right is null");
		return evaluate(left, right);
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (operateur == NULL)
			throw new NullExpressionException("operator is null");
		return operateur->evaluate(l, r);
	}

	template<class T>
	inline BinaryExpression<T>* BinaryExpressionModel<T>::GetOpe()
	{
		return operateur;
	}

	template<class T>
	inline void BinaryExpressionModel<T>::SetOpe(BinaryExpression<T>* op)
	{
		this->operateur = op;
	}

}

#endif // !BINARYEXPRESSIONMODEL_H


