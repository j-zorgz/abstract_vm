#include <iostream>
#include <stack>
#include <eOperandType.hpp>
#include <IOperand.hpp>
#include <lexer.hpp>
#include <Token.hpp>
#include <fstream>

std::string	get_instructions_from_stdin()
{
	std::string ret("");

	std::cin.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);
	while (1)
	{
		std::string line;
		try {
			std::getline(std::cin, line);
		}
		catch (std::ios_base::failure const e) {
			// std::cout << " " << e.what() << std::endl;
			if (std::cin.eof())
				std::cout << "Error : Please terminate your program with the `;;' instruction."	<< std::endl;
			else
				std::cout << "An error occured while trying to read from the standard input."	<< std::endl;
			exit(1);
		}
		if (line == ";;")
		{
			//TODO : remove the exception flags on std::cin ?
			return (ret);
		}
		ret += '\n' + line;
	}
}

std::string	get_instructions_from_file(char *filename)
{

	std::cout << "Reading from a file isn't yet supported. (file = " << filename << ")." << std::endl;
	exit(2);
	// return std::string(std::string("Not yet supported") + filename + "\n");

}

int main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout << "Usage: " << av[0] << " [file]" << std::endl;
		return (-1);
	}

	std::string	instructions;
	if (ac == 1)
		instructions = get_instructions_from_stdin();
	else
		instructions = get_instructions_from_file(av[1]);

	std::vector<Token> tokens = lexer(instructions);
}
