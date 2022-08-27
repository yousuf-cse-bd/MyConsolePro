/**
 * @file AlarmingClockPro.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Project: Alarming clock project with beep sound
 * @version 0.1
 * @date 2022-08-17
 * @since WednesDay; 03:01 AM
 * @copyright Copyright (c) 2022
 * Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <ctime> //Return system time
#include <windows.h> //Beep(Frequency, Millisecond)
#include <conio.h> //Window holder
using namespace std;

const short int cycle = 60;
class AlarmingClockPro
{
private:
    unsigned int hour, minute, second;
public:
    AlarmingClockPro(unsigned int hour, unsigned int minute, unsigned int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
        alarmingClockFunction();
    }
    /*Beep sound provider 30 times*/
    void beepSoundProvider(){
        cout<<"Alarm Start:"<<endl;
        cout<<"Alarming now..."<<endl;
        for(unsigned int i = 1; i <= 5; i++){
            /*First arg: frequency and Second arg: millisecond*/
            Beep(580, 900);
        }
        cout<<"Alarm Stop:"<<endl;
    }
    void alarmingClockFunction(){
        unsigned int hourCounter, minuteCounter, secondCounter;
        hourCounter =  minuteCounter = secondCounter = 0;
        while(true){
            if(hour == hourCounter && minute == minuteCounter && second == secondCounter){
                cout<<"<><><><><><><><><<><><>:LAST TIME:<><><><><><><><><<><><>\n"<<endl;
                printf("\t\t\t%0.2d:%0.2d:%0.2d\n", hourCounter, minuteCounter, secondCounter);
                cout<<"\n<><><><><><><><><<><><><><><><><><><><><<><><><><><><><>\n"<<endl;
                cout<<"Hour: "<<hourCounter<<endl;
                cout<<"Minute: "<<minuteCounter<<endl;
                cout<<"Second: "<<secondCounter<<endl;
                beepSoundProvider();
                break;
            }
            else{
                cout<<"<><><><><><><><><<><><><>:JUST TIMER:<><><><><><><><><<><><>\n"<<endl;
                printf("\t\t\tTimer: %0.2d:%0.2d:%0.2d\n", hourCounter, minuteCounter, secondCounter);
                cout<<"\n<><><><><><><><><><><><><><><><><><><><><><><><><<><><><><>\n"<<endl;
                /*Delay for 1 second*/
                Sleep(1000);
                system("cls");
            }
            secondCounter ++;
            if(secondCounter == cycle){ // cycle = 60
                minuteCounter ++;
                secondCounter = 0;
            }
            if(minuteCounter == cycle){ // cycle = 60
                hourCounter ++;
                minuteCounter = 0;
            }
        }
    }
    ~AlarmingClockPro(){
        cout<<"<@THANKS@>"<<endl;
    }
};
/*Print system time and date*/
void currentTimeAndDate(){
    time_t now = time(0);
    tm *timeDatePtr = localtime(&now);
    /*Return time*/
    cout<<"Second: "<<timeDatePtr->tm_sec<<endl;
    cout<<"Minute: "<<timeDatePtr->tm_min<<endl;
    cout<<"Hour: "<<timeDatePtr->tm_hour<<endl;

    /*Return Date*/
    printf("The day of the month: %0.2d \n", timeDatePtr->tm_mday);
    /*tm_mon indexing start 0, that's why + 1*/
    printf("The month of the year: %0.02d \n",(timeDatePtr->tm_mon)+1);
    /*A man max alive 122 year so 1900 added*/
    cout<<"Year: "<<(timeDatePtr->tm_year)+1900<<endl;
    cout<<"The day of the week day: "<<timeDatePtr->tm_wday<<endl;
    cout<<"The day of the year: "<<timeDatePtr->tm_yday<<endl;
    cout<<"Day light savings: "<<timeDatePtr->tm_isdst<<endl; //?
    cout<<endl;
    /*YYYY = 0.4 optinal, but another good looking*/
    cout<<"Current Date: ";
    printf("%0.2d-%0.2d-%0.4d\n", timeDatePtr->tm_mday, ((timeDatePtr->tm_mon)+1),((timeDatePtr->tm_year)+1900));
    cout<<"Current Time: ";
    printf("%0.2d:%0.2d:%0.2d\n", timeDatePtr->tm_hour, timeDatePtr->tm_min, timeDatePtr->tm_sec);    
}


int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    /*Create an object with calling constructor*/
    AlarmingClockPro myAlarmingClock = AlarmingClockPro(0, 0, 5);
    currentTimeAndDate();
    getch();
    cout<<"Yousuf.cse17"<<endl;
    return 0;
}
