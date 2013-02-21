#include <iostream>

int main()
{
	int n[28];
	for (int i = 0; i < 28; i++)
		n[i] = 0;
		
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				n[i + j + k]++;
	
	int s = 0;
	for (int i = 0; i < 28; i++)
		s += n[i] * n[i];
		
	std::cout << "Число счастливых билетов: " << s << std::endl;
}
