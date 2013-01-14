/* program to implement the Newton-Raphson Algorithm */
/* Author:
 * Pranav Gupta
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

float newton_raphson(float(*func)(float), float a, float b, float epsilon);
float function(float x);
float first_der(float(*func)(float), float x);
float second_der(float(*func)(float), float x);

int main(){
	float optPoint = newton_raphson(function, 0, 10, 0.05);
	printf("Optimum Point : %f\n\n", optPoint);
	return 0;
}

float newton_raphson(float(*func)(float), float a, float b, float epsilon){
	float x = b;
	float f1x = first_der(func, x);
	float f2x;

	int itr_no = 1;
	while(abs(f1x) > epsilon){
		printf("Iteration Number %3d ------ x : %6f\tf1x : %6f\n", itr_no, x, f1x);
		f2x = second_der(func, x);
		x -= f1x/f2x;
		f1x = first_der(func, x);
		itr_no++;
	}
	
	return x;
}

float function(float x){
	return x*x*x - 2*x + 1;
}

float first_der(float(*func)(float), float x){
	float delta = x < 0.01 ? 0.01 : 0.01 * x;
	return (func(x + delta) - func(x - delta))/ (2 * delta);	
}

float second_der(float(*func)(float), float x){
	float delta = x < 0.01 ? 0.01 : 0.01 * x;
	return (first_der(func, x + delta) - first_der(func, x - delta))/ (2 * delta);	
}
