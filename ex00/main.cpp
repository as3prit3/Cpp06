# include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::invalid_argument("Invalid number of arguments: ./ScalarConverter <value>");
		ScalarConverter::convert(av[1]);
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
	}
}
