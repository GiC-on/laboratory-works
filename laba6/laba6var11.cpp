// Лабораторная работа 6 вариант 11
// Чупов Максим ЭиН-2 1к.

#include <iostream>
#include <string>
#include <vector>

int main()
{
	// ввод строки слов
	std::string str;
	std::cout << "enter string:\n";
	std::getline(std::cin, str);

	// подсчёт количества слов
	int wordsCount = 1;
	for(int i = 0; i < str.size()-1; i++)
	{
		if(str[i] == ' ') wordsCount++;
	}

	// создание массива и заполнение словами
	std::vector<std::string> words {str.substr(0, str.find(' '))};
	str.replace(0, str.find(' ') + 1, "");

	for(int i = 1; i < wordsCount; i++)
	{
		words.push_back(str.substr(0, str.find(' ')));
		str.erase(0, str.find(' ')+1);
	}

	// сортировка массива через Selection Sort
	for(int i = 0; i < wordsCount; i++)
	{
		int firstIndex = i;
		for(int j = i+1; j < wordsCount; j++)
		{
			if(words[j] < words[firstIndex]) firstIndex = j;
		}

		std::string buff = words[i];
		words[i] = words[firstIndex];
		words[firstIndex] = buff;
	}

	// вывод отсортированного в алфавитном порядке массива
	for(int i = 0; i < wordsCount; i++)
	{
		std::cout << words[i] << " ";
	}

	return 0;
}
