#pragma once
#include "DynamicArray.h"

class MathFunction
{
public:
	int sumOfAllElements(DynamicArray* d); // calculates the sum of all elements in the array
	DynamicArray** findAllCombinations(DynamicArray* d); // finds all different combinations of the elements in the array and returns it	                                                     
};