/**
 * @file profiling.cpp
 * 
 * @brief Source code for calculating standard deviation
 *
 * This file calculates a standard deviation from numbers given through stdin.
 * It is made for profiling purposes and uses math_operations.h library.
 * It takes at most XXX numbers of XXX size.
 * 
 * @author xfignam00
 * @author xmalegt00
 * @author xnovakf00
 * @author xskovaj00
 */

#include "../LIBS/math_operations.h"
#include <iostream>
#include <string>
#include <vector>

MathOps m;

/**
* @brief Calculates mean of given numbers
* 
* @param vector Vector of floats to calculate mean from
* @param count	Count of the numbers
* @return		Mean of the numbers
*/
float mean(std::vector<double> vector, double count){

	float sum = 0.0; // sum of all the numbers

	for(float num : vector)
	{
		sum = m.add(sum, num);
	}
	
	MathErrorCode ERR = SUCCESS;
	
	float mean = m.divide(sum, count, ERR);
	
	if(ERR != SUCCESS){
		return ERR;
	}
	else{
		return mean;
	}
}

int main() {
	std::vector<double> numbers;

	double num;
	double count;

	while(std::cin >> num){
		numbers.push_back(num);
		count++;
	}

	float meanN = mean(numbers, count);

	std::cout << meanN <<std::endl;

	return 0;
}

