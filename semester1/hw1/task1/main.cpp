#include <iostream>

int main()
{
	std::cout << "x = ";
	int x = 0;
	std::cin >> x;
	int sqr = x * x;
	int res = (sqr + x) * (sqr + 1) + 1;
	std::cout << "x^4 + x^3 + x^2 + x + 1 = " << res << std::endl;
}
