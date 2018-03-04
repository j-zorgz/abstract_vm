#include <OperandFactory.hpp>
#include <Int8.hpp>
#include <Int16.hpp>
#include <Int32.hpp>
#include <Float.hpp>
#include <Double.hpp>

IOperand const * (OperandFactory::*OperandFactory::_hashTable[5])(std::string const &) const = {
	&OperandFactory::createInt8,
	&OperandFactory::createInt16,
	&OperandFactory::createInt32,
	&OperandFactory::createFloat,
	&OperandFactory::createDouble
};

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	return ((this->*_hashTable[type])(value));
}


IOperand const * OperandFactory::createInt8(std::string const & value) const
{
	std::cout << "Called operand factory createInt8 method with value : " << value << std::endl;
	return (new Int8(static_cast<int8_t>(std::stod(value))));
}

IOperand const * OperandFactory::createInt16(std::string const & value) const
{
	std::cout << "Called operand factory createInt16 method with value : " << value << std::endl;
	return (new Int16(static_cast<int16_t>(std::stod(value))));
}

IOperand const * OperandFactory::createInt32(std::string const & value) const
{
	std::cout << "Called operand factory createInt32 method with value : " << value << std::endl;
	return (new Int32(static_cast<int32_t>(std::stod(value))));
}

IOperand const * OperandFactory::createFloat(std::string const & value) const
{
	std::cout << "Called operand factory createFloat method with value : " << value << std::endl;
	return (new Float(static_cast<float>(std::stod(value))));
}

IOperand const * OperandFactory::createDouble(std::string const & value) const
{
	std::cout << "Called operand factory createDouble method with value : " << value << std::endl;
	return (new Double(std::stod(value)));
}

OperandFactory::OperandFactory(void)
{

}
