#include <iostream>
#include <array>

int main()
{
	std::array<int, 10> b;
	for (int i = 0;i < b.size() ;i++)
		b[i] = 12;
	//iterator
	for (std::array<int, 10>::iterator i = b.begin();i != b.end();i++)
		std::cout << *i;
	//[auto] not allowed in c11
	for (auto i = b.begin();i != b.end();i++)
		std::cout << *i;
	std::cout << "\n------\n";
	//[range for loop] not allowed in c11
	for (auto& i: b)
		std::cout << i;

	return (1); 
}