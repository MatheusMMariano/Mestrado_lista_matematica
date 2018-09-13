#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

double fx(double Tr, double r){
	return (Tr*r*0.7051);
}

double fx(double r){
	return (r*0.7051);
}

int main(){
	vector<double> Tr = {640, 794, 885, 943, 1034, 1064, 1114, 1152, 1204, 1222, 1239};
	double T1 = 0.0, T2 = 0.0, PM1 = 0.0, PM2 = 0.0, h = 0.017;
	int i = 0;
	
	for(double a = 0.308; a <  0.478; a = a + h){
		T1 = T1 + ((((a + h) - a)/2) * (fx(Tr[i], a) + fx(Tr[i+1], a+h)));
		T2 = T2 + ((((a + h) - a)/2) * (fx(a) + fx(a+h)));
		
		PM1 = PM1 + (((a + h) - a) * (fx(Tr[i], (a + (a+h))/2)));
		PM2 = PM2 + (((a + h) - a) * (fx((a + (a+h))/2)));
		i++;
	}
	cout << "> Trapezio: " << (T1/T2) << endl;
	cout << "> Ponto Me: " << (PM1/PM2) << endl;
	return 0;
}
