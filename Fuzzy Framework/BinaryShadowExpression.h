#ifndef BinarySHADOWEXPRESSION_H
#define BinarySHADOWEXPRESSION_H

namespace core
{
	template <class T>
	class BinaryShadowExpression: public BinaryExpression<T>
	{
	private:
		BinaryExpression<T>* target;
	public: 
		BinaryShadowExpression() {};
		BinaryShadowExpression(BinaryExpression<T>* _target):target(_target) {};
		virtual ~BinaryShadowExpression() {};

		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		void setTarget(BinaryExpression<T>*);
		virtual BinaryExpression<T>* getTarget();
	
	};


	template <class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (target == NULL)
			throw new std::exception("target null");
		return target->evaluate(l, r);
	}

	template <class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* _target)
	{
		target = _target;
	}

	template <class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget()
	{
		return target;
	}
}

#endif //!BINARY_SHADOW_EXPRESSION_H