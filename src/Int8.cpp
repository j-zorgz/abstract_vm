#include <Int8.hpp>
#include <iostream>

Int8::Int8(void)
{

}

Int8::Int8(int8_t value)
{
	this->_value = value;
	std::cout << "Creating an Int8 object." << std::endl;
}

Int8::Int8(Int8 const & src)
{
	*this = src;
}

Int8::~Int8(void)
{

}

Int8 & Int8::operator=(Int8 const & rhs)
{
	_value = rhs._value;
	return *this;
}
