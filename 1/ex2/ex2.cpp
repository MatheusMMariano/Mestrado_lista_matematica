#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double L(vector<double> xn, int i, double x){
	double lagranja = 1.0;
	
	for(int t = 0; t < xn.size(); t++){
		if(t != i) lagranja = lagranja * ((x - xn[t]) / (xn[i] - xn[t]));
	}
	return lagranja;
}

double lagrange(vector<double> xn, vector<double> fx, double x){
	double Ln = 0.0;
	
	for(int i = 0; i < xn.size(); i++) Ln = Ln + (fx[i]*L(xn, i, x));
	return Ln;
}

vector<double> L(vector<double> xn, int t){
	vector<double> A;
	vector<double> B;
	vector<double> polinomio;
	double div = 1.0;
	
	for(int i = 0; i < xn.size(); i++){
		if(t != i){
			if(i == 0) A.push_back({1, -(xn[i])});
			else{
				B.push_back({1, -(xn[i])});
				for(int a = 0; r < A.size(); a++){
					for(int b = 0; b < B.size(); b++){
						if(a == b || a < b) polinomio.push_back(A[a]*B[b]);
						else if(b == B.size()-1) polinomio.push_back(A[a]*B[b]);
					}
				}
				A = polinomio;
				polinomio.clear();
				B.clear();
			}
			div = div * (x[t]-x[i]);
		}
	}
	return A;
}

vector<vector<double>> lagrange(vector<double> xn, vector<double> fx){
	vector<vector<double>> Ln;
	
	for(int i = 0; i < xn.size(); i++){
		Ln.push_back(L(xn, i));
		for(int t = 0; t < Ln[i].size(); t++) Ln[i][t] = Ln[i][t] * fx[i];
	}
	return Ln;
}

int main(int argc, char** argv) {
	vector<double> xn  = {0.0 , 6.0  , 10.0 , 13.0 , 17.0 , 20.0 , 28.0 };
	vector<double> fx1 = {6.67, 17.33, 42.67, 37.33, 30.10, 29.31, 28.74};
	vector<double> fx2 = {6.67, 16.11, 18.89, 15.00, 10.56,  9.44,  8.89};
	double x1 = 2.0;
	double x2 = 2.0;
	
	//3-a)
	
	
	//3-b
	cout << "\nResultado Amostra 1: " << lagrange(xn, fx1, x1) << endl;
	cout << "Resultado Amostra 2: "   << lagrange(xn, fx2, x2) << endl;

	return 0;
}
