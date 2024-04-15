/**
 * @file stddev.cpp
 * 
 * @brief Source code for calculating standard deviation from given numbers
 *
 * This file calculates a standard deviation from numbers given through stdin.
 * It is made for profiling purposes and uses math_operations.h library.
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
#include <iomanip>


MathOps m;

/**
* @brief 		Calculates mean of given numbers
* 
* @param vector Vector of doubles to calculate mean from
* @param count	Count of the numbers
* @param flag	Flag if an error occurs
* @return		Mean of the numbers or error code
*/
double calcMean(std::vector<double> vector, double count, MathErrorCode *flag){

	double sum = 0.0;

	for(double num : vector)
	{
		sum = m.add(sum, num);
	}
	
	MathErrorCode ERR = SUCCESS;
	
	double mean = m.divide(sum, count, ERR);
	
	if(ERR != SUCCESS){
		*flag = ERR;
		return ERR;
	}
	else{
		return mean;
	}
}

/** 
 * @brief Calculates the standard deviation from the numbers
 * 
 * @param vector Vector of doubles to calculate standard deviation from
 * @param count  Count of the numbers
 * @param flag	 Flag if an error occurs
 * @return		 Standard deviation from the numbers or error code
 * 
*/
double calcStddev(std::vector<double> vector, double count, MathErrorCode *flag){
	MathErrorCode ERR = SUCCESS;

	double mean = calcMean(vector, count, &ERR);
	if(ERR != SUCCESS){
		*flag = ERR;
		return ERR;
	}

	double sum = 0.0;
	double meanSqN = 0.0;
	double tempNum = 0.0; 

	meanSqN = m.nthPower(mean, 2); // mean^2
	meanSqN = m.multiply(count, meanSqN); // (mean^2)*count

	for(double num : vector){
		tempNum = m.nthPower(num, 2);
		sum = m.add(sum, tempNum); 
	} // calculates sum of numbers^2

	sum = m.subtract(sum, meanSqN);
	sum = m.divide(sum, count-1, ERR);
	if(ERR != SUCCESS){
		*flag = ERR;
		return ERR;
	}
	sum = m.squareRoot(sum, ERR);
	if(ERR != SUCCESS){
		*flag = ERR;
		return ERR;
	}
	return sum;
}

int main() {
	std::vector<double> numbers;

	double num = 0;
	double count = 0;
	MathErrorCode eFlag = SUCCESS;

	while(std::cin >> num){
		numbers.push_back(num); 
		count++;
	} // adds each number to vector

	double stddev = calcStddev(numbers, count, &eFlag);

	if(eFlag != SUCCESS){
		std::cerr << "ERROR NUMBER: " << eFlag << std::endl << "CHECK THE VALIDITY OF YOUR INPUT" << std::endl;
		return eFlag;
	}
	else{
		std::cout << std::setprecision(8) << stddev <<std::endl;
	}
	return 0;
}
/*** End of file stddev.cpp ***/

