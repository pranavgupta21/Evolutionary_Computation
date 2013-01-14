/* program to implement the Golden-Section Search Algorithm */
/* Author:
 * Pranav Gupta
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define GOLDEN_RATIO 0.618

pair<float, float> single_variable_gss(float(*func)(float), float a, float b, float epsilon);
float function(float x);
float x2w(float x, float a, float b);
float w2x(float w, float a, float b);



int main(){
	pair<float, float> optRegion = single_variable_gss(function, 0, 10, 0.01);
	printf("Optimum Region : (%f,%f)\n\n", optRegion.first, optRegion.second);
	return 0;
}

pair<float, float> single_variable_gss(float(*func)(float), float a, float b, float epsilon){
	float a_w, b_w, fa, fb, l_w, w1, w2, f1, f2;
	
	// initialize values for first iteration //
	a_w = 0;
	b_w = 1;
	l_w = 1;
	w1 = a_w + (GOLDEN_RATIO * l_w);
	w2 = b_w - (GOLDEN_RATIO * l_w);
	f1 = func(w2x(w1, a, b));
	f2 = func(w2x(w2, a, b));
	fa = func(w2x(a_w, a, b));
	fb = func(w2x(b_w, a, b));
	
	int itr_no = 0;
	while((b - a) * l_w > epsilon){
		if (fb > f1 && f2 > f1){
			// boundary point //
			a_w = w2;
			fa = f2;
			
			// length //
			l_w = b_w - a_w;
			
			// probe points //
			w2 = w1;
			f2 = f1;
			w1 = a_w + (GOLDEN_RATIO * l_w);
			f1 = func(w2x(w1, a, b));
		}
		else{
			// boundary point //
			b_w = w1;
			fb = f1;
			
			// length //
			l_w = b_w - a_w;
			
			// probe points //
			w1 = w2;
			f1 = f2;
			w2 = b_w - (GOLDEN_RATIO * l_w);
			f2 = func(w2x(w2, a, b));
		}
		itr_no++;
		printf("Iteration Number %3d ------ l_w = %6f\tl_x = %6f\n", itr_no, l_w, (b - a) * l_w);
	}
	
	pair<float, float> optRegion(w2x(a_w, a, b), w2x(b_w, a, b));
	return optRegion;
}

float function(float x){
	return x*x*x - 2*x + 1;
}

float x2w(float x, float a, float b){
	return (x - a)/(b - a);
}

float w2x(float w, float a, float b){
	return a + (b - a) * w;
}
