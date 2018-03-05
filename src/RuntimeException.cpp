#include <RuntimeException.hpp>

#include <iostream>

RuntimeException::~RuntimeException(void) throw()
{
}

RuntimeException & RuntimeException::operator=(RuntimeException const & rhs)
{
	memcpy(_what, rhs._what, sizeof(_what));
	return *this;
}

RuntimeException::RuntimeException() : _what("Not defined")
{
}

RuntimeException::RuntimeException(const char *what)
{
	strncpy(_what, what, sizeof(_what) - 1);
}

RuntimeException::RuntimeException(std::string const & what)
{
	strncpy(_what, what.c_str(), sizeof(_what) - 1);
}

const char * RuntimeException::what() const throw()
{
	return _what;
}
