#include <iostream>


bool isSubstr(char* str, char* substr)
{
	int i = 0;
	int j = 0;
	while ((*(str + j) != '\0') && (*(substr + i) != '\0'))
	{
		if (*(substr + i) != *(str + j))
		{
			++j;
			i = 0;
		}
		else
		{
			++i;
			++j;
		}
	}
	return (*(substr + i) == '\0');
}


std::string boolToString(bool ans)
{
	if (ans) return "yes";
	else return "no";
}


int main() {
	char str1[] = "You are my hero";
	char str2[] = "my h";
	char str3[] = "You w";

	char* str = str1;
	char* a = str2;
	char* b = str3;

	std::cout << "A is substring STR?: " << boolToString (isSubstr(str, a)) << std::endl;
	std::cout << "B is substring STR?: " << boolToString (isSubstr(str, b)) << std::endl;
}