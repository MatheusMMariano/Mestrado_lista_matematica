#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<double> sistemaLinear(vector<vector<double>> &matriz){
	vector<double> sistema;
	
	for(int i = matriz.size()-1; i >= 0; i--){
		double soma = 0.0;
		
		for(int j = matriz.size()-1; j > i; j--){
			soma = soma + ((matriz[i][j]) * (sistema[(matriz.size()-1)-j]));
		}

		sistema.push_back((matriz[i][matriz[i].size()-1] - soma) / matriz[i][i]);
	}
	
	cout << ">";
	for(int i = 0; i < sistema.size(); i++) cout << " " << sistema[i];
	cout << "\n";
	return sistema;
}

void show(vector<vector<double>> &matriz){
	cout << "\n";
	for(int l = 0; l < matriz.size(); l++){
		cout << "[";
		for(int c = 0; c < matriz.size()+1; c++) cout << " " << matriz[l][c];
		cout << "]" << endl;
	}
}

void zera(vector<vector<double>> &matriz, int l, int c){
	double pivo = (matriz[l][c] / matriz[c][c]);
	
	for(int i = c; i < matriz.size()+1; i++){
		matriz[l][i] = matriz[l][i] - ((pivo) * matriz[c][i]);
	}
}

double MEG(vector<vector<double>> &matriz){
	for(int l = 0; l < matriz.size(); l++){
		for(int c = 0; c < matriz.size(); c++){
			if(c < l){
				if(matriz[l][c] != 0) zera(matriz, l, c);
			} 
			else break;
		}
	}
}

double det(vector<vector<double>> matriz){
	return ((matriz[1][1] * matriz[2][2]) - (matriz[1][2] * matriz[2][1])) -
		   ((matriz[1][0] * matriz[2][2]) - (matriz[1][2] * matriz[2][0])) +
		   ((matriz[1][0] * matriz[2][1]) - (matriz[1][1] * matriz[2][0]));
}

vector<double> subMatriz(vector<double> SA, vector<double> SB){
	vector<double> SC;
	for(int i = SA.size()-1; i >= 0; i--) SC.push_back(SA[i]-SB[i]);
	return SC;
}

void tridiagonal(vector<vector<double>> &A, int t){
	for(int i = 0; i < t; i++){
		vector<double> l;
		
		for(int j = 0; j < t; j++){
			if(j == i) l.push_back(2);
			else if(j == (i+1) || j == (i-1)) l.push_back(-1.0);
			else l.push_back(0.0);
		}
		if(i == 0 || i == 9) l.push_back(1.0);
		else l.push_back(0.0);
		A.push_back(l);
	}
}

int main(int argc, char** argv) {
	//1
	cout << "\nExercicio 1)" << endl;
	vector<vector<double>> matriz = {{4, -1,  1,  8},
									 {2,  5,  3,  3},
									 {1,  2,  4, 11}};
	MEG(matriz);
	show(matriz);
	sistemaLinear(matriz);

	//2a)
	cout << "\nExercicio 2 a)" << endl;
	vector<vector<double>> SA = {{0.50,    0.25, 	  0.00, 	0.00,  0.35},
								 {0.35,    0.80, 	  0.40, 	0.00,  0.77},
								 {0.00,    0.25, 	  1.00, 	0.50, -0.50},
								 {0.00, 0.249999,  1.00001, 0.499999, -2.25}};
	MEG(SA);
	show(SA);
	sistemaLinear(SA);

	//2b)
	cout << "\nExercicio 2 b)" << endl;
	vector<vector<double>> SB = {{0.50, 0.25	, 0.00	 , 0.00	   ,  0.356},
								 {0.35, 0.80	, 0.40	 , 0.00	   ,  0.774},
								 {0.00, 0.25	, 1.00	 , 0.50	   , -0.501},
								 {0.00, 0.249999, 1.00001, 0.499999, -2.249}};
	
	vector<double> SC = subMatriz(sistemaLinear(SA), sistemaLinear(SB));
	
	cout << "\n[" << SC[SC.size()-1];
	for(int i = SC.size()-2; i >= 0; i--){
		cout << ", " << SC[i];
	}
	cout << "]";
	
	//3)
	cout << "\nExercicio 3)";
	vector<vector<double>> A;
	tridiagonal(A, 10);
	MEG(A);
	show(A);
	sistemaLinear(A);
}
