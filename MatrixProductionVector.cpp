/**
 * @file: MatrixProductionVector.cpp
 * @author: Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief: Product of tow matrixs using vector and 2D array
 * @version: 0.1
 * @date: 2023-02-27
 * @since: MonDay; 11:52 PM
 * @copyright: Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
using namespace std;

class MatrixProduction{
private:
	int rowsA{};
	int columnsA{};
	vector <vector <int>> matrixA{};
	int rowsB{};
	int columnsB{};
	vector <vector <int>> matrixB{};
	
public:
	MatrixProduction() = default;
	
	MatrixProduction *loadElements(vector<vector<int>> &matrix, const int &rows, const int &columns){
		int element{};
		vector <int> temp{};
		for(int i{0}; i < rows; i++){
			for(int j{0}; j < columns; j++){
				cout<<"["<<i<<", "<<j<<"] = ";
				cin>>element;
				temp.push_back(element);
			}
			matrix.push_back(temp);
			temp.clear();
		}
		return this;
	}
	void showMatrix(const vector<vector<int>> &matrix) const {
		for(const auto &x: matrix){
			for(const auto &y: x){
				cout<<y<<"\t";
			}
			cout<<endl;
		}
	}
	MatrixProduction *inputRowColumnA(void){
		cout<<"Enter row for A: ";
		cin>>rowsA;
		rowsA = abs(rowsA);
		cout<<"Enter column for A: ";
		cin>>columnsA;
		rowsB = abs(columnsA);
		if(rowsA == 0 || columnsA == 0){
			exit(0);
		}
		loadElements(matrixA ,rowsA, columnsA);
		cout<<"Matrix A Below:"<<rowsA<<"x"<<columnsA<<endl;
		showMatrix(matrixA);
		return this;
	}
	
	void *inputRowColumnB(void){
		cout<<"Enter row for B: ";
		cin>>rowsB;
		rowsB = abs(rowsB);
		cout<<"Enter column for B: ";
		cin>>columnsB;
		columnsB = abs(columnsB);
		if(rowsB == 0 || columnsB == 0){
			exit(0);
		}
		
		return this;
	}
	
	void matrixMuliplication(void){
		if(columnsA == rowsB){
			loadElements(matrixB ,rowsB, columnsB);
			cout<<"Matrix B Below:"<<rowsB<<"x"<<columnsB<<endl;
			showMatrix(matrixB);
			
			int productAB[rowsA][columnsB];
			for(int i{0}; i<rowsA; i++){
				for(int j{0}; j<columnsB; j++){
					productAB[i][j] = 0;
					for(int k{0}; k < columnsA; k++){ /*columnsA or rowsB*/
						productAB[i][j] += matrixA.at(i).at(k) * matrixB.at(k).at(j);
					}
				}
			}
			
			cout<<"Matix production below:"<<rowsA<<"x"<<columnsB<<endl;
			for(int i {0}; i < rowsA; i++){
				for(int j {0}; j < columnsB; j++){
					cout<<productAB[i][j]<<"\t";
				}
				cout<<endl;
			}
			
		} 
		else{
			cout<<"\tMatrix multiplication not posible...!"<<endl;
		}
	}
	~MatrixProduction() = default;
	
};

int main(int argc, const char *const argv[]){
	system("cls");
	MatrixProduction matrixProduction1{};
	matrixProduction1.inputRowColumnA();
	
	matrixProduction1.inputRowColumnB();
	
	matrixProduction1.matrixMuliplication();
	cout<<"HappyEnding...";
	for(int i{0}; i < 10; i++){
		printf("%c", 2);
	}
	cout<<endl;
	system("pause>0");
	return 0;
}