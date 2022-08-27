/**
 * @file ATM_SystemCB.cpp
 * @author Md. Yousuf Ali (youusuf.cse17@gmail.com)
 * @brief Simple ATM machine performance
 * @version 0.1
 * @date 2022-06-09
 * @since ThursDay; 07:15 AM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using namespace std;

class ATMappliaction
{
    double balance, depositAmount, withdrawAmount;
    public:
    ATMappliaction()
    {
        balance = 0.0;
    }
    void showMessage()
    {
        cout<<"***************MENU***************"<<endl;
        cout<<"1 Check Balance"<<endl;
        cout<<"2 Deposit Amount"<<endl;
        cout<<"3 Withdraw Amount"<<endl;
        cout<<"0 EXIT..!"<<endl;
        cout<<"**********************************"<<endl;
    }
    //getBalance
    double checkBalance()
    {
        // cout<<"\t\tYour Remaining Balance: ";
        if(balance!=0)
        return balance;
        else
        return 0;
    }
    void getBalance(double balance)
    {
        this->balance = balance;
    }
    void getDepositAmount(double depositAmount)
    {
        this->depositAmount = depositAmount;
        balance = balance + depositAmount;
        cout<<"\t\tDeposite Done."<<endl;
    }
    void getWithdrawAmount(double withdrawAmount)
    {
        this->withdrawAmount = withdrawAmount;
        if(balance >= withdrawAmount)
        {
            cout<<"\t\tWithdraw Amount : "<<withdrawAmount<<" TK"<<endl;
            balance = balance - withdrawAmount;
        }
        else
            cout<<"\t\tTransaction not Valid."<<endl;
        
    }

    ~ATMappliaction()
    {
        cout<<"\t\tEXIT...!"<<endl;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    //Balance, Deposit, Withdraw;
    system("cls");
    ATMappliaction atmApplication;
    int option;
    do
    {
        atmApplication.showMessage();
        cout<<"Enter Your Option Here: ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"\t\tYour Balance Now: "<<atmApplication.checkBalance()<<" TK"<<endl;
            break;
        case 2:
            cout<<"\t\tDeposit Amount Here: ";
            double depositAmount;
            cin>>depositAmount;
            atmApplication.getDepositAmount(depositAmount);                
            break;
        case 3:
            cout<<"\t\tWithdraw Amunt Here: ";
            double withdrawAmount;
            cin>>withdrawAmount;
            atmApplication.getWithdrawAmount(withdrawAmount);
            break;
            case 0:
            break;
        
        default:
            cout<<"Sorry! Selecet Your the Proper Option."<<endl;
            break;
        }
        
    } while (option != 0);
    
    system("pause>0");
    
    return 0;
}
