#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include <vector>
#include "Expression.h"

namespace core
{
	template<class T>
	class NaryExpression
	{
	public:
		NaryExpression() {};
		virtual ~NaryExpression() {};
		virtual T evaluate(std::vector<const Expression<T>*>*) const = 0;
	};
}
#endif // !MAMDANIDEFUZZ_H
