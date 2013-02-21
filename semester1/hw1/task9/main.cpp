#include <iostream>

int main()
{
	std::cout << "a = ";
	int a = 0;
	std::cin >> a;
	std::cout << "n = ";
	int n = 0;
	std::cin >> n;
	int p = 1;
	for (int i = 0; i < n; i++)
		p *= a;
	std::cout << "a^n = " << p << std::endl;
}
