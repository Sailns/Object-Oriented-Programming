#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

//definicja klasu
class Circle
{
public:
	Circle();
	~Circle() {}

	void Add(int x, int y); 
	std::vector<std::pair<int, int>> Get() { return _points; } // uzyskanie wektoru punktów

	std::pair<int, int> SumOfTwoVectors(size_t fPoint, size_t sPoint, size_t tPoint, size_t ePoint); //suma dwóch wektorów
	std::pair<int, int> SumOfAllPoints(); //suma punktów
	std::ostream& operator << (std::ostream& os); //przeciążamy operator wyjścia 

private:
	std::vector<std::pair<int, int>> _points; // wektor punktów
};