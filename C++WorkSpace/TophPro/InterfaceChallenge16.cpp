/**
 * @file: MatrixProductionVector.cpp
 * @author: Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief: Product of tow matrixs using vector and 2D array pointer notation
 * @version: 0.1
 * @date: 2023-02-28
 * @since: MonDay; 09:00 AM
 * @copyright: Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;

class Interface{
	friend ostream &operator<< (ostream &output, const Interface &object){
		object.print(output);
		return output;
	}
public:
	virtual void print(ostream &output) const = 0;
	virtual ~Interface() = default;
};

class Account : public Interface{
private:
	static constexpr const char *const defName{"Unnamed Account"};
	static constexpr double defBalance{0.0};
protected:
	string name{};
	double balance{0.0};
public:
	Account(const string_view &name = defName, const double &balance = defBalance):
		name{name}, balance{balance}{
			
		}
	virtual bool deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;
	virtual void print(ostream &output) const override{
		output<<"Account: ["<<name<<": "<<balance<<"]";
	}
	virtual ~Account() = default;
};

bool Account ::deposit(double amount){
	if(amount > 0){
		balance += amount;
		return true;
	}
	else{
		return false;
	}
}

bool Account:: withdraw(double amount){
	if(balance - amount >= 0){
		balance -= amount;
		return true;
	}
	else{
		return false;
	}
}

class CheckingAccount : public Account{
private:
	static constexpr const char *const defName {"Unnamed Checking Account"};
	static constexpr double defBalance {0.0};
	static constexpr double perCheckFee {1.50};
public:
	CheckingAccount(const string_view &name = defName, const double &balance = defBalance):
	Account{name, balance}{ /*Delegating constructor*/
		
	}
	virtual void print(ostream &output) const override{
		output<<"CheckingAccount: ["<<name<<": "<<balance<<"]";
	}
	virtual bool deposit(double amount) override{
		return Account::deposit(amount);
	}
	virtual bool withdraw(double amount) override{
		amount += perCheckFee;
		return Account::withdraw(amount);
	}
	virtual ~CheckingAccount() = default;
};

class SavingsAccount : public Account{
private:
	static constexpr const char *const defName{"Unnamed Savings Account"};
	static constexpr double defBalance {0.0};
	static constexpr double defInRate {0.0};
protected:
	double intRate{0.0};
public:
	SavingsAccount(const string_view &name = defName, const double &balance = defBalance, 
		const double &intRate = defInRate):Account{name, balance}, intRate{intRate}{
		}
	virtual void print(ostream &output) const override{
		output<<"SavingsAccount["<<name<<": "<<balance<<": "<<intRate<<"%]";
	}
	virtual bool deposit(double amount) override{
		amount += amount * (intRate / 100);
		return Account :: deposit(amount);
	}
	virtual bool withdraw(double amount) override{
		return Account::withdraw(amount);
	}
	virtual ~SavingsAccount() = default;
};

class TrustAccount : public SavingsAccount{
private:
	static constexpr char const *const defName {"Unnamed Trust Account"};
	static constexpr double defBalance {0.0};
	static constexpr double defIntRate {0.0};
	static constexpr double bonusAmount {50.00};
	static constexpr double bonusTheshold {5000.00};
	static constexpr int maxWithdrawals {3}; /*Times*/
	static constexpr double maxWithdrawPercent {0.20};
protected:
	int numberOfWithdrawals{0};
public:
	TrustAccount(const string_view &name = defName, const double &balance = defBalance,
		const double &intRate = defIntRate): SavingsAccount{name, balance, intRate},
		numberOfWithdrawals{0}{
			
		}
	virtual void print(ostream &output) const override{
		cout<<"TrustAccount["<<name<<": "<<balance<<": "<<intRate<<"%: "<<numberOfWithdrawals<<"]";
	}
	virtual bool deposit(double amount) override {
		if(amount >= bonusTheshold){
			amount += bonusAmount;
		}
		return SavingsAccount :: deposit(amount);		 
	}
	virtual bool withdraw(double amount) override{
		if(numberOfWithdrawals >= maxWithdrawals || amount >= (balance*maxWithdrawPercent)){
			return false;
		}
		else{
			++numberOfWithdrawals;
			return SavingsAccount :: withdraw(amount);
		}
	}
	virtual ~TrustAccount() = default;
};

/*Display Account objects in a vector of Account object pointers*/
const void display(const vector <Account*> &accounts){
	cout<<"\n===Displaying Accounts=========================="<<endl;
	for(const auto &acc: accounts){
		cout<<*acc<<endl;
	}
}

/*Deposits supplied amount to each Account object pointer in the vector*/
void deposit(vector <Account*> &account, double amount){
	cout<<"\n===Depositing to Accounts=========================="<<endl;
	for(auto &acc: account){
		if(acc->deposit(amount)){
			cout<<"Deposited "<<amount<<" to "<<*acc<<endl;
		}
		else{
			cout<<"Failed Deposit of "<<amount<<" to "<<*acc<<"...!"<<endl;
		}
	}
}

/*Withdraw amount from each Account object pointers in the vector */
void withdraw(vector <Account*> &account, double amount){
	cout<<"\n===Withdrawing from Accounts=========================="<<endl;
	for(auto &acc: account){
		if(acc->withdraw(amount)){
			cout<<"Withdraw "<<amount<<" from "<<*acc<<endl;
		}
		else{
			cout<<"Failed withdraw of "<<amount<<" from "<<*acc<<"...!"<<endl;
		}
	}
}

int main(int argc, const char *const argv[]){
	system("cls");
	cout.precision(2);cout<<fixed;
	/*--------------------------------------------------*/
	CheckingAccount frank {"Frank", 5000};
	cout<<frank<<endl;
	
	Account *trust = new TrustAccount{"James"};
	if(trust){
		cout<<*trust<<endl;
	}
	else{
		cout<<"Memory allocation NOT done for *trust!!!"<<endl;
	}
	delete trust;
	trust = nullptr;
	cout<<"-----------------------------------------------"<<endl;
	
	Account *p1 = new CheckingAccount{"Larry", 10000};
	Account *p2 = new SavingsAccount{"Moe", 1000};
	Account *p3 = new TrustAccount{"Curly"};
	
	vector <Account*> accounts {p1, p2, p3};
	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);
	
	display(accounts);
	delete p1;
	p1 = nullptr;
	
	delete p2;
	p2 = nullptr;
	
	delete p3;
	p3 = nullptr;
	
	cout<<"\n\t\tHappyEnding..."<<endl;
	return 0;
}