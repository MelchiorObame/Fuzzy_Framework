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
		FuzzyFactory(BinaryShadowExpression<T>* _and, BinaryShadowExpression<T>* _or, BinaryShadowExpression<T>* _then, BinaryShadowExpression<T>* _agg, BinaryShadowExpression<T>* _defuzz);
		FuzzyFactory(UnaryShadowExpression<T>* _not);
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
		virtual void changeNot(Not<T>* _o);
		virtual void changeIs(Is<T>* _o);

	private:
		BinaryShadowExpression<T>* and, or , then, agg, defuzz;
		UnaryShadowExpression<T> * not;
	};

	template<class T>
	inline FuzzyFactory<T>::FuzzyFactory(BinaryShadowExpression<T>* _and, BinaryShadowExpression<T>* _or, BinaryShadowExpression<T>* _then, BinaryShadowExpression<T>* _agg, BinaryShadowExpression<T>* _defuzz):and(_and),or(_or),then(_then),agg(_agg),defuzz(_defuzz)
	{
	}

	template<class T>
	inline FuzzyFactory<T>::FuzzyFactory(UnaryShadowExpression<T>* _not):not(_not)
	{
	}

	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* _left, Expression<T>* _right) const
	{
		return new BinaryShadowExpression(And<T>* , left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* _left, Expression<T>* _right) const
	{
		return new BinaryShadowExpression(Or<T>*, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* _left, Expression<T>* _right) const
	{
		return new BinaryShadowExpression(Then<T>*, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* _left, Expression<T>* _right) const
	{
		return new BinaryShadowExpression(Agg<T>*, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* _left, Expression<T>* _right) const
	{
		return new BinaryShadowExpression(Defuzz<T>*, left, right);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* _operand) const
	{
		return new UnaryShadowExpression(Not<T>*, operand);
	}
	template<class T>
	inline Expression<T>* FuzzyFactory<T>::newIs(Is<T>* _s, Expression<T>* _operand) const
	{
		return new UnaryShadowExpression(Is<T>*, operand);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeAnd(And<T>* _o)
	{
		And a;
		a.SetOpe(_o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeOr(Or<T>* _o)
	{
		Or o;
		o.SetOpe(_o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeThen(Then<T>* _o)
	{
		Then t;
		t.SetOpe(_o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeAgg(Agg<T>* _o)
	{
		Agg agg;
		agg.SetOpe(_o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeNot(Not<T>* _o)
	{
		Not n;
		n.SetOpe(_o);
	}
	template<class T>
	inline void FuzzyFactory<T>::changeIs(Is<T>* _o)
	{
		Is i;
		i.SetOpe(_o);
	}
}
#endif
