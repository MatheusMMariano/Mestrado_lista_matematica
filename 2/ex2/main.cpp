#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

double fx(double x){
	return (10/((-(x))*sqrt(x)));
}

int main(){
	double a = 10.0, b = 5.0, T = 0.0, PM = 0.0, h = 0.01;
	for(double i = 10; i > 5; i = i - h){
		T = T + ((((i-h)-i)/2)*(fx(i)+fx(i-h)));
		PM = PM + (((i-h)-i) * (fx((i+(i-h))/2)));
	}
	cout << "> Trapezio: " << T << endl;
	cout << "> Ponto Me: " << PM << endl;
	return 0;
}
