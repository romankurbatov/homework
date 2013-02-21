#include <iostream>

long long fact(int n);

int main()
{
	std::cout << "n=";
	int n = 0;
	std::cin >> n;
	
	long long fact_n = 1;
	
	// считаем итеративно
	for (int i = 2; i <= n; i++)
		fact_n *= i;
	std::cout << "Факториал посчитан итеративно" << std::endl;
	std::cout << "n!=" << fact_n << std::endl;
	
	// считаем рекурсивно
	fact_n = fact(n);
	std::cout << "Факториал посчитан рекурсивно" << std::endl;
	std::cout << "n!=" << fact_n << std::endl;
}

long long fact(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}
