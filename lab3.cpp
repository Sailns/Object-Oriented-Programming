#include "Circle.h"
#include <fstream>

//std::ostream& operator << (std::ostream& os, std::pair<int, int> mPair)
//{
//	std::ostringstream oss;
//
//	oss << mPair.first << ", " << mPair.second;
//	return oss;
//}

int main()
{
	std::ifstream file("dane.txt"); // otwarcie pliku 

	if (!file.is_open()) // jeśli plik nie był otwarty, to piszemy wiadomośc 
	{
		std::cout << "Nie mozemy otworzyc plik" << std::endl;
		return -1;
	}

	int numberOfPoints;
	file >> numberOfPoints; // sczytujemy ilość punktów
	std::cout << "ilosc punktow = " << numberOfPoints << std::endl;

	Circle circle; //klasa
	while (numberOfPoints > 0)
	{
		int x, y;
		file >> x >> y; // sczytujemy z pliku po dwie liczby x, y
		std::cout << "x i y = " << x << ", " << y;
		circle.Add(x, y);
		std::cout << std::endl;
		numberOfPoints--;
	}

	file.close(); // zamknięcie pliku
	auto resOfAllPoints = circle.SumOfAllPoints(); // suma wszystkich wektorów
	auto sumOfTwoPoints = circle.SumOfTwoVectors(0, 1, 2, 3); // suma dwuch wektorów
	std::cout << "Suma dwuch wektoruw: " << resOfAllPoints.first << ", " << resOfAllPoints.second << std::endl;
	std::cout << "Suma wszystkich wektoruw: " << sumOfTwoPoints.first << ", " << sumOfTwoPoints.second << std::endl;

	return 0;
}