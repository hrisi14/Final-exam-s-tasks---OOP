#include "ModifiableFunction.h"

void ModifiableFunction::free()
{
	delete [] modifiedPoints;
	modifiedPointsCounter = 0;
}
void ModifiableFunction::copyFrom(const ModifiableFunction& other)
{
	modifiedPointsCounter = other.modifiedPointsCounter;
	for (size_t i = 0; i < modifiedPointsCounter; i++)
	{
		modifiedPoints[i] = other.modifiedPoints[i];
	}
}

void ModifiableFunction::moveFrom(ModifiableFunction&& other)
{
	modifiedPoints = other.modifiedPoints;
	modifiedPointsCounter = 0;
	other.modifiedPoints = nullptr;
	other.modifiedPointsCounter = 0;
}


ModifiableFunction::ModifiableFunction()
{
	f.pred = [](unsigned initialValue) { return initialValue; };
	capacity = 2;
	modifiedPoints = new Pair[capacity];
	modifiedPointsCounter = 0;
}

ModifiableFunction::ModifiableFunction(MyFunction f, size_t capacity): NaturalFunction(f) 
{
	modifiedPoints = new Pair[capacity];
	this->capacity = capacity;
	modifiedPointsCounter = 0;
}


ModifiableFunction::ModifiableFunction(const ModifiableFunction& other):NaturalFunction(other)
{
	copyFrom(other);
}
ModifiableFunction& ModifiableFunction::operator=(const ModifiableFunction& other)
{
	if (this != &other)
	{
		NaturalFunction::NaturalFunction(other);
		free();
		copyFrom(other);
	}
	return *this;
}

ModifiableFunction::ModifiableFunction(ModifiableFunction&& other):NaturalFunction(std::move(other))
{
	moveFrom(std::move(other));
}

ModifiableFunction& ModifiableFunction::operator=(ModifiableFunction&& other)
{
	if (this != &other)
	{
		NaturalFunction::NaturalFunction(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ModifiableFunction::~ModifiableFunction()
{
	free();
}

void ModifiableFunction::setFunction(MyFunction newF)
{
	removeAllModifications();
	f = newF;
}

unsigned ModifiableFunction::evaluate(unsigned value) const
{
	return f.pred(value);
}

bool ModifiableFunction::modify(unsigned point, unsigned value)
{
	int pointIndex = findPointIndex(point);
	if (pointIndex == -1)
	{
		if (modifiedPointsCounter > capacity)
		{
			return false;
		}	
		modifiedPointsCounter++;
		pointIndex = modifiedPointsCounter;
	}
	modifiedPoints[pointIndex].setPointValue(value);
	return true;
}

bool ModifiableFunction::removeModification(unsigned point)
{
	int pointIndex = findPointIndex(point);
	if (pointIndex == -1)         //such a point has not been modified at all
	{
		return false;
	}
	if (pointIndex != modifiedPointsCounter)
	{
		std::swap(modifiedPoints[pointIndex], modifiedPoints[modifiedPointsCounter]);
	}
	modifiedPointsCounter--;
}

int ModifiableFunction::findPointIndex(unsigned point) const
{
	for (int i = 0; i < modifiedPointsCounter; i++)
	{
		if (modifiedPoints[i].point == point)
		{
			return i;
		}
	}
	return -1;
}

void ModifiableFunction::removeAllModifications()
{
	modifiedPointsCounter = 0;
}