#include <iostream>

int main()
{
	std::cout << "a = ";
	int a = 0;
	std::cin >> a;
	std::cout << "b = ";
	int b = 0;
	std::cin >> b;
	int q = 0;
	while (a >= b) {
		q++;
		a -= b;
	}
	std::cout << "q = " << q << std::endl;
}
