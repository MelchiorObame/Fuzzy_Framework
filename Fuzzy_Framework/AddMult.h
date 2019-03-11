#pragma once
#include "And.h"
namespace fuzzy{
	template <class T>
	class AddMult :public And
	{
	public:
		AddMult();
		virtual ~AddMult();
		T evaluate(l : Expression, r : Expression);
	};
}


