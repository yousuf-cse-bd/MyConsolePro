/**
 * @file StandardCalculator.cpp
 * @author Md. Yousuf Ali (yousuf.cse@gmail.com)
 * @brief Standard simple console calculator
 * @version 0.1
 * @date 2022-06-30
 * @since ThursDay; 07:32 AM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <conio.h>
using namespace std;
#pragma pack(1)
class StandardCalculator
{
private:
    /* data */
    long double number1, number2;
    // char * arithmeticSign = new char[2];
    string arithmeticSign;
public:
    long double result = 0;
    StandardCalculator(){
        system("cls");
    }
    void input1(){
        cout<<"\tEnter First Number Here: ";
        cin>>number1;
    }
    void input2(){
        cout<<"\tEnter Next Number : ";
        cin>>number2;
    }
    void inputOperator(){
        // cout<<"\tEnter Your Operator[+,-,*,/]: ";
        cin>>arithmeticSign;
        cout<<"Arithmetic: "<<arithmeticSign[0]<<endl;
        if(arithmeticSign == "+"){
            input2();
            add();
        }
        else if(arithmeticSign[0] == '-'){
            input2();
            sub();
        }
        else if(arithmeticSign[0] == '*'){
            input2();
            mult();
        }
        else if(arithmeticSign[0] == '/'){
            input2();
            div();
        }
        else{
            cout<<"Your Entered Operator Invalid"<<endl;
        }
        
    }
    void allClear(){
        number1 = 0;
        number2 = 0;
        result = 0;
        // arithmeticSign = nullptr;
    }
    void add(){
        result = number1 + number2;
        cout<<"\tResult: "<<result<<endl;
    }
    void sub(){
        result = number1 - number2;
        cout<<"\tResult: "<<result<<endl;
    }
    void mult(){
        result = number1 * number2;
        cout<<"\tResult: "<<result<<endl;
    }
    void div(){
        if(number2 == 0){
            cout<<"Infinity...!"<<endl;
        }
        else{
            result = number1 / number2;
            cout<<"\tResult: "<<result<<endl;
        }
    }
    long double answer(){
        return result;
    }
    void clear(){
        number1 = 0;
        number2 = 0;
    }
    ~StandardCalculator(){
        // delete(arithmeticSign);
        cout<<"Called by Destructor...!"<<endl;
    }
};

void design(unsigned int n){
    for(unsigned int i = 1; i<=n;i++){
        cout<<"==========";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    system("cls");
    StandardCalculator myCalculator;
    int option;
    do
    {   design(5);
        cout<<"0 for EXIT"<<endl;
        cout<<"1 for First Input"<<endl;
        cout<<"2 for [+,-,*,/]"<<endl;
        cout<<"3 for Answer"<<endl;
        cout<<"4 for Clear"<<endl;
        cout<<"5 for All Clear"<<endl;
        design(5);
        cout<<"\tChoose Your Right Option Here: ";
        cin>>option;
        
        switch (option)
        {
        case 0:
            cout<<"EXIT..!"<<endl;
            break;
        case 1:
            myCalculator.input1();
            break;
        case 2:
            myCalculator.inputOperator();
            break;
        case 3:
            cout<<"Your Result: "<<myCalculator.answer()<<endl;
            break;
        case 4:
            myCalculator.clear();
            break;
        case 5:
            myCalculator.allClear();
            break;
        default:
            cout<<"Please! Enter the right option..!"<<endl;
            break;
        }
    } while (option != 0);
    getche();
    return 0;
}
