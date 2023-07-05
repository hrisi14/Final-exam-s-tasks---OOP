#pragma once
#include <iostream>
#include <exception>

struct MyFunction
{
	unsigned (*pred) (unsigned);
};

class NaturalFunction
{
protected:
	
	MyFunction f;

public:
	NaturalFunction(); // f(x) = x;
	NaturalFunction(MyFunction f);    //explicit!!!
	virtual ~NaturalFunction() = default;

	void setFunction(MyFunction newF);                           //CHECK!!!
	virtual unsigned evaluate(unsigned value) const;            //CHECK!!!
	unsigned countFixedPoints(int a, int b) const;	           // a and b are the bounds of an interval
};

bool validateInterval(int a, int b);  //защо в имплементацията са с & ?!?
bool checkSameResultValues(const NaturalFunction& lhs, const NaturalFunction& rhs, int a, int b);

