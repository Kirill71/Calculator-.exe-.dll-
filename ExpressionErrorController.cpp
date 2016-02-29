#include "ExpressionErrorController.h"

bool ExpressionErrorController::is_known_operator(const char functor)
{
	if (is_math_operator(functor)) return true;
	else
	{
		switch (functor)
		{
		case POWER: case POINT:case COMA:
		case LEFT_BRACKET:case RIGHT_BRACKET:
		case FUNCTION_LEFT_BRACKET: case FUNCTION_RIGHT_BRACKET:
		case SPACE:case ALPHABET_BEGIN: case ALPHABET_END:
		case e: case �:
			return true;
		default:
			return false;
		}
	}
}

bool ExpressionErrorController::is_math_operator(const char op)
{
	switch (op)
	{
	case ADDITION: case DEDACTION:
	case MULTIPLE: case DIVISION:
		return true;
	default:
		return false;
	}
}

const string & ExpressionErrorController::exception_handling(runtime_error& ex, string& str)
{
	
	str = ex.what();
	str.shrink_to_fit();
	return str;
}

void ExpressionErrorController::check_all_errors(const string & str)
{
	size_t size= str.size();
	check_brekets(str,size);
	check_sintax(str, size);
	check_unknown_operators(str, size);
}

void ExpressionErrorController::check_brekets(const string & str, size_t size)
{
	stack<char> stack;
	for (size_t i(0); i < size; ++i)
	{
		if (str[i] == LEFT_BRACKET) stack.push(str[i]);
		else
			if (str[i] == RIGHT_BRACKET)
			{
				(!stack.empty()) ? stack.pop() : stack.push(str[i]);
			}
	}
	if (!stack.empty()) throw UnmatchedBracketsException();
}

void ExpressionErrorController::check_unknown_operators(const string & str, size_t size)
{
	for (size_t i(0); i < size; ++i)
	{
		if (!is_known_operator(str[i]) && !isdigit(str[i])) throw  UnknownOperatorException();
	}
}

void ExpressionErrorController::check_sintax(const string & str, size_t size)
{
	for (size_t i(0); i < size - 1; ++i)
	{
		if (is_math_operator(str[i])&& is_math_operator(str[i + 1])) throw UnknownSintaxException();
	}
}