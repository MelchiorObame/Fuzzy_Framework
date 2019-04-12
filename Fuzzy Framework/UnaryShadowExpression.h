#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

namespace core
{
	template <class T>
	class UnaryShadowExpression: public UnaryExpression<T>
	{
	private:
		UnaryExpression<T>* target;

	public: 

		UnaryShadowExpression() {};
		UnaryShadowExpression(UnaryExpression<T>* _target): target(_target) {};
		virtual ~UnaryShadowExpression() {};

		void getTarget();
		void setTarget(UnaryExpression<T>*);
		T evaluate(Expression<T>*) const;
	
	};

	template <class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const
	{
		if (target != NULL)
			return target->evaluate(o);
		throw new NullExpressionException("target is null");	
	}


	template <class T>
	void UnaryShadowExpression<T>::getTarget()
	{
		return target;
	}

	template <class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* _target)
	{
		target = _target;
	}

}

#endif