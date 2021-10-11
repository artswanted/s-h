#include <iostream>

#define FILL(a)\
for (int i = 0; i < 10; i++)\
{\
	std::cout << "Input passengers for wagon #" << i+1 << std::endl;\
	std::cin >> a[i];\
}\

#define VAGONCHECKER(a)\
for (int i=0; i<10; i++) \
{\
if (a[i] < 20) {\
std::cout << "Wagon #" << i << " is empty." << std::endl;\
}\
if (a[i] > 20) {\
std::cout << "Wagon #" << i << " is overloaded" << std::endl;\
}\
}\

#define VAGONSUM(a)\
int sum = 0;\
for (int i = 0; i < 10; i++)\
{\
	sum += a[i];\
}\
std::cout << "Total passengers in all wagons are " << sum << std::endl;\

int main()
{
	int a[10];
	FILL(a);
	VAGONCHECKER(a);

}
