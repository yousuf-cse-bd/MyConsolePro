/**
 * @file AgeCalculatorPro.cpp
 * @author Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Project: Age calculator
 * @version 0.1
 * @date 2022-08-15
 * @since MonDay; 12:03 PM
 * @copyright Copyright (c) 2022
 * Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <cmath>
#include <ctime>
#include <conio.h>
using namespace std;
#pragma pack(1)
class AgeCalculatorPro{
    private:
    unsigned int currentDate, currentMonth, currentYear;
    unsigned int birthDate, birthMonth, birthYear;
    //                                jan,feb,mar,apri,may,jun,jul,Aug,sep,oct,nov,dec
    unsigned int daysInPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const string daysName[7] = {"SunDay", "MonDay", "TuesDay", "WednesDay", "ThursDay", "FriDay", "SaturDay"};
    public:
    /*Defult constructor*/
    AgeCalculatorPro(){
        // system("cls");
        if(isLeapYear(birthYear)){
            daysInPerMonth[1] = 29;
            // cout<<"Leap Year: "<<endl;
        }
    }
    short int dayOfTheWeek(unsigned int day, unsigned int month, unsigned int year){
        // printf("%0.2u-%0.2u-%0.4u\n", day, month, year);
        unsigned int a, y, m;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;
        // Gregorian calendar:
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    bool isLeapYear(unsigned int birthYear){
        if((birthYear % 4 == 0 && birthYear % 100 != 0) || (birthYear % 100 == 0)){
            return true;
        }else{
            return false;
        }
    }
    void inputAgeAtTheDateOf(unsigned int currentDate, unsigned int currentMonth,unsigned int currentYear){
        this->currentDate = currentDate;
        this->currentMonth = currentMonth;
        this->currentYear = currentYear; 
        printf("\tYour Age at the Date of: %0.2u-%0.2u-%0.4u\n", currentDate, currentMonth, currentYear);
    }
    void inputDateOfBirth(unsigned int birthDate, unsigned int birthMonth,unsigned int birthYear){
        this->birthDate = birthDate;
        this->birthMonth = birthMonth;
        this->birthYear = birthYear;
        printf("\tYour Date of Birth: %0.2u-%0.2u-%0.4u\n", birthDate, birthMonth, birthYear);
    }
    string formatedNumber(string number){
        for(int i = number.size() - 3; i > 0; i = i - 3){
            number.insert(number.begin()+i, ',');
        }
        return number;
    }
    
    string ageCalculator(){
        /*If current-date is less than birth-date*/

        if(currentDate < birthDate){
            /*Pointing birthMonth*/
            currentDate = currentDate + daysInPerMonth[birthMonth - 1];
            currentMonth--;
        }

        /*If current-month is less than birth-month*/
        if(currentMonth < birthMonth){
            currentMonth = currentMonth + 12;
            currentYear --;
        }

        unsigned int days, months, years;
        days = currentDate - birthDate;
        months = currentMonth - birthMonth;
        years = currentYear - birthYear;
        short thatDay = dayOfTheWeek(birthDate, birthMonth, birthYear);
        cout<<"\t\tThat day was: "<<daysName[thatDay]<<endl;
        
        cout<<"1. In as All Month: "<<(years * 12) + months<<", Days: "<<days<<endl;
        months = (years * 12) + months;
        double d = (months * 30.41666666666667) + days;
        cout<<"2. In as All Days: "<<ceil(d)<<endl;
        /*Calculation in hours*/
        unsigned int hours = (d * 24);
        string number;
        number = formatedNumber(to_string(hours));
        cout<<"3. In as All Hours: "<<number<<endl;

        
        /*Calculation in minutes*/
        unsigned minutes = (hours * 60);
        number = formatedNumber(to_string(minutes));
        cout<<"4. In as All Minutes: "<<number<<endl;
        /*Calculation in seconds*/
        unsigned  long long int seconds = minutes * 60;
        number = formatedNumber(to_string(seconds));
        cout<<"5. In as All Seconds: "<<number<<endl;
        string age = to_string(years).append(" Years, ").append(to_string(months)).append(" Months, ").append(to_string(days)).append(" Days.");
        return age;
    }
};


int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    /*Declaring argument of time()*/
    time_t currentTime = time(0);
    /*ctime() used to give the present time*/
    cout<<"Current Date and Time: "<<ctime(&currentTime)<<endl;
    AgeCalculatorPro myAgeCalculator;
    string currentDate, birthDate;
    char cDate[3], cMonth[3], cYear[5];
    char bDate[3], bMonth[3], bYear[5];
    cout<<"Enter Current Date(DD-MM-YYYY): ";
    cin>>currentDate;
    cDate[0] = currentDate[0];
    cDate[1] = currentDate[1];

    cMonth[0] = currentDate[3];
    cMonth[1] = currentDate[4];

    cYear[0] = currentDate[6];
    cYear[1] = currentDate[7];
    cYear[2] = currentDate[8];
    cYear[3] = currentDate[9];
    myAgeCalculator.inputAgeAtTheDateOf(stoi(cDate), stoi(cMonth), stoi(cYear));
    cout<<"Enter Birth Date(DD-MM-YYY): ";
    cin>>birthDate;
    if(currentDate == birthDate){
        cout<<"Your Age: "<<"Same Day"<<endl;
    }else{
        bDate[0] = birthDate[0];
        bDate[1] = birthDate[1];

        bMonth[0] = birthDate[3];
        bMonth[1] = birthDate[4];

        bYear[0] = birthDate[6];
        bYear[1] = birthDate[7];
        bYear[2] = birthDate[8];
        bYear[3] = birthDate[9];
        myAgeCalculator.inputDateOfBirth(stoi(bDate), stoi(bMonth), stoi(bYear));
        string age;
        age = myAgeCalculator.ageCalculator();
        cout<<"Your Age: "<<age<<endl;
    }
    getch();
    return 0;
}
