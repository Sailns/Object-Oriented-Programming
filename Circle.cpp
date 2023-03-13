#include "Circle.h"

//realizujemy klas

Circle::Circle()
{
}

void Circle::Add(int x, int y) //metoda do dodamania koordynaty w masyw
{
	std::pair<int, int> pair_c(x, y); 
	_points.push_back(std::move(pair_c));
}

std::pair<int, int> Circle::SumOfTwoVectors(size_t fPoint, size_t sPoint, size_t tPoint, size_t ePoint) //suma wektorów 
{
	size_t sizeOfPoints = _points.size();
	if ((fPoint > sizeOfPoints && fPoint <= 0) ||
		(sPoint > sizeOfPoints && sPoint <= 0) ||
		(tPoint > sizeOfPoints && tPoint <= 0) ||
		(ePoint > sizeOfPoints && ePoint <= 0))
	{
		throw("Punkry nie powinny wychodzic za granice"); // nie można dodać 5 póktów
	}

	return std::pair<int, int>((_points[fPoint].first + _points[sPoint].first) + (_points[tPoint].first + _points[ePoint].first),
								(_points[fPoint].second + _points[sPoint].second) + (_points[tPoint].second + _points[ePoint].second));
}

std::pair<int, int> Circle::SumOfAllPoints() //suma wszystkich punktów
{
	int sumX = 0;
	int sumY = 0;
	for (auto i : _points)
	{
		sumX += i.first;
		sumY += i.second;
	}

	return std::pair<int, int>(sumX, sumY);
}

std::ostream& Circle::operator << (std::ostream& os) //przeciążamy operator wyjścia 
{
	std::ostringstream oss;

	oss << "Points: ";
	for (auto i : _points)
	{
		oss << i.first << ", " << "second ";
	}
	return oss;
}

