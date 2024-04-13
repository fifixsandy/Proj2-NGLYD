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
* @brief 		Calculates mean of given numbers
* 
* @param vector Vector of floats to calculate mean from
* @param count	Count of the numbers
* @param flag	Flag if an error occurs
* @return		Mean of the numbers or error code
*/
float calcMean(std::vector<double> vector, double count, MathErrorCode *flag){

	float sum = 0.0;

	for(float num : vector)
	{
		sum = m.add(sum, num);
	}
	
	MathErrorCode ERR = SUCCESS;
	
	float mean = m.divide(sum, count, ERR);
	
	if(ERR != SUCCESS){
		*flag = ERR;
		return ERR;
	}
	else{
		return mean;
	}
}

float calcStdev(std::vector<double> vector, double count, MathErrorCode *flag){
	MathErrorCode ERR;

	float mean = calcMean(vector, count, flag);

	float sum = 0.0;
	float meanSqN = 0.0;
	float tempNum = 0.0; 

	meanSqN = m.nthPower(mean, 2); // mean^2
	meanSqN = m.multiply(count, meanSqN); // (mean^2)*count

	for(float num : vector){
		tempNum = m.nthPower(num, 2);
		sum = m.add(sum, tempNum);
	}

	sum = m.subtract(sum, meanSqN);
	sum = m.divide(sum, count-1, ERR);
	sum = m.squareRoot(sum, ERR);

	return sum;
}
int main() {
	std::vector<double> numbers;

	double num;
	double count;
	MathErrorCode eFlag;

	while(std::cin >> num){
		numbers.push_back(num);
		count++;
	}

	float mean = calcMean(numbers, count, &eFlag);

	float stdev = calcStdev(numbers, count, &eFlag);

	if(eFlag != SUCCESS){
		
		return eFlag;
	}
	else{
		std::cout << stdev <<std::endl;
	}
	return 0;
}

