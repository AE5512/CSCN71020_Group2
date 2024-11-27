#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"


char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

void anglePrint(int* input) { //reusable print function
	double angleA = findingAngle(input[0], input[1], input[2]);
	double angleB = findingAngle(input[1], input[2], input[0]);
	// this fixes an edge case that would result in the angle sum being 179
	// this is meant to make the triangle true even if we lie a little
	double angleC = 180 - round(angleA) - round(angleB);
	printf("Sngle a: %.0lf\nAngle b: %.0lf\nAngle c: %.0lf\n", angleA, angleB, angleC);

}

double findingAngle(int a, int b, int c) {
	double PI = 3.1415926; // a constant for 
	// arccos[(b^2 + c^2 - a^2) / 2bc]
	double topHalf = (b*b) + (c*c) - (a*a);
	double bottomHalf = 2*b*c;
	double result = topHalf / bottomHalf;
	// Converting radains into degrees
	double degree = acos(result) * 180 / PI;
	return degree;
}