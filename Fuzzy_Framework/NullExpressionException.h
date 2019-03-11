#ifndef NULLEXPRESSIONEXCEPTION_H
#define NULLEXPRESSIONEXCEPTION_H

#include <string>

namespace core
{
	class NullExpressionException : public std::exception
	{
	public:
		NullExpressionException(std::string _message) :message(_message) {};
		virtual ~NullExpressionException() {};
	private:
		std::string message;
	};
}

#endif