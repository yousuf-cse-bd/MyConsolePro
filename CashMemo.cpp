/**
 * @file CashMemo.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Simple cash memo program concept from ICT college book
 * @version 0.1
 * @date 2022-07-23
 * @since Saturday, 5:44 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using  namespace std;
class CashMemo{
private:
    /* data */
    string customerName, customerAddress;
    unsigned int customerPhoneNumber;
    string productName;
    long double productPrice, totalAmount, totalVatInclude, finalAmount;
    float vat;
    unsigned int productQuantity;
public:
    CashMemo(){
        cout<<"\tJust Constructor"<<endl;
    }
    ~CashMemo(){
        cout<<"\tDestructor"<<endl;
    }

    void inputCustomerInfo(string customerName, string customerAddress, unsigned int customerPhoneNumber){
        this->customerName = customerName;
        this->customerAddress = customerAddress;
        this->customerPhoneNumber = customerPhoneNumber;
    }
    void sellProduct(){
        cout<<"Please, Enter the product name if you want?: ";
        cin>>productName;
        cout<<"Enter number of product: ";
        cin>>productQuantity;
        cout<<"Enter the price value here: ";
        cin>>productPrice; 
    }
    void calculation(){
        vat = 0.15;
        totalAmount = productPrice * productQuantity;
        totalVatInclude = totalAmount * vat;
        finalAmount = totalAmount + totalVatInclude;
    }
    void showInfoPrint(){
        cout<<"***************Cash_Memo***************"<<endl;
        cout<<"Customer Name: "<<customerName<<endl;
        cout<<"Customer Address: "<<customerAddress<<endl;
        cout<<"Customer Phone: "<<customerPhoneNumber<<endl;

        cout<<"Product Name: "<<productName<<endl;
        cout<<"Number of Product: "<<productQuantity<<endl;
        cout<<"Price of Product: "<<productPrice<<endl;
        cout<<"Vat Value: "<<vat * 100<<"%"<<endl;
        cout<<"Total Vat: "<<totalVatInclude<<endl;
        cout<<"Final Bill Amount: "<<finalAmount<<" in Taka"<<endl;
    }
};




int main(int argc, char const *argv[])
{
    /* code */
    system("cls");
    CashMemo myCashMemo;
    string customerName, customerAddress;
    unsigned int customerPhoneNumber;
    cout<<"Enter your name: ";
    getline(cin, customerName);
    cout<<"Enter your address:";
    getline(cin, customerAddress);
    cout<<"Enter your active phone number: ";
    cin>>customerPhoneNumber;
    myCashMemo.inputCustomerInfo(customerName, customerAddress, customerPhoneNumber);
    myCashMemo.sellProduct();
    myCashMemo.calculation();
    myCashMemo.showInfoPrint();
    return 0;
}
