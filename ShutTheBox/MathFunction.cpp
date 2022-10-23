#include "MathFunction.h"

int MathFunction::sumOfAllElements(DynamicArray* d)
{
	int sum = 0;
	for (int i = 0; i < d->getSize(); ++i) sum += d->getElement(i);
	return sum;
}

DynamicArray** MathFunction::findAllCombinations(DynamicArray* d)
{
	DynamicArray** result = new DynamicArray * [d->getMaxcap()]; // initialise result vector of vectors
	if (d->getSize() == 0) return NULL; // if array is empty then return NULL
	else if (d->getSize() == 1) // if array is just one element then return the original array back
	{
		result[0] = d;
		return result;
	}
	else
	{
		std::cout << "To resume later" << std::endl;
		return NULL;
	}
}