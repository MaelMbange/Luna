#include <iostream>

int main(void)
{
	int a = 10 + 5;
	int b = 20 - 2;
	a = a + a / 2;
	int ab = a + b;

	std::cout << ab << std::endl;

	return 0;
}
