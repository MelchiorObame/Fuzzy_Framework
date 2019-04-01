#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "ExpressionFactory.h"
#include "Is.h"
namespace core {
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T>
	{
	public:
		FuzzyFactory() {};
		virtual ~FuzzyFactory() {};
		virtual Expression<T>* newAnd(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newOr(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newThen(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newAgg(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newDefuzz(Expression<T>* _left, Expression<T>* _right) const;
		virtual ExpressionModel<T>* newNot(Expression<T>* _operand) const;
		virtual Expression<T>* newIs(Is<T>* _s , Expression<T>* _operand) const;
	private:
		Expression<T>* operand;
		Expression<T>* left;
		Expression<T>* right;
		Is<T>* s;
	};
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* _left, Expression<T>* _right) : left(_left), right(_right) const
	{
		return new Binary(And, left, right);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* _left, Expression<T>* _right) : left(_left), right(_right) const
	{
		return new Binary(Or, left, right);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* _left, Expression<T>* _right) : left(_left), right(_right) const
	{
		return new Binary(Then, left, right);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* _left, Expression<T>* _right) : left(_left), right(_right) const
	{
		return new Binary(Agg, left, right);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* _left, Expression<T>* _right) : left(_left), right(_right) const
	{
		return new Binary(Defuzz, left, right);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* _operand) : operand(_operand) const
	{
		return new Unary(Not, operand);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Is<T>* _s, Expression<T>* _operand) : s(_s), operand(_operand) const
	{
		return new Unary(Is, operand);
	}
}
#endif
