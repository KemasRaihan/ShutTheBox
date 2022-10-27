#pragma once
#include <iostream>

class Dice
{

	static const int min = 1;
	static const int max = 6;

public: 
	static inline int roll();
};

inline int Dice::roll(){ return min + (rand() % max); }