#include <iostream>
#include <string>

class Entity
{
	public:
		int	x,y;
		void	Move(int xa, int ya)
		{
			x += xa;
			y += ya;
		}
};
//inhiretance
class Player : public Entity
{
	public:
		std::string Name;
		void	printName()
		{
			std::cout << "Name is: " << Name << std::endl;
		}
};

int main()
{
	Player p1;

	p1.x = 10;
	p1.y = 10;
	p1.Name = "karim";
	p1.Move(1, 2);
	p1.printName();
	std::cout << "value : "<< p1.x << " " << p1.y << std::endl;
	return (0);
}