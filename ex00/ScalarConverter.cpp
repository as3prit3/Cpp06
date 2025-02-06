# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}


void	DisplayConversion(double value)
{
	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

bool	Handle_char_pseudo_literals(std::string str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return true;
	}
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return true;
	}
	return false;
}

void	ScalarConverter::convert(std::string str)
{
	if (Handle_char_pseudo_literals(str))
		return ;

	if (str.find('f') != std::string::npos && str.find('f') != str.length() - 1)
		throw std::exception();

	int	dot = 0, count = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue ;
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			throw std::exception();
		if (str[i] == '.')
			dot++;
		if (str[i] == 'f')
			count++;
	}
	if (dot > 1 || count > 1)
		throw std::exception();

	double	double_nb = std::atof(str.c_str());
	if (str.find('.') == std::string::npos && str.find('f') == std::string::npos)
	{
		if (double_nb >= std::numeric_limits<int>::min() && double_nb <= std::numeric_limits<int>::max())
			DisplayConversion(static_cast<int>(double_nb));
		else
			DisplayConversion(double_nb);
	}
	else if (str.find('.') != std::string::npos || str.find('f') != std::string::npos)
		DisplayConversion(double_nb);
}
