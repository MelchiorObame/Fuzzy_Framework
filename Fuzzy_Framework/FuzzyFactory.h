#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "Expression.h"
#include "ExpressionFactory.h"
//#include "Is.h"
//#include "And.h"
//#include "Or.h"
//#include "Then.h"
//#include "Agg.h"
//#include "Not.h"
//#include "BinaryExpression.h"
//#include "UnaryExpression.h"

namespace core {
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T>
	{
	public:
		FuzzyFactory(UnaryExpression<T>* _opNot, BinaryExpression<T>* _opAnd, BinaryExpression<T>* _opOr, BinaryExpression<T>* _opThen, BinaryExpression<T>* _opAgg, BinaryExpression<T>* _opDefuzz);
		FuzzyFactory() {};
		virtual ~FuzzyFactory() {};
		virtual Expression<T>* newAnd(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newOr(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newThen(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newAgg(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newDefuzz(Expression<T>* _left, Expression<T>* _right) const;
		virtual Expression<T>* newNot(Expression<T>* _operand) const;
		virtual Expression<T>* newIs(Is<T>* _s , Expression<T>* _operand) const;
		virtual void changeAnd(And<T>* _o);
		virtual void changeOr(Or<T>* _o);
		virtual void changeThen(Then<T>* _o);
		virtual void changeAgg(Agg<T>* _o);
		virtual void changeDefuzz(Defuzz<T>* _o);
		virtual void changeNot(Not<T>* _o);
		virtual void changeIs(Is<T>* _o);

	private:
		BinaryShadowExpression<T>* opAnd, opOr , opThen, opAgg, opDefuzz;
		UnaryShadowExpression<T> * opNot;

	};

	template<class T>
	inline FuzzyFactory<T>::FuzzyFactory(UnaryExpression<T>* _opNot, BinaryExpression<T>* _opAnd, BinaryExpression<T>* _opOr, BinaryExpression<T>* _opThen, BinaryExpression<T>* _opAgg, BinaryExpression<T>* _opDefuzz) :
		opNot(_opNot), opAnd(_opAnd), opOr(_opOr), opThen(_opThen), opAgg(_opAgg), opDefuzz(_opDefuzz)
	{
	}

	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* _left, Expression<T>* _right) const
	{
		return newBinary(opAnd, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* _left, Expression<T>* _right) const
	{
		return newBinary(opOr, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* _left, Expression<T>* _right) const
	{
		return newBinary(opThen, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* _left, Expression<T>* _right) const
	{
		return newBinary(opAgg, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* _left, Expression<T>* _right) const
	{
		return newBinary(opDefuzz, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* _operand) const
	{
		return newUnary(opNot, operand);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newIs(Is<T>* _s, Expression<T>* _operand) const
	{
		return newUnary(_s, operand);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeAnd(And<T>* _o)
	{
		opAnd->setTarget(o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeOr(Or<T>* _o)
	{
		opOr->setTarget(o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeThen(Then<T>* _o)
	{
		opThen->setTarget(o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeAgg(Agg<T>* _o)
	{
		opAgg->setTarget(o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeDefuzz(Defuzz<T>* _o)
	{
		opDefuzz->setTarget(o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeNot(Not<T>* _o)
	{
		opNot->setTarget(o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeIs(Is<T>* _o)
	{
		opIs->setTarget(o);
	}
}
#endif