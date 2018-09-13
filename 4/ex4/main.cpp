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
	vector<float> HE = {0.025, 0.016666}, HR = {0.025, 0.033333};
	vector<float> RE, RRK;
	float yR = 1.0, yE = 1.0;
	
	//EULER
	int t = 0;
	for(int i = 0; i < 2; i++){
		for(float x = 0.0; x <= 1.0; x=x+HE[i]){
			yE = yE + HE[i] * fx(x, yE); //0.025 diverge / 0.016666 converge
			
		t++;
		}
		
		cout << "\n -> " << t << "\n";
		RE.push_back(yE);
		yE = 1.0;
	}
	
	//Euler: 0.025
	//Ele tem um acréscimo e descréscimo de valores descontrolados
	
	//RUNGE KUTTA 4
	for(int i = 0; i < 2; i++){
		for(float x = 0.0; x <= 1.0; x=x+HR[i]){
			yR = yR + (1.0/6.0)*(    K1(HR[i], x, yR) +
						 		(2 * K2(HR[i], x, yR))+
						 		(2 * K3(HR[i], x, yR))+
									 K4(HR[i], x, yR)); //0.025 converge / 0.033333 diverge
		}
		RRK.push_back(yR);
		yR = 1.0;
	}
	
	//RK4: 0.03333
	//No gráfico ele oscila o y através do h de forma descontrolada,
	//
	
	cout << "Euler - " << HE[0] << ": " << RE[0] << " / " << HE[1] << ": " << RE[1] << endl;
	cout << "RK-4  - " << HR[0] << ": " <<RRK[0] << " / " << HR[1] << ": " << RRK[1] << endl;
	return 0;
}
