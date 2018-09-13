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

//----------------------------------------------------------------

void polinomio(vector<double> &A, vector<double> &B){
	vector<double> p;
	int t = A.size();
	
	for(int a = 0; a < t; a++){
		for(int b = 0; b < 2; b++){
			if(a <= b) p.push_back(A[a]*B[b]);
			else{
				if(b == 1) p.push_back(A[a]*B[b]);
				else p[p.size()-1] = p[p.size()-1] + (A[a]*B[b]);
			}
		}
	}
	A = p;
}

vector<double> L(vector<double> Xn, int t){
	vector<double> A;
	
	if(t == 0) A = {1.0, -(Xn[1])};
	else A = {1.0, -(Xn[0])};
	
	for(int i = 1; i < Xn.size(); i++){
		if(t == 0 && i == 1) i = i+1;
		if(i != t){
			vector<double> B = {1.0, -Xn[i]};
			polinomio(A, B);
		}
	}
	return A;
}

double div(vector<double> Xn, int i){
	double divi = 1.0;
	for(int t = 0; t < Xn.size(); t++){
		if(t != i) divi = divi * (Xn[i] - Xn[t]);
	}
	return divi;
}

void show(vector<double> p){
	cout << "\nLn" << ": [" << p[0];
	for(int i = 1; i < p.size(); i++){
		cout << ", " << p[i];
	}
	cout << "]";
}

vector<double> sumVector(vector<vector<double>> Ln){
	vector<double> p;
	double v = 0.0;
	
	for(int i = 0; i < Ln.size(); i++){
		for(int t = 0; t < Ln.size(); t++) v = v + Ln[t][i];
		p.push_back(v);
		v = 0.0;
	}
	return p;
}

vector<double> lagrange(vector<double> Xn, vector<double> Fx){
	vector<vector<double>> Ln; //Ln = [(y0*L0),(y1*L1),(y2*L2),...,(yn-1*Ln-1)]
	
	for(int i = 0; i < Xn.size(); i++){ //(y0*L0)
		vector<double> mult = L(Xn, i); //(L0) = (x -x1)(x -x2)(x -x3) = [1, -6, 6] -> x^2-6x+6
		double divi = div(Xn, i);		//(x0-x1)(x0-x2)(x0-x3) =  2		 ->    2
		for(int t = 0; t < mult.size(); t++) mult[t] = Fx[i]*(mult[t]/divi); // [1*(1/2), 1*(-6/2), 1*(6/2)]		
		Ln.push_back(mult); //[0.5, -3, 3]
	}
	return sumVector(Ln);
}

int main(int argc, char** argv) {
	vector<double> Xn  = {0.0 , 6.0  , 10.0 , 13.0 , 17.0 , 20.0 , 28.0 };
	vector<double> Fx1 = {6.67, 17.33, 42.67, 37.33, 30.10, 29.31, 28.74};
	vector<double> Fx2 = {6.67, 16.11, 18.89, 15.00, 10.56,  9.44,  8.89};
	double x1 = 2.0;
	double x2 = 2.0;
	
	//3-a)
	vector<double> p1 = lagrange(Xn, Fx1);
	vector<double> p2 = lagrange(Xn, Fx2);
	show(p1);
	show(p2);
	
	//3-b
	cout << "\nResultado Amostra 1: " << lagrange(Xn, Fx1, x1) << endl;
	cout << "Resultado Amostra 2: "   << lagrange(Xn, Fx2, x2) << endl;

	return 0;
}
