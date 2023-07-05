#include "NaturalFunction.h"

NaturalFunction::NaturalFunction()      // f(x) = x;
{
	f.pred = [](unsigned value)
	{
		return value;
	};
}

NaturalFunction::NaturalFunction(MyFunction f) :f(f) {}      //explicit!!!

void NaturalFunction::setFunction(MyFunction newF)
{
	f = newF;
}
unsigned NaturalFunction::evaluate(unsigned value) const
{
	return f.pred(value);
}
unsigned NaturalFunction::countFixedPoints(int a, int b) const
{
	if (!validateInterval(a, b))
	{
		throw std::exception("Error! Invalid interval!");
	}

	unsigned counter = 0;
	for (size_t i = a; i <= b; i++)
	{
		if (f.pred(i) == i)
		{
			counter++;
		}
	}
	return counter;
}


bool validateInterval(int a, int b)
{
	return a <= b;
}
bool checkSameResultValues(const NaturalFunction& lhs, const NaturalFunction& rhs, int a, int b)
{
	if (!validateInterval(a, b))
	{
		throw std::exception("Error! Invalid interval!");
	}

	for (size_t i = a; i <= b; i++)
	{
		if (lhs.evaluate(i) == rhs.evaluate(i))
		{
			return true;
		}
	}
	return false;
}

