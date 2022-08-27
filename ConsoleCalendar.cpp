/**
 * @file ConsoleCalendar.cpp
 * @author Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Project: A simple console calendar
 * @version 0.1
 * @date 2022-08-14
 * @since Sunday; 11: 41 AM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using namespace std;
/*Find leap year*/
bool isLeapYear(unsigned int year){
    if((year % 4 == 0   && year % 100 != 0) || (year % 400 == 0)){
        return true;
    }
    else{
        return false;
    }
}
/*Get first day of the year*/
int getFirstDayOfTheYear(unsigned int year){
    int firstDayOfTheYear = firstDayOfTheYear = (year*365 + ((year-1)/4) - ((year - 1)/100) + ((year - 1) / 400)) % 7;
    return firstDayOfTheYear;
}
int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    unsigned int year;
    cout<<"Enter your favorite year here,?: ";
    cin>>year;
    /*Message showing*/
    cout<<"\n\n*************************WELCOME TO "<<year<<"*************************\n"<<endl;
    const char * monthName[] = {"January", "February", "March", "Aprill", "May", "June",
    "July", "August", "September", "October", "November", "December"};
    int daysInPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    /*If year is leap-year*/
    if(isLeapYear){

        daysInPerMonth[1] = 29;
    }
    const char * daysName[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fir", "Sat"};
    /*Outer loop prints months name and inner loop prints days name*/
    int weekDayCounter;
    weekDayCounter = getFirstDayOfTheYear(year);
    for(unsigned int i = 0; i<12; i++){
        cout<<"\n\n-------------------------"<<monthName[i]<<"-------------------------"<<endl;
        for(unsigned int j = 0; j<7; j++){
            cout<<daysName[j]<<"\t";
        }
        cout<<"\n"<<endl;
        for(unsigned int tabCounter = 1; tabCounter <= weekDayCounter; tabCounter++){
            cout<<"\t";
        }
        /*Print all days and newline each 7 days*/
        for(unsigned int day = 1; day <= daysInPerMonth[i]; day++){
            weekDayCounter ++;
            if(weekDayCounter == 7){
                cout<<day<<"\n";
                weekDayCounter = 0;
            }else{
                cout<<day<<"\t";
            }
        }
    }
    
    return 0;
}
