#include <iostream>
#include <vector>
#include <iomanip>
#pragma pack(1)
using namespace std;

class Account{
	friend ostream &operator<< (ostream &output, const Account &account){
		output<<"Account: ["<<account.name<<", "<<account.balance<<"]";
		return output;
	}
private:
	static constexpr const char *const defName{"Unnamed Account"};
protected:
	string name{};
	double balance{0.0};
	static constexpr double defBalance{0.0};
public:
	Account(const string_view &name = defName, const double &balance = defBalance):
		name{name}, balance{balance}{}
	bool withdraw(const double &amount){
		if(balance - amount >= 0){
			balance -= amount;
			return true;
		}
		else{
			return false;
		}
	}
	bool deposit(const double &amount){
		if(amount > 0){
			balance += amount;
			return true;
		}
		else{
			return false;
		}
	}
};

class SavingsAccount: public Account{
	friend ostream &operator<< (ostream &output, const SavingsAccount &savingsAccount){
		output<<"SavingsAccount: ["<<savingsAccount.name<<", "<<savingsAccount.balance<<", ";
		output<<savingsAccount.intRate<<"%]";
		return output;
	}
private:
	static constexpr const char *const defName{"Unnamed Savings Account"};
	static constexpr double defIntRate{0.0};
protected:
	double intRate{};
public:	
	SavingsAccount(const string_view &name = defName, const double &balance = defBalance,
		const double &intRate = defIntRate):Account{name, balance}, intRate{intRate}{}
	bool deposit(double amount){
		amount += (amount*intRate/100);
		return Account::deposit(amount);
	}
};

class CheckingAccount : public Account{
	friend ostream &operator<< (ostream &output, const CheckingAccount &checkingAccount){
		output<<"CheckingAccount: ["<<checkingAccount.name<<", "<<checkingAccount.balance;
		output<<", "<<checkingAccount.perCheckFee<<"]";
		return output;
	}
private:
	static constexpr const char *const defName {"Unnamed Checking Account"};
	const double perCheckFee {1.50};
public:
	CheckingAccount(const string_view &name = defName, const double &balance = defBalance)
		:Account{name, balance}{}
	bool withdraw(double amount){
		amount += perCheckFee;
		return Account :: withdraw(amount);
	}
};

class TrustAccount : public SavingsAccount{
	friend ostream &operator<< (ostream &output, const TrustAccount &trustAccount){
		output<<"TrustAccount: ["<<trustAccount.name<<", "<<trustAccount.balance<<",";
		output<<trustAccount.intRate<<"%, "<<trustAccount.numWithdrawls<<"]";
		return output;
	}
private:
	static constexpr const char *const defName{"Unnamed Trust Account"};
	static constexpr double defIntRate{0.0};
	static constexpr double bonusAmount{50.00};
	static constexpr double bonusThreshold{5000.00};
	static constexpr int maxWithdrawals {3};
	static constexpr double maxWithdrawalsPercent {0.2};
	
protected:
	int numWithdrawls;
	
public:
	TrustAccount(const string_view &name = defName, const double &balance = defBalance,
		const double intRate = defIntRate):
		SavingsAccount{name, balance, intRate}, numWithdrawls{0}{}
	bool deposit(double amount){
		if(amount >= bonusThreshold){
			amount +=bonusAmount;
		}
		return SavingsAccount :: deposit(amount);
	}
	/*Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value*/
	bool withdraw(double amount){
		if((numWithdrawls >= maxWithdrawals) || (amount > balance * maxWithdrawalsPercent)){
			return false;
		}
		else{
			++numWithdrawls;
			return SavingsAccount::withdraw(amount);
		}
	}
};
/*Helper functions for Account class*/
/*Displays Account objects in a vector of Account objects*/
void display(const vector <Account> &accounts){
	cout<<"\n===Accounts============================================="<<endl;
	for(const auto &acc: accounts){
		cout<<acc<<endl;
	}
}
/*Deposits supplied amount to each Account object in the vector*/
void deposit(vector <Account> &accounts, double amount){
	cout<<"\n===Depositing to Accounts=================================="<<endl;
	for(auto &acc: accounts){
		if(acc.deposit(amount)){
			cout<<"Deposited "<<amount<<" to "<<acc<<endl;
		}
		else{
			cout<<"Faild Deposite of "<<amount<<" to "<<acc<<endl;
		}
	}
}

/*Withdraw amount from each Account object in the vector*/
void withdraw(vector <Account> &accounts, double amount){
	cout<<"\n===Withdrawing from Accounts==============================="<<endl;
	for(auto &acc: accounts){
		if(acc.withdraw(amount)){
			cout<<"Withdrew "<<amount<<" from "<<acc<<endl;
		}
		else{
			cout<<"Failed Withdrawal of "<<amount<<" from "<<acc<<endl;
		}
	}
}

/*Helper functions for SavingsAccount class*/
/*Displays SavingsAccount object in a vector of SavingsAccount objects*/
void display(const vector <SavingsAccount> &savingsAccounts){
	cout<<"\n===SavingsAccount=========================================="<<endl;
	for(const auto &sAcc: savingsAccounts){
		cout<<sAcc<<endl;
	}
}

/*Deposits supplied amount to each SavingsAccount object in the vector*/
void deposit(vector <SavingsAccount> &savingsAccounts, double amount){
	cout<<"\n===Depositing to SavingsAccounts==========================="<<endl;
	for(auto &sAcc: savingsAccounts){
		if(sAcc.deposit(amount)){
			cout<<"Deposited "<<amount<<" to "<<sAcc<<endl;
		}
		else{
			cout<<"Faild Deposit of "<<amount<<" to "<<sAcc<<endl;
		}
	}
}

/*Withdraw supplied amount from each SavingsAccounts object in the  vector*/
void withdraw(vector <SavingsAccount> &savingsAccounts, double amount){
	cout<<"\n===Withdrawing from SavingsAccount========================="<<endl;
	for(auto &sAcc: savingsAccounts){
		if(sAcc.withdraw(amount)){
			cout<<"Withdrew "<<amount<<" from "<<sAcc<<endl;
		}
		else{
			cout<<"Faild Withdrawl of "<<amount<<" from "<<sAcc<<endl;
		}
	}
}

/*Helper functions fom CheckingAccount class*/
/*Displays Checking Account objects in a vector of CheckingAccount objects*/
void display(const vector <CheckingAccount> &checkingAccounts){
	cout<<"\n====CheckingAccounts========================================"<<endl;
	for(const auto &checAcc: checkingAccounts){
		cout<<checAcc<<endl;
	}
}

/*Deposits supplied amount to each CheckingAccount object in the vector*/
void deposit(vector <CheckingAccount> &checkingAccount, double amount){
	cout<<"\n====Depositing to CheckingAccounts========================="<<endl;
	for(auto &cheAcc: checkingAccount){
		if(cheAcc.deposit(amount)){
			cout<<"Deposited "<<amount<<" to "<<cheAcc<<endl;
		}
		else{
			cout<<"Faild Deposit of "<<amount<<" to "<<cheAcc<<endl;
		}
	}
}

/*Withdraw supplied amount from each CheckingAccount object in the vector*/
void withdraw(vector <CheckingAccount> &checkingAccounts, double amount){
	cout<<"\n===Withdrawing from CheckingAccounts======================="<<endl;
	for(auto &cheAcc: checkingAccounts){
		if(cheAcc.withdraw(amount)){
			cout<<"Withdrew "<<amount<<" from "<<cheAcc<<endl;
		}
		else{
			cout<<"Faild Withdrawal of "<<amount<<" from "<<cheAcc<<endl;
		}
	}
}

/*Helper functions for TrustAccount class*/
/*Displays TrustAccount objects in a vector of TrustAccount objects*/
void display(const vector <TrustAccount> &trustAccount){
	cout<<"\n===TrustAccounts==========================================="<<endl;
	for(const auto &trustAcc: trustAccount){
		cout<<trustAcc<<endl;
	}
}

/*Deposits supplied amount to each TrustAccount object in the vector*/
void deposit(vector <TrustAccount> &trustAccount, double amount){
	cout<<"\n====Depositing to TrustAccount========================="<<endl;
	for(auto &trusAcc: trustAccount){
		if(trusAcc.deposit(amount)){
			cout<<"Deposited "<<amount<<" to "<<trusAcc<<endl;
		}
		else{
			cout<<"Faild Deposit of "<<amount<<" to "<<trusAcc<<endl;
		}
	}
}

/*Withdraw supplied amount from each TrustAccount object in the vector*/
void withdraw(vector <TrustAccount> &trustAccount, double amount){
	cout<<"\n===Withdrawing from TrustAccounts======================="<<endl;
	for(auto &trustAcc: trustAccount){
		if(trustAcc.withdraw(amount)){
			cout<<"Withdrew "<<amount<<" from "<<trustAcc<<endl;
		}
		else{
			cout<<"Faild Withdrawal of "<<amount<<" from "<<trustAcc<<endl;
		}
	}
}


int main(int argc, char const **argv){
	system("cls");
	cout<<fixed<<setprecision(2); /*After decimal 2 digits*/
//	cout.precision(3); /*Total 3 digits*/
	/*Account*/
	vector <Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{"Larry"});
	accounts.push_back(Account{"Moe", 2000});
	accounts.push_back(Account{"Curly", 5000});
	
	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);
	
	/*SavingsAccounts*/
	vector <SavingsAccount> savingsAcconts;
	savingsAcconts.push_back(SavingsAccount{});
	savingsAcconts.push_back(SavingsAccount{"Superman"});
	savingsAcconts.push_back(SavingsAccount{"Batman", 2000});
	savingsAcconts.push_back(SavingsAccount{"Wonderwoman", 5000, 5.0});
	
	display(savingsAcconts);
	deposit(savingsAcconts, 1000);
	withdraw(savingsAcconts, 2000);
	
	/*CheckingAccounts*/
	vector <CheckingAccount> checkingAccount;
	checkingAccount.push_back(CheckingAccount{});
	checkingAccount.push_back(CheckingAccount{"Kirk"});
	checkingAccount.push_back(CheckingAccount{"Spock", 2000});
	checkingAccount.push_back(CheckingAccount{"Bones", 5000});
	
	display(checkingAccount);
	deposit(checkingAccount, 1000);
	withdraw(checkingAccount, 2000);
	
	/*TrustAccount*/
	vector <TrustAccount> trustAccount;
	trustAccount.push_back(TrustAccount{});
	trustAccount.push_back(TrustAccount{"Athos", 10000, 5.0});
	trustAccount.push_back(TrustAccount{"Porthos", 20000, 4.0});
	trustAccount.push_back(TrustAccount{"Aramis", 30000});
	
	display(trustAccount);
	deposit(trustAccount, 1000);
	withdraw(trustAccount, 3000);
	cout<<"-------------------------------------------------"<<endl; 
	/*Withdraw 5 times from each TrustAccount*/
	/*All withdraw should fail if there are too many withdrawals or
	 If the withdrawal is > 20% of the balance*/
	for(size_t i {1}; i <= 5; i++){
		withdraw(trustAccount, 1000);
	}
	
	return 0;
}