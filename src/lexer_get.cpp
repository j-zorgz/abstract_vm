#include <lexer.hpp>

Token getString(std::string str, size_t &i)
{
	size_t		start;
	std::string content;

	start = i;
	while (i < str.length() && (isdigit(str[i]) || isalpha(str[i])))
		i++;
	content = str.substr(start, i - start);
	Token ret(TOK_STRING, content);
	i--;
	return ret;
}

Token getOperator(std::string str, size_t &i)
{
	Token ret(TOK_OPERATOR, std::string(1, str[i]));
	return ret;
}

Token getSeparator(std::string str, size_t &i)
{
	size_t	start;
	std::string	content;

	start = i;
	while (i < str.length() && isseparator(str[i]))
	{
		i++;
	}
	content = str.substr(start, i - start);
	i--;
	return Token(TOK_SEP, content);
}

Token getDigit(std::string str, size_t &i)
{
	size_t		start;
	std::string	content;
	bool	minusOk = true;
	Token	ret;
	bool	dotSeen = false;
	int		dotOk = 0;
	/*
		Values for dotOk :
			0 : when before the dot and before first digit. Pass to 1 when first digit is read.
			1 : After the first digit when a dot is ok.
			2 : After the dot has been read.
	*/

	start = i;

	while (i < str.length())
	{
		if (str[i] == '-')
		{
			if (minusOk == false)
			{
				std::cout << "Error ! Will soon throw an exception." << std::endl;
				break; // Throw Exception
			}
			else
				minusOk = false;
		}
		else if (str[i] == '.')
		{
			if (dotOk == 0 || dotOk == 2)
			{
				std::cout << "Error ! Will soon throw an exception." << std::endl;
				break; // Throw Exception
			}
			else
				dotOk = 2;
			dotSeen = true;
		}
		else if (isdigit(str[i]))
		{
			if (dotOk == 0)
				dotOk = 1;
			minusOk = false;
		}
		else
		{
			break;
		}
		i++;
	}
	if (dotOk == 0 || (dotSeen && dotOk == 1))
	{
		std::cout << "Error ! Will soon throw an exception." << std::endl;
		// Throw exception.
	}
	content = str.substr(start, i - start);
	if (dotOk == 1)
		ret = Token(TOK_INTEGER, content);
	else
		ret = Token(TOK_REAL, content);
	i--;
	return ret;
}