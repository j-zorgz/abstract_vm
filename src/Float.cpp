#include <Float.hpp>
#include <iostream>

Float::Float(void)
{
}

Float::Float(float value)
{
	this->_value = value;
	this->_stringRepresentation = std::to_string(value);
	// std::cout << "Creating a Float object with value : " << std::to_string(_value) << std::endl;
}

Float::Float(Float const & src)
{
	*this = src;
}

Float::~Float(void)
{
}

Float & Float::operator=(Float const & rhs)
{
	_value = rhs._value;
	return *this;
}

int	Float::getPrecision(void) const
{
	return static_cast<int>(OperandTypeFloat);
}

eOperandType	Float::getType(void) const
{
	return OperandTypeFloat;
}
