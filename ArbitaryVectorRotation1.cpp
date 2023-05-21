/**
 * @file ArbitaryVectorRotation1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief A simple game: vector rotation controled by keyboard
 * @version 0.1
 * @date 2022-05-21
 * @since SundDay; 06:13 PM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;


void roateOnceLeft(vector <int> &v, const size_t &vSize);
const void display(const vector <int> &v, const size_t &vSize, const char *const lebel);
void rotateOnceRight(vector <int> &v, const size_t &vSize);
void rotateVectorElement(vector <int> &v, const size_t &vSize, const ssize_t &n);

const void display(const vector <int> &v, const size_t &vSize, const char *const lebel){
	cout<<lebel<<endl;

	for(size_t i{0}; i < vSize; i++){
		cout<<i<<" ";
	}
	cout<<endl;
	for(const int &x: v){
		cout<<x<<" ";
	}
	cout<<endl;
}

void rotateOnceRight(vector <int> &v, const size_t &vSize){
	
	const int lastIndexElement {v.at(vSize-1)};
	
	for(ssize_t i{static_cast<ssize_t>(vSize) - 2}; i >= 0; i--){
		v.at(i+1) = v.at(i);
	}
	v.at(0) = lastIndexElement;
}



void roateOnceLeft(vector <int> &v, const size_t &vSize){
	int firstIndexElement{v.at(0)};
	for(size_t i{0}; i < vSize - 1; i++){
		v.at(i) = v.at(i+1);
	}
	v.at(vSize - 1) = firstIndexElement;
}

int main(int argc, char const *argv[]){
    /* code */
    system("cls");
   
	vector <int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t vSize{numbers.size()};
	
	display(numbers, vSize, "Before Rotate Vector");
	
	char controller{'\0'};
	
	do{
		cout<<"===========================MENU==========================="<<endl;
		cout<<"L for Left Rotation()"<<endl;
		cout<<"R for Right Rotation()"<<endl;
		cout<<"Number for Times()"<<endl;
		cout<<"Q for QUIT()"<<endl;
		cout<<"=========================================================="<<endl;
		cin>>controller;
		controller = toupper(controller);
		
		
		if(controller == 'L'){
			rotateVectorElement(numbers, vSize, -1);
		}
		else if(controller == 'R'){
			rotateVectorElement(numbers, vSize, 1);
		}
		else if(isdigit(controller)){
			ssize_t n{controller - '0'};
			rotateVectorElement(numbers, vSize, n);
		}
		else if(controller == 'Q'){
			cout<<"EXIT()"<<endl;
			exit(0);
		}
		else{
			cout<<"Your have selected WRONG key...!"<<endl;
		}
		
	}while(controller != 'Q');
	
   
	system("pause>0");
    return 0;
}

void rotateVectorElement(vector <int> &v, const size_t &vSize, const ssize_t &n){
	ssize_t position {n};
	if(n > 0){ /*Positive -> RIGHT_ROTATE*/
		if(position >= static_cast<ssize_t>(vSize)){
			position %= static_cast<ssize_t>(vSize);
		}
		for(ssize_t i{0}; i < position; i++){
			rotateOnceRight(v, vSize);
		}
		display(v, vSize, "After Right Rotate");
	}
	else if(n < 0){ /*Negative <- LEFT_ROATE*/
		position = abs(position);
		if(position >= static_cast<ssize_t>(vSize)){
			position %= static_cast<ssize_t>(vSize);
		}
		for(ssize_t i{0}; i < position; i++){
			roateOnceLeft(v, vSize);
		}
		display(v, vSize, "After Left Rotate");
	}
	else{
		display(v, vSize, "After NO Rotate");
	}
}