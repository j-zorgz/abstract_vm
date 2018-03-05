#include <AVM.hpp>
#include <iostream>
#include <RuntimeException.hpp>

std::map<eInstructionType, void (AVM::*)(const Instruction &)> AVM::_funcMap =
{
	{Push, &AVM::ExecPush},
	{Pop, &AVM::ExecPop},
	{Dump, &AVM::ExecDump},
	{Assert, &AVM::ExecAssert},
	{Add, &AVM::ExecAdd},
	{Sub, &AVM::ExecSub},
	{Mul, &AVM::ExecMul},
	{Div, &AVM::ExecDiv},
	{Mod, &AVM::ExecMod},
	{Print, &AVM::ExecPrint},
	{Exit, &AVM::ExecExit}
};

AVM::AVM(void)
{
}

AVM::AVM(std::vector<Instruction> instructions) : _instructions(instructions)
{
}

AVM::AVM(AVM const & src)
{
	*this = src;
}

AVM::~AVM(void)
{
}

AVM & AVM::operator=(AVM const & rhs)
{
	_instructions = rhs._instructions;
	return *this;
}

void	AVM::execute(void)
{
	size_t	actualInstruction = 0;
	std::map<eInstructionType, void (AVM::*)(const Instruction &)>::iterator it;


	while (actualInstruction < _instructions.size())
	{
		it = _funcMap.find(_instructions[actualInstruction].getType());
		if (it == _funcMap.end())
		{
			throw RuntimeException("Wut ? In AVM::execute()");
		}
		else
		{
			(this->*(it->second))(_instructions[actualInstruction]);
		}
		actualInstruction++;
	}
}

void	AVM::ExecPush(const Instruction & instruction)
{
	std::cout << "In ExecPush." << std::endl;
	_stack.push(instruction.getValue());
}
void	AVM::ExecPop(const Instruction & instruction)
{
	std::cout << "In ExecPop." << std::endl;
	if (_stack.size() > 0)
	{
		delete _stack.top();
		_stack.pop();
	}
	else
		throw RuntimeException("Pop on empty stack.\n");
	(void)instruction;
}
void	AVM::ExecDump(const Instruction & instruction)
{
	std::cout << "In ExecDump." << std::endl;
	std::stack<const IOperand*> copy(_stack);

	int	nbr = 1;
	while (_stack.size() > 0)
	{
		const IOperand *operand = _stack.top();
		std::cout << nbr << " : " << operand->toString() << std::endl;
		nbr++;
		_stack.pop();
	}
	_stack = copy;

	(void)instruction;
}

void	AVM::ExecAssert(const Instruction & instruction)
{
	std::cout << "In ExecAssert." << std::endl;
	(void)instruction;
}

void	AVM::ExecAdd(const Instruction & instruction)
{
	(void)instruction;

	std::cout << "In ExecAdd." << std::endl;
	const IOperand	*first = pop_operand("add");
	const IOperand	*second = pop_operand("add");

	const IOperand	*added = *second + *first;
	delete first;
	delete second;
	_stack.push(added);
}
void	AVM::ExecSub(const Instruction & instruction)
{
	(void)instruction;

	std::cout << "In ExecSub." << std::endl;
	const IOperand	*first = pop_operand("sub");
	const IOperand	*second = pop_operand("sub");

	const IOperand	*added = *second - *first;
	delete first;
	delete second;
	_stack.push(added);
}
void	AVM::ExecMul(const Instruction & instruction)
{
	(void)instruction;

	std::cout << "In ExecMul." << std::endl;
	const IOperand	*first = pop_operand("mul");
	const IOperand	*second = pop_operand("mul");

	const IOperand	*added = *second * *first;
	delete first;
	delete second;
	_stack.push(added);
}
void	AVM::ExecDiv(const Instruction & instruction)
{
	(void)instruction;

	std::cout << "In ExecDiv." << std::endl;
	const IOperand	*first = pop_operand("div");
	const IOperand	*second = pop_operand("div");

	const IOperand	*added = *second / *first;
	delete first;
	delete second;
	_stack.push(added);
}
void	AVM::ExecMod(const Instruction & instruction)
{
	(void)instruction;

	std::cout << "In ExecMod." << std::endl;
	const IOperand	*first = pop_operand("mod");
	const IOperand	*second = pop_operand("mod");

	const IOperand	*added = *second % *first;
	delete first;
	delete second;
	_stack.push(added);
}
void	AVM::ExecPrint(const Instruction & instruction)
{
	std::cout << "In ExecPrint." << std::endl;
	(void)instruction;
}
void	AVM::ExecExit(const Instruction & instruction)
{
	std::cout << "In ExecExit." << std::endl;
	(void)instruction;
}

const IOperand	*AVM::pop_operand(std::string operation)
{
	if (_stack.size() > 0)
	{
		const IOperand *ret = _stack.top();
		_stack.pop();
		return (ret);
	}
	else
	{
		throw RuntimeException("Stack must have at least two instructions to execute the " + operation + " operation.");
	}
}
