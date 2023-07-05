#pragma once
#include "NaturalFunction.h"

struct Pair
{
	unsigned point;
	unsigned value;

	void setPointValue(unsigned newValue)
	{
		value = newValue;
	}
};

class ModifiableFunction: NaturalFunction
{
	MyFunction f;
	Pair* modifiedPoints;
	size_t modifiedPointsCounter = 0;
	size_t capacity;
	
	void free();
	void copyFrom(const ModifiableFunction& other);
	void moveFrom(ModifiableFunction&& other);

public:
	ModifiableFunction();                                      //f(x) = x;
	ModifiableFunction(MyFunction f, size_t capacity);         //explicit ?!

	//Big 6 because of the dynamic memory:
	ModifiableFunction(const ModifiableFunction& other);
	ModifiableFunction& operator=(const ModifiableFunction& other);
	ModifiableFunction(ModifiableFunction&& other);
	ModifiableFunction& operator=(ModifiableFunction&& other);
	~ModifiableFunction();
	
	void setFunction(MyFunction newF);
	unsigned evaluate(unsigned value) const override;
	//unsigned countFixedPoints(int lowerBound, int upperBound) const; -> uses the one from the base class

	bool modify(unsigned point, unsigned value);
	bool removeModification(unsigned point);

	int findPointIndex(unsigned point) const;
	void removeAllModifications();
};

