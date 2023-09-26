#include <iostream>

class Myclass
{
	public:
		int	storage;
		Myclass(int _storage)
		{
			storage = _storage;
		}
		void	printStorage()
		{
			if (storage <= 10)
				throw "out of storage";
			std::cout << "my storage is: " << storage << std::endl;
			storage--;
		}
};

int main()
{
	Myclass c(12);

	try
	{
		c.printStorage();
		c.printStorage();
		c.printStorage();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}