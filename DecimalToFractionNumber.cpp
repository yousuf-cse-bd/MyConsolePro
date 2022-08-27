/**
 * @file DecimalToFractionNumber.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Project: Convert Decimal number into an irreducible Fraction using GCD with class concept
 * @version 0.1
 * @date 2022-08-26
 * @since FriDay; 06:08 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <conio.h>
using namespace std;

#pragma pack(1)
/*Using class*/
class DecimalToFractionNumber
{
private:
    long double decimalNumber;
public:
    DecimalToFractionNumber(long double decimalNumber){
        this->decimalNumber = decimalNumber;
    }
    void decimalToFraction(){
        long double tmp = decimalNumber;
        decimalNumber = abs(decimalNumber);
        string decimalString(to_string(decimalNumber));
        /*consider the value as a natural number, so remove decimal point*/
        string intPart;
        for(unsigned int i = 0; i<decimalString.size(); i++){
            if(decimalString[i] != '.'){
                intPart += decimalString[i];
            }
        }
        /*Counting right side zero's from point*/
        unsigned int countingDigits = 0;
        for(long long int i = decimalString.size() - 1; i>= 0; i--){
            if(decimalString[i] == '.'){
                break;
            }
            else{
                countingDigits++;
            }
        }
        string commonNumber = "1";
        for(unsigned int i = 1; i <= countingDigits; i++){
            commonNumber += "0";
        }
        /*stoull(): string to unsigned long long int*/
        unsigned long long int numerator, denominator;
        numerator = stoll(intPart);
        denominator = stoull(commonNumber);
        /*Now find gcd value for divisor will be gcd, and (numerator and denominator) co-prime number always.*/
        unsigned long long int gcdDivisor = FindGCD(numerator, denominator);
        /*Calculate finaly numerator and denominator for fraction shape*/
        numerator = numerator / gcdDivisor;
        denominator = denominator / gcdDivisor;
        ldiv_t ouput;
        ouput = ldiv(numerator, denominator);
        if(tmp >= 0.0){
            if(denominator > 1){
                cout<<"Typically Frcation Shape: "<<numerator<<'/'<<denominator<<endl;

                if((ouput.quot) != 0){
                    cout<<"My Style Fraction: "<<ouput.quot<<' '<<ouput.rem<<'/'<<denominator<<endl;
                }
            }else{
                cout<<"Typically Frcation Shape: "<<numerator<<endl;
            }
            
        }else{
            if(denominator > 1){
                cout<<"Typically Frcation Shape: -"<<numerator<<'/'<<denominator<<endl;
                
                if((ouput.quot) != 0){
                    cout<<"My Style Fraction: -"<<ouput.quot<<' '<<ouput.rem<<'/'<<denominator<<endl;
                }
            }else{
                cout<<"Typically Frcation Shape: -"<<numerator<<endl;
            }
        }
    }
    /*We know the GCD value can be negative but we consider here all positive*/
    unsigned long long int FindGCD(unsigned long long int number1, unsigned long long int number2){
        unsigned long long int number3;
        while(number2 != 0){
            number3 = number1 % number2;
            number1 = number2;
            number2 = number3;
        }
        return number1;
    }
    ~DecimalToFractionNumber(){
        cout<<"\t\tThanks for trying..."<<endl;
    }
};

/*Driver code*/
int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    long double decimalNumber = 4.5;
    do{
        cout<<"Enter a decimal number here: ";
        cin>>decimalNumber;
        /*Crate an object and call constrcutor with long double type parameter*/
        DecimalToFractionNumber decimalToFractionNumberObject = DecimalToFractionNumber(decimalNumber);
        decimalToFractionNumberObject.decimalToFraction();
    }while(decimalNumber != 0.0);
    getche();
    return 0;
}
