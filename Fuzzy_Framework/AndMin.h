#pragma once
#include "And.h"
namespace fuzzy{
	template <class T>
	class AndMin :public And
	{
	
	public:
		AndMin();
		virtual ~AndMin();
		T evaluate(l : Expression, r : Expression);
		
	};
}


