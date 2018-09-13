#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

//Euler
double fx(double t, double y){
	return (-100*y)+(100*t)+1;
}

//Runge-Kutta 4
double K1(double h, double x, double y){
	return (h*fx(x, y));
}

double K2(double h, double x, double y){
	return (h*fx(x+(h/2), y+(K1(h, x, y)/2)));
}

double K3(double h, double x, double y){
	return (h*fx(x+(h/2), y+(K2(h, x, y)/2)));
}

double K4(double h, double x, double y){
	return (h*fx(x+h, y+K3(h, x, y)));
}

int main(){
	vector<double> HE = {0.025, 0.016666}, HR = {0.025, 0.033333};
	double yE = 1.0, yR = 1.0, x = 0.0;
	
	for(int i = 0; i < 2; i++){
		yE = yE + HE[i] * fx(x, yE);
		yR = yR + (1/6)*(   K1(HR[i], x, yR) +
						 (2*K2(HR[i], x, yR))+
						 (2*K3(HR[i], x, yR))+
						    K4(HR[i], x, yR));
	}
	cout << "Euler: " << yE << endl;
	cout << " RK-4: " << yR << endl;
	return 0;
}
