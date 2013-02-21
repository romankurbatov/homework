#include <iostream>
#include <cstdio>

int main()
{
	const int maxlen = 100;
	
	std::cout << "Введите строку (не более " << maxlen - 1 << " симв.):" << std::endl;
	char s[maxlen];
	std::fgets(s, maxlen, stdin);
	
	int op = 0;
	bool correct = true;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(')
			op++;
		else if (s[i] == ')')
			op--;
		if (op < 0) {
			correct = false;
			break;
		}
	}
	if (op != 0)
		correct = false;
		
	if (correct)
		std::cout << "Строка корректная" << std::endl;
	else
		std::cout << "Строка некорректная" << std::endl;
}
