# include <iostream>
# include <exception>
# include <limits>
# include <iomanip>
# include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
	public:
		static void	convert(std::string str);
};
