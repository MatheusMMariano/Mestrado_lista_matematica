#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double erroTrapezio(double a, double b){
	double f = 705.36;
	//double h = 0.00092229575;
	
	double h = sqrt(0.0001/(((b-a)*f/)/12));
}

int main(int argc, char** argv) {
	cout << "\nTRAPEZIO: " << erroTrapezio(0, 2) << endl;
	cout << "\n   MEDIO: " <<    medio(2, 5) << endl;
	
	return 0;
}
