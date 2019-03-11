#ifndef IS_H
#define IS_H

#include "Expression.h"
#include "UnaryExpression.h"

namespace fuzzy
{
	template <class T>
	class Is : public core::UnaryExpression<T>
	{
	public:
		Is() {};
		virtual ~Is() {};
		T evaluate(core::Expression<T>*) const = 0;
	};
}
#endif //!IS_H