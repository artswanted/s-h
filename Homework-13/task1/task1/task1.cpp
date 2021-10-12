#include <iostream>

#define MONDAY_NAME "Monday"
#define TUESDAY_NAME "Tuesday"
#define WEDNESDAY_NAME "Wednesday"
#define THURSDAY_NAME "Thursday"
#define FRIDAY_NAME "Friday"
#define SATURDAY_NAME "Saturday"
#define SUNDAY_NAME "Sunday"

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define GETNAME(index) index ## _NAME

int main()
{
    int answer;
    std::cout << "What is a day today?\n";
    std::cin >> answer;
	switch (answer)
	{
		case (MONDAY): {
			std::cout << "Today is " GETNAME(MONDAY) << std::endl;
		} break;
		case (TUESDAY): {
			std::cout << "Today is " GETNAME(TUESDAY) << std::endl;
		} break;
		case (WEDNESDAY): {
			std::cout << "Today is " GETNAME(WEDNESDAY) << std::endl;
		} break;
		case (THURSDAY): {
			std::cout << "Today is " GETNAME(THURSDAY) << std::endl;
		} break;
		case (FRIDAY): {
			std::cout << "Today is " GETNAME(FRIDAY) << std::endl;
		} break;
		case (SATURDAY): {
			std::cout << "Today is " GETNAME(SATURDAY) << std::endl;
		} break;
		case (SUNDAY): {
			std::cout << "Today is " GETNAME(SUNDAY) << std::endl;
		} break;
		default: {
			std::cout << "Wrong day!" << std::endl;
		} break;
	}
}