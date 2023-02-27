/**
 * @file: OverrideWithOverrideKeyWord.cpp
 * @author: Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief: Function overriding with override key-word using dynamic binding
 * @version: 0.1
 * @date: 2023-02-26
 * @since: SunDay; 11:45 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;

class Account{
public:
	Account() = default;
	virtual void withdraw(const double &amount) const{
		if(amount > 0){
			cout<<"In Account:: Withdraw() done."<<endl;
		}
		else{
			cout<<"In Account:: Withdraw() failed!"<<endl;
		}
	}
	virtual ~Account() = default;
};

class Savings : public Account{
	public:
	Savings() = default;
	virtual void withdraw(const double &amount) const override{
		if(amount > 0){
			cout<<"In Savings:: Withdraw() done."<<endl;
		}
		else{
			cout<<"In Savings:: Withdraw() failed!"<<endl;
		}
	}
	virtual ~Savings() = default;
};

class Checking : public Account{
	public:
	Checking() = default;
	virtual void withdraw(const double &amount) const override{
		if(amount > 0){
			cout<<"In Checking:: Withdraw() done."<<endl;
		}
		else{
			cout<<"In Checking:: Withdraw() failed!"<<endl;
		}
	}
	virtual ~Checking() = default;
};

class Trust : public Account{
	public:
	Trust() = default;
	virtual void withdraw(const double &amount) const override {
		if(amount > 0){
			cout<<"In Trust:: Withdraw() done."<<endl;
		}
		else{
			cout<<"In Trust:: Withdraw() failed!"<<endl;
		}
	}
	virtual ~Trust() = default;
};


int main(int argc, const char **const argv){
	system("cls");
	Account *pObjects[]{new Account{}, new Savings{}, new Checking{}, new Trust{}};
	for(const auto &object: pObjects){
		object->withdraw(500);
	}
	cout<<"\n*****CleanUp*****"<<endl;
	for(auto &object: pObjects){
		delete object;
		object = nullptr;
	}
	printf("\nHappyEnding %c%c\n", 2,2);
	return 0;
}