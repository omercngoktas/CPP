#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.h"
#include <cmath>

class Radix1{
	private:	
		int* numbers;
		int length;
		Queue<int> **queues;
		int maxStep;
		
		int MaxStepNumber();
		int power(int);
		int StepCount(int);
		int* QueueCurrentLengths();
	public:
		Radix1(int*, int);
		int* Sort();
		~Radix1();
};

#endif