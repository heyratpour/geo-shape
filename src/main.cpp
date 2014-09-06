/* 
 * File:   main.cpp
 * Author: Pouyan Heyratpour
 * Email: P.Heyratpour@Gmail.Com
 *
 * Created on January 28, 2013, 4:14 AM
 */
#include <shape.h>

int main()
{
	square sq(16);
	rectangle rc(10, 12);
	rhombus rh(5, 10);
	parallelogram pr(8, 14, PI/6);
	
	double trpLegs[2] = {8, 8};
	double trpLegsAngles[2] = {PI/3, PI/3};
	trapezoid trp(14, trpLegs, trpLegsAngles);
	
	equilateral eq(7);
	isosceles iso(17, PI/4);
	
	double trSides[3] = {5, 3, 4};
	double trAngles[3] = {0.6435011088, 0.927295218, PI/2};
	triangle tr(trSides, trAngles);
	
	circle cr(4);
	ellipse ell(4, 8);
	
	return 0;
}
