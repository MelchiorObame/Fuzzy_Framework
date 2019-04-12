#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

namespace core
{
	template <class T>
	class BinaryExpression
	{
	public:
		BinaryExpression() {};
		virtual ~BinaryExpression() {};

		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

}

#endif //!BINARYEXPRESSION_H