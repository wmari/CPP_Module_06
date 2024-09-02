#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data
{
	private:
		std::string name;

	public:

		Data();
		Data(std::string str);
		Data(Data &copy);
		~Data();

		Data &operator=(Data &copy);
		std::string getname();
};

#endif