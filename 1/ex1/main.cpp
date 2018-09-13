#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//EX2
vector<double> lagL1(vector<double> L, vector<double> y, int i){
	L[0] = (L[0]/L[2])*y[i];
	L[1] = (L[1]/L[2])*y[i];
	return L;
}

vector<double> Lx1(vector<double> fx, int i){
	if (i == 0) return { 1.0, -(fx[1]), (fx[0] - fx[1]) };
	else 		return { 1.0, -(fx[0]), (fx[1] - fx[0]) };
}

vector<double> lagrangeN1(vector<double> fx, vector<double> y){
	vector<double> L0, L1;
	L0 = lagL1(Lx1(fx, 0), y, 0);
	L1 = lagL1(Lx1(fx, 1), y, 1);
	
	return {L0[0]+L1[0], L0[1]+L1[1]};
}

//EX1
vector<double> lagL2(vector<double> L, vector<double> y, int i){
	L[0] = (L[0]/L[3])*y[i];
	L[1] = (L[1]/L[3])*y[i];
	L[2] = (L[2]/L[3])*y[i];
	return L;
}

vector<double> Lx2(vector<double> fx, int i){
	if		(i == 0) return { 1.0, -(fx[1] + fx[2]), (fx[1] * fx[2]), (fx[i] - fx[1]) * (fx[i] - fx[2]) };
	else if	(i == 1) return { 1.0, -(fx[0] + fx[2]), (fx[0] * fx[2]), (fx[i] - fx[0]) * (fx[i] - fx[2]) };
	else 			 return { 1.0, -(fx[0] + fx[1]), (fx[0] * fx[1]), (fx[i] - fx[0]) * (fx[i] - fx[1]) };
}

vector<double> lagrangeN2(vector<double> fx, vector<double> y){
	vector<double> L0, L1, L2;
	L0 = lagL2(Lx2(fx, 0), y, 0);
	L1 = lagL2(Lx2(fx, 1), y, 1);
	L2 = lagL2(Lx2(fx, 2), y, 2);
	
	return {L0[0]+L1[0]+L2[0], L0[1]+L1[1]+L2[1], L0[2]+L1[2]+L2[2]};
}


int main(int argc, char** argv) {
	//EX1
	vector<double> polinomio1 = lagrangeN2({0.0, 0.6, 0.9}, {cos(0.0), cos(0.6), cos(0.9)});
	
	cout << "\nExercicio 1" << endl;
	cout << "Polinomio: " << polinomio1[0] << "x^2 " << polinomio1[1] << "x + " << polinomio1[2] << endl;
	cout << "Resultado: " << (polinomio1[0] * (0.45 * 0.45)) + (polinomio1[1] * 0.45) + (polinomio1[2]) << endl;
	
	//EX2-a)
	vector<double> polinomio2 = lagrangeN1({0.0, 0.5}, {exp(0.0), exp(0.5)});
	
	cout << "\nExercicio 2-a)" << endl;
	cout << "Polinomio: " << polinomio2[0] << "x + " << polinomio2[1] << endl;
	cout << "Resultado: " << (polinomio2[0] * 0.25) + (polinomio2[1]) << endl;
	
	//EX2-b)
	vector<double> polinomio3 = lagrangeN1({0.5, 1.0}, {exp(0.5), exp(1.0)});

	cout << "\nExercicio 2-b)" << endl;
	cout << "Polinomio: " << polinomio3[0] << "x + " << polinomio3[1] << endl;
	cout << "Resultado: " << (polinomio3[0] * 0.75) + (polinomio3[1]) << endl;
	
	//EX2-c)
	vector<double> polinomio4_1 = lagrangeN2({0.0, 1.0, 2.0}, {exp(0.0), exp(1.0), exp(2.0)});
	
	cout << "\nExercicio 2-c)" << endl;
	cout << "Polinomio: " << polinomio4_1[0] << "x^2 " << polinomio4_1[1] << "x + " << polinomio4_1[2] << endl;
	cout << "Resultado: \n\t - 0.25: " << (polinomio4_1[0] * (0.25 * 0.25)) + (polinomio4_1[1] * 0.25) + (polinomio4_1[2]) << endl;
	cout << "\t - 0.75: " << (polinomio4_1[0] * (0.75 * 0.75)) + (polinomio4_1[1] * 0.75) + (polinomio4_1[2]) << endl;

	return 0;
}
