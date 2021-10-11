#include <iostream>

#define MONDAY "Monday"
#define TUESDAY "Tuesday"
#define WEDNESDAY "Wednesday"
#define THURSDAY "Thursday"
#define FRIDAY "Friday"
#define SATURDAY "Saturday"
#define SUNDAY "Sunday"

int main()
{
    int answer;
    std::cout << "What is a day today?\n";
    std::cin >> answer;
	switch (answer)
	{
		case (1): {
			std::cout << "Today is " MONDAY << std::endl;
		} break;
		case (2): {
			std::cout << "Today is " TUESDAY << std::endl;
		} break;
		case (3): {
			std::cout << "Today is " WEDNESDAY << std::endl;
		} break;
		case (4): {
			std::cout << "Today is " THURSDAY << std::endl;
		} break;
		case (5): {
			std::cout << "Today is " FRIDAY << std::endl;
		} break;
		case (6): {
			std::cout << "Today is " SATURDAY << std::endl;
		} break;
		case (7): {
			std::cout << "Today is " SUNDAY << std::endl;
		} break;
		default: {
			std::cout << "Wrong day!" << std::endl;
		} break;
	}
}