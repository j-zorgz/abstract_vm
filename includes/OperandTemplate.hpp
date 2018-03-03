#ifndef OPERANDTEMPLATE_HPP
# define OPERANDTEMPLATE_HPP

# include <IOperand.hpp>
# include <OperandFactory.hpp>
# include <cmath>

template <typename T>
class OperandTemplate : public IOperand{
public:
	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	std::string const & toString( void ) const;

protected:
	std::string	_stringRepresentation;
	T _value;
};

template <typename T>
std::string const & OperandTemplate<T>::toString(void) const
{
	return _stringRepresentation;
}

template <typename T>
IOperand const * OperandTemplate<T>::operator+( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());

	//TODO : Check overflow and underflow...
	// ...
	double rez;

	rez = _value + std::stod(rhs.toString());

	std::cout << "Resultat of add : " << rez << std::endl;

	OperandFactory op;
	return (op.createOperand(returnType, std::to_string(rez)));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator-( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());

	//TODO : Check overflow and underflow...
	// ...
	double rez;

	rez = _value - std::stod(rhs.toString());

	std::cout << "Resultat of add : " << rez << std::endl;

	OperandFactory op;
	return (op.createOperand(returnType, std::to_string(rez)));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator*( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());

	//TODO : Check overflow and underflow...
	// ...
	double rez;

	rez = _value * std::stod(rhs.toString());

	std::cout << "Resultat of add : " << rez << std::endl;

	OperandFactory op;
	return (op.createOperand(returnType, std::to_string(rez)));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator/( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());

	//TODO : Check overflow and underflow...
	// ...
	double rez;

	rez = _value / std::stod(rhs.toString());

	std::cout << "Resultat of add : " << rez << std::endl;

	OperandFactory op;
	return (op.createOperand(returnType, std::to_string(rez)));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator%( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());

	//TODO : Check overflow and underflow...
	// ...
	double rez;

	rez = fmod(_value, std::stod(rhs.toString()));

	std::cout << "Resultat of add : " << rez << std::endl;

	OperandFactory op;
	return (op.createOperand(returnType, std::to_string(rez)));
}

#endif