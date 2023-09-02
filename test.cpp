#include <iomanip>
#include <iostream>

// using namespace std;
// int main()
// {
// 	// stdout
// 	cout << "test from C++";
	
// 	// stdin
// 	// cin

// 	// stderr
// 	// cerr

// 	// general information
// 	// clog
// 	return (0);
// }

/*--------------------------------*/

// int main()
// {
// 	std::cout << "Enter two numbers:" << std::endl;
// 	int n1 = 0, n2 = 0;
// 	std::cin >> n1 >> n2;
// 	std::cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << std::endl;
// 	return (0);
// }

/*-----------NAMESPACE------------*/
// using namespace std;

// int main()
// {
// 	cout << "Enter two numbers:" << endl;
// 	int n1 = 0, n2 = 0;
// 	cin >> n1 >> n2;
// 	cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << endl;
// 	return (0);
// }

/*-----------CLASSES------------*/

// class Book
// {
// 	public:
// 		std::string	title;
// 		std::string	author;
// 		int			pages;

// };

// int main()
// {
// 	Book book;
// 	book.title = "to heaven";
// 	book.author = "karim chaouki";
// 	book.pages = 120;
// 	std::cout << book.author << " " << book.title << " " << book.pages;
// 	return (0);
// }

/*-----------CONSTRUCTOR FUNCTION------------*/

// class Book
// {
// 	public:
// 		std::string	title;
// 		std::string	author;
// 		int			pages;
// 		Book()
// 		{
// 			title = "no_title";
// 			author = "no_author";
// 			pages = 0;
// 		}
// 		Book(std::string _title, std::string _author, int _pages)
// 		{
// 			title = _title;
// 			author = _author;
// 			pages = _pages;
// 		}
// };

// int main()
// {
// 	Book book("Groking algorithmes", "author name", 120);
// 	Book book2;
// 	// book.title = "to heaven";
// 	// book.author = "karim chaouki";
// 	// book.pages = 120;
// 	// Book("groking algorithm");
// 	std::cout << book2.author << " " << book2.title << " " << book2.pages << std::endl;
// 	return (0);
// }


/*-----------OBJECT FUNCTION------------*/

// class Student 
// {
// 	public:
// 		std::string name;
// 		std::string major;
// 		double gpa;
// 		Student(std::string _name, std::string _major, double _gpa)
// 		{
// 			name = _name;
// 			major = _major;
// 			gpa = _gpa;
// 		}

// 		bool hasHonors()
// 		{
// 			if (gpa >= 3.5)
// 				return (true);
// 			return (false);
// 		}
// };

// int main()
// {
// 	Student student1("karim", "IT", 2.4);
// 	Student student2("dahmad", "IT", 3.6);
// 	std::cout << student2.hasHonors() << std::endl;
// 	return (0);
// }

/*-----------Getters and Setters------------*/

// class Movie
// {
// 	private:
// 		std::string	rating;
// 	public:
// 		std::string	title;
// 		std::string	director;
// 		Movie(std::string _title, std::string _director, std::string _rating)
// 		{
// 			title = _title;
// 			director = _director;
// 			setRating(_rating);
// 		}
// 		void	setRating(std::string _rating)
// 		{
// 			if (_rating == "G" || _rating == "PG" 
// 			|| _rating == "PG-13" || _rating == "R" 
// 			|| _rating == "NR")
// 				rating = _rating;
// 			else
// 				rating = "NR";
// 		}
// 		std::string getRating()
// 		{
// 			return (rating);
// 		}
// };

// int main()
// {
// 	Movie	avengers("The Avengers", "Joss Whedon", "PG-30");
// 	avengers.setRating("erweth");
// 	std::cout << "Rating is: "<< avengers.getRating() << std::endl;

// 	return (0);
// }

/*-----------Inheritance------------*/

// class Chef
// {
// 	public:
// 		void makeChicken()
// 		{
// 			std::cout << "The chef makes chicken" << std::endl;
// 		}
// 		void makeSalad()
// 		{
// 			std::cout << "The chef makes salad" << std::endl;
// 		}
// 		void makeSpecialDish()
// 		{
// 			std::cout << "The chef makes bbq ribs" << std::endl;
// 		}
// };

// class ItalianChef:public Chef
// {
// 	public:
// 		void	makePasta()
// 		{
// 			std::cout << "The chef makes pasta" << std::endl;
// 		}
// 		void makeSpecialDish()
// 		{
// 			std::cout << "The chef makes kesksou" << std::endl;
// 		}
// };

// int main()
// {
// 	// Chef chef;
// 	// ItalianChef italianChef;

// 	// chef.makeSpecialDish();
// 	// italianChef.makeSpecialDish();
// 	int j;
// 	int i;
// 	for( j = 1; j <= 5 ; j++)
// 	{
// 	    if ( j % 4 == 0)
// 	    {
// 	        stop = 1;
// 	        continue;
// 	    }

// 	    sum += i+j;
// 	}
// 	std::cout << sum << std::endl;
// 	return (0);
// }

// int main ()
// {
// 	int i;
// 	std::string index;

// 	// std::cout << "enter something:";
// 	i = 0;
// 	while (1)
// 	{
// 		// std::cin >> i;
// 		if (!(std::cin >> i))
// 		{
// 			std::cin.clear();
// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// 			std::cout << "Heere\n";
// 			continue;
// 		}
// 		// if (std::to_string(i).length() > 10)
// 		// 	std::cout << "Invalide input!!\n";
// 		break;
// 	}
// 	std::cout << "value is: " << i;
// 	return 0;
// }

// int main()
// {
// 	int i;
// 	std::cin >> i;
// 	std::cout << "value is: " << std::numeric_limits<std::streamsize>::max();
// 	return (0);
// }

// #include <iostream>
// #include <ctime>
// #include <iomanip> // For std::setw and std::setfill

// int main() {
//     time_t currentTime;
//     time(&currentTime);

//     struct tm *timeInfo = localtime(&currentTime);

//     char formattedTime[15];
//     sprintf(formattedTime, "%04d%02d%02d_%02d%02d%02d",
//             timeInfo->tm_year + 1900,
//             timeInfo->tm_mon + 1,
//             timeInfo->tm_mday,
//             timeInfo->tm_hour,
//             timeInfo->tm_min,
//             timeInfo->tm_sec);

//     std::cout << "Formatted time: " << formattedTime << std::endl;

//     return 0;
// }

// int main() {
//     int originalValue = 42;

//     // Creating a reference to the originalValue
//     int& reference = originalValue;

//     // Modifying the value through the reference
//     reference = 99;

//     std::cout << "originalValue: " << originalValue << std::endl; // Outputs: originalValue: 99

//     // Creating a read-only reference
//     const int& readOnlyReference = originalValue;

//     // This would result in a compilation error because readOnlyReference is read-only
//     readOnlyReference = 123;

//     std::cout << "readOnlyReference: " << readOnlyReference << std::endl; // Outputs: readOnlyReference: 99

//     return 0;
// }
// In this example, reference is a reference to the originalValue, meaning any changes made to reference also affect originalValue. The readOnlyReference is a read-only reference, which means you cannot modify the variable through it.

// References are commonly used as function parameters to allow modifying the original value or to avoid copying large objects. For instance:

// cpp
// Copy code


// void modifyValue(int& value) {
//     value = 123;
// }

// int main() {
//     int num = 7;
//     modifyValue(num);
// 	 std::string bee = NULL;
// 	 std::string *test1 = &bee;
// 	//  &test1 = bee;
//     std::cout << "num after modification: " << bee << std::endl; // Outputs: num after modification: 123

//     return 0;
// }
// Remember that references must be initialized when they are declared and cannot be reassigned to refer to a different variable once they are bound.



#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// int main () {
//   ofstream myfile("example.txt");
// //   myfile.open ("example.txt");
//   myfile << "Writing this to a file.\n";
//   myfile.close();
//   return 0;
// }

// #include <string>

// void    HelloWorld()
// {
//     std::cout << "Hello World" << std::endl;
// }
// void    HelloWorld2()
// {
//     std::cout << "Hello World 2" << std::endl;
// }

// int main()
// {
//     void(*func[2])() = {HelloWorld, HelloWorld2};

//     return (0);
// }

// int main()
// {
//     int day = 7;
//     switch (day) {
//     case 6:
//         cout << "Today is Saturday";
//         break;
//     case 7:
//         cout << "Today is Sunday";
//         break;
//     default:
//         cout << "Looking forward to the Weekend";
//     }
// }


float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
  
/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{  
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);
  
   /* Calculate area of triangle PBC */ 
   float A1 = area (x, y, x2, y2, x3, y3);
  
   /* Calculate area of triangle PAC */ 
   float A2 = area (x1, y1, x, y, x3, y3);
  
   /* Calculate area of triangle PAB */  
   float A3 = area (x1, y1, x2, y2, x, y);
    
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}
  
/* Driver program to test above function */
int main()
{
   /* Let us check whether the point P(10, 15) lies inside the triangle
      formed by A(0, 0), B(20, 0) and C(10, 30) */
   if (isInside(1, 1, 3, 4, 4, 1, 3, 2))
     cout <<"Inside";
   else
     cout <<"Not Inside";
  
   return 0;
}

 