//Chapter 10 : Exercise 69

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;


class Shape
{
public:
	virtual int CalculateArea() = 0;

protected:
	int area = 0;
};

class Square : public Shape
{
public:
	int height = 10;

	int CalculateArea() override
	{
		area = height * height;
		return area;
	}
};

class Circle : public Shape
{
public:
	int radius = 10;

	int CalculateArea() override
	{
		area = 3.14 * (radius * radius);
		return area;
	}
};


std::string TestCase() {
	Shape* square = new Square();
	Shape* circle = new Circle();

	out << "Square Area: " << square->CalculateArea() << std::endl;
	out << "Circle Area: " << circle->CalculateArea() << std::endl;

	delete square;
	square = nullptr;

	delete circle;
	circle = nullptr;

	return out.str();
}

TEST(Chapter10, Exercise69) {

	EXPECT_EQ("Square Area: 100\nCircle Area: 314\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}