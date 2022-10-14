/**
 * @file DivisibleBigNumber.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Check divisible big positive number by (2,3,4,5,6,9)
 * @version 0.1
 * @date 2022-10-14
 * @since FriDay; 05:04 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(1)
using namespace std;
/*unsign long long int takes 18 max digits like 9999*/
class DivisibleBigNumber{
private:
    string decimalNumberString;
    unsigned long long int decimalNumber; /* unsigned long long int = 0 to 18,446,744,073,709,551,615*/
    unsigned int sumOfDigits;
    bool isLengthLessThan18(void){
        if(decimalNumberString.length() <= 18){
            decimalNumber = stoull(decimalNumberString);
            return true;
        }else{
            return false;
        }
    }
public:
    DivisibleBigNumber(string decimalNumberString){
        this->decimalNumberString = decimalNumberString;
        sumOfDigits = 0;
    }
    bool isDivisibleBy2(unsigned short modular){
        unsigned short int ones;
        if(isLengthLessThan18()){
            // cout<<"Decimal Number: "<<decimalNumber<<endl;
            if(decimalNumber % modular == 0){
                return true;
            }else{
                return false;
            }
        }
        else{
            ones = (decimalNumberString[decimalNumberString.size()-1]-'0');
            // cout<<"Ekok Position: "<<ones<<endl;
            if(ones % modular == 0){
                return true;
            }else{
                return false;
            }
        }
    }

    bool isDivisibleBy3(unsigned short modular){
        unsigned short int decimalDigit;
        if(isLengthLessThan18()){
            if(decimalNumber % modular == 0){
                return true;
            }else{
                return false;
            }
        }else{
            for(register int i = 0; i<decimalNumberString.size(); i++){
                sumOfDigits += (unsigned short int)(decimalNumberString[i]-'0');
            }
            if(sumOfDigits % modular == 0){
                return true;
            }
            else{
                return false;
            }
        }
    }

    bool isDivisibleBy4(unsigned short modular){
        if(isLengthLessThan18()){
            if(decimalNumber % 4 == 0){
                return  true;
            }else{
                return false;
            }
        }else{
            char ones, tens;
            ones = decimalNumberString[decimalNumberString.size()-1];
            tens = decimalNumberString[decimalNumberString.size()-2];
            char twoDigitsNumber[3] = {tens, ones, '\0'};
            decimalNumber = stoull(twoDigitsNumber);
            if(decimalNumber % modular == 0 || ones == '0' && tens == '0'){
                return true;
            }else{
                return false;
            }
        }
    }

    bool isDivisibleBy5(unsigned short modular){
        char ones = decimalNumberString[decimalNumberString.size()-1];
        if(ones == '0' || ones == '5'){
            return true;
        }
        else if(decimalNumber % modular == 0){
            return true;
        }else{
            return false;
        }
    }
    bool isDivisibleBy6(unsigned short modular){
        if(isDivisibleBy2(2) && isDivisibleBy3(3)){
            return true;
        }else{
            return false;
        }
    }
    bool isDivisibleBy9(unsigned int modular){
        unsigned short int decimalDigit;
        if(isLengthLessThan18()){
            if(decimalNumber % modular == 0){
                return true;
            }else{
                return false;
            }
        }else{
            for(register int i = 0; i<decimalNumberString.size(); i++){
                sumOfDigits += (unsigned short int)(decimalNumberString[i]-'0'); /*Type casting*/
            }
            if(sumOfDigits % modular == 0){
                return true;
            }
            else{
                return false;
            }
        }
    } 
};

int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    unsigned short int rightSign = 251; /*Right sign ascci code*/
    string decimalNumberString = "18446744073709551615";
    cout<<"Enter a Positive Number Here: ";
    cin>>decimalNumberString;
    cout<<endl;
    DivisibleBigNumber determiner = DivisibleBigNumber(decimalNumberString);
    if(determiner.isDivisibleBy2(2)){
        printf("\t%c", rightSign);
        cout<<"The "<<decimalNumberString<<" is Divisible by TWO '2'.\n"<<endl;
    }else{
        cout<<"\t x The "<<decimalNumberString<<" is NOT Divisible by TWO '2'.\n"<<endl;
    }

    if(determiner.isDivisibleBy3(3)){
        printf("\t%c", rightSign);
        cout<<"The "<<decimalNumberString<<" is Divisible by THREE '3'.\n"<<endl;
    }else{
        cout<<"\t x The "<<decimalNumberString<<" is NOT Divisible by THREE '3'.\n"<<endl;
    }

    if(determiner.isDivisibleBy4(4)){
        printf("\t%c", rightSign);
        cout<<"The "<<decimalNumberString<<" is Divisible by FOUR '4'.\n"<<endl;
    }else{
        cout<<"\t x The "<<decimalNumberString<<" is NOT Divisible by FOUR '4'.\n"<<endl;
    }

    if(determiner.isDivisibleBy5(5)){
        printf("\t%c", rightSign);
        cout<<"The "<<decimalNumberString<<" is Divisible by FIVE '5'.\n"<<endl;
    }else{
        cout<<"\t x The "<<decimalNumberString<<" is NOT Divisible by FIVE '5'.\n"<<endl;
    }

    if(determiner.isDivisibleBy6(6)){
        printf("\t%c", rightSign);
        cout<<"The "<<decimalNumberString<<" is Divisible by SIX '6'.\n"<<endl;
    }else{
        cout<<"\tx The "<<decimalNumberString<<" is NOT Divisible by SIX '6'.\n"<<endl;
    }

    if(determiner.isDivisibleBy9(9)){
        printf("\t%c", rightSign);
        cout<<"The "<<decimalNumberString<<" is Divisible by NINE '9'.\n"<<endl;
    }else{
        cout<<"\t x The "<<decimalNumberString<<" is NOT Divisible by NINE '9'.\n"<<endl;
    }
    system("pause>0");
    return 0;
}
