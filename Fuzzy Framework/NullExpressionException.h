#ifndef NULLEXPRESSIONEXCEPTION_H
#define NULLEXPRESSIONEXCEPTION_H

namespace core
{
	class NullExpressionException: public std::exception
	{
	public:
		NullExpressionException(std::string _m) : message(_m) {};
		virtual ~NullExpressionException() {};

	private:
		std::string message;
	};
}

#endif