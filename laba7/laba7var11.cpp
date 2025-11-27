// Лабораторная работа 7 вариант 11
// Чупов Максим ЭиН-2 1к.

#include <iostream>
#include <string>

struct student
{
	std::string fio;
	std::string adress;
	int scores[3];
};

int main()
{
	int studCount;

	std::cout << "Enter students count: ";
	std::cin >> studCount;

	student* studs = new student[studCount];
	
	// filling students' data
	for(int i = 0; i < studCount; i++)
	{
		std::cin.ignore();
		std::cout << "Enter " << i+1 << " student's FIO: ";
		std::getline(std::cin, studs[i].fio);

		std::cout << "Enter his/her adress: ";
		std::getline(std::cin, studs[i].adress);

		std::cout << "Enter his/her scores for 3 exams by space: ";
		std::cin >> studs[i].scores[0] >> studs[i].scores[1]
				 >> studs[i].scores[2];
	}

	std::cout << "\nStudents who live in Minsk city and have "
			  << "average score not less than 4.5:\n";
	
	// finding the right students
	for(int i = 0; i < studCount; i++)
	{
		if (studs[i].adress == "Minsk" && (studs[i].scores[0] +
			studs[i].scores[1] + studs[i].scores[2]) / 3.0f >= 4.5f)
		{
			std::cout << studs[i].fio.substr(0, studs[i].fio.find(' ')) << "\n";
		}
	}

	return 0;
}