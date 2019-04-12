#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

namespace core
{
	template <class T>
	class NaryShadowExpression : public NaryExpression<T>
	{
	private:
		NaryExpression<T>* target;

	public:
		NaryShadowExpression() {};
		NaryShadowExpression(NaryExpression<T>* _target):target(_target) {};
		virtual ~NaryShadowExpression() {};

		T evaluate(std::vector<const Expression<T>*>* operands) const;
		void setTarget(NaryExpression<T>*);
		virtual NaryExpression<T>* getTarget() const ;
	};

	template <class T>
	T NaryShadowExpression<T>::evaluate(std::vector<const Expression<T>*>* operands) const
	{
		if (target == NULL)
			throw new NullExpressionException("target is null");
		return target->evaluate(operands);
	}

	template <class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T>* _target)
	{
		target = _target;
	}

	template <class T>
	NaryExpression<T>* NaryShadowExpression<T>::getTarget() const
	{
		return target;
	}

}

#endif   //!NARYSHADOWEXPRESSION_H