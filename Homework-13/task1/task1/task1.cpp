#include <iostream>

#define MONDAY "Monday"
#define TUESDAY "Tuesday"
#define WEDNESDAY "Wednesday"
#define THURSDAY "Thursday"
#define FRIDAY "Friday"
#define SATURDAY "Saturday"
#define SUNDAY "Sunday"

#define MONDAY_NUM 1
#define TUESDAY_NUM 2
#define WEDNESDAY_NUM 3
#define THURSDAY_NUM 4
#define FRIDAY_NUM 5
#define SATURDAY_NUM 6
#define SUNDAY_NUM 7

int main()
{
    int answer;
    std::cout << "What is a day today?\n";
    std::cin >> answer;
	switch (answer)
	{
		case (MONDAY_NUM): {
			std::cout << "Today is " MONDAY << std::endl;
		} break;
		case (TUESDAY_NUM): {
			std::cout << "Today is " TUESDAY << std::endl;
		} break;
		case (WEDNESDAY_NUM): {
			std::cout << "Today is " WEDNESDAY << std::endl;
		} break;
		case (THURSDAY_NUM): {
			std::cout << "Today is " THURSDAY << std::endl;
		} break;
		case (FRIDAY_NUM): {
			std::cout << "Today is " FRIDAY << std::endl;
		} break;
		case (SATURDAY_NUM): {
			std::cout << "Today is " SATURDAY << std::endl;
		} break;
		case (SUNDAY_NUM): {
			std::cout << "Today is " SUNDAY << std::endl;
		} break;
		default: {
			std::cout << "Wrong day!" << std::endl;
		} break;
	}
}