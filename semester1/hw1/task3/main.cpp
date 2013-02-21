#include <iostream>

void reverse(int x[], int first, int last);
void swap(int *a, int *b);

int main()
{
	const int max_part = 10;
	const int max_array = 2 * max_part;
	
	std::cout << "m = ";
	int m = 0;
	std::cin >> m;
	if (m > max_part || m < 0)
		m = max_part;
		
	std::cout << "n = ";
	int n = 0;
	std::cin >> n;
	if (n > max_part || n < 0)
		n = max_part;
		
	int x[max_array];
	int len = m + n;
	for (int i = 0; i < len; i++)
		x[i] = 0;
		
	for (int i = 0; i < m; i++)
		std::cin >> x[i];
	for (int i = 0; i < n; i++)
		std::cin >> x[m + i];
	
	reverse(x, 0, m - 1);
	reverse(x, m, m + n - 1);
	reverse(x, 0, m + n - 1);
	
	std::cout << "Массив с переставленным началом и концом: " << std::endl;
	for (int i = 0; i < len; i++)
		std::cout << x[i] << ' ';
	std::cout << std::endl;
}

void reverse(int x[], int first, int last)
{
	if (first >= last)
		return;
	int n = (last - first + 1) / 2;
	for (int i = 0; i < n; i++)
		swap(&x[first + i], &x[last - i]);
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
