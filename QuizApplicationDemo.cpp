/**
 * @file QuizApplicationDemo.cpp
 * @author Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Project: Static Quiz Application Demo
 * @version 0.1
 * @date 2022-08-27
 * @since SaturDay; 11:09 AM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
/*Minimize padding issue for structure*/
#pragma pack(1)
struct QuizApplication{
    /* data */
    string questions;
    string options[3];
};
const unsigned int numberOfQuestion = 10;
/**/
void startQuize(QuizApplication quizApplication[]){
    int ans;
    unsigned int correct = 0;
    for(unsigned int i = 0; i < numberOfQuestion; i++)
    {
        /*Index for question*/
        cout<<(i+1)<<"/. "<<quizApplication[i].questions<<endl;
        /*This loop print 3 options*/
        for(unsigned int j = 0; j<3; j++){
            cout<<"\t"<<(j + 1)<<". "<<quizApplication[i].options[j]<<endl;
        }
        cout<<"Choose 1-3: ";
        input:
        cin>>ans;
        switch (i)
        {
        case 0:
            if(ans == 3){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }
            else if(ans == 1 || ans == 2){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 1:
            if(ans == 2){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 1 || ans == 3){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 2:
            if(ans == 1){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 2 || ans == 3){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 3:
            if(ans == 2){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 1 || ans == 3){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 4:
            if(ans == 1){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 2 || ans == 3){
                cout<<"\t\tIncorrect!"<<endl;
            }
            break;
        case 5:
            if(ans == 3){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 1 || ans == 2){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 6:
            if(ans == 1){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 2 || ans == 3){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 7:
            if(ans == 3){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 1 || ans == 2){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 8:
            if(ans == 1){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 2 || ans == 3){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        case 9:
            if(ans == 2){
                cout<<"\t\tCorrect!"<<endl;
                correct++;
            }else if(ans == 1 || ans == 3){
                cout<<"\t\tIncorrect!"<<endl;
            }else{
                cout<<"Enter Your Answer Again: ";
                goto input;
            }
            break;
        default:
            cout<<"Muhammad Yousuf Ali"<<endl;
            break;
        }
    }
    cout<<"\nYour Correct Answer: "<<correct<<endl;
    cout<<"Your Incorrect Answer: "<<numberOfQuestion - correct<<endl;
}


int main(int argc, char const *argv[])
{
    /* code */
    system("cls");
    /*This is structur entity object*/
    QuizApplication quizApplication[numberOfQuestion];
    //Load Questions
    quizApplication[0].questions = "What is the smallest country?";
    quizApplication[1].questions = "What's the biggest animal in the world?";
    quizApplication[2].questions = "How many elements are there in the periodic table?";
    quizApplication[3].questions = "Which is the captial of bangladesh?";
    quizApplication[4].questions = "Dhaka is capital of Bangladesh. On which river it is situated?";
    quizApplication[5].questions = "What is the currency of Bangladesh?";
    quizApplication[6].questions = "Bangladesh is bordered by two countries. Which ones?";
    quizApplication[7].questions = "What does 'Bangladesh' mean?";
    quizApplication[8].questions = "On which continent is Bangladesh located?";
    quizApplication[9].questions = "What is the oldest city of Bangladesh?";
    //For 1st question
    quizApplication[0].options[0] = "USA";
    quizApplication[0].options[1] = "India";
    quizApplication[0].options[2] = "Vatican City";
    
    //For 2nd question
    quizApplication[1].options[0] = "Elephant";
    quizApplication[1].options[1] = "Blue Whale";
    quizApplication[1].options[2] = "Great White Shark";

    //For 3rd question
    quizApplication[2].options[0] = "118 Elements";
    quizApplication[2].options[1] = "119 Elements";
    quizApplication[2].options[2] = "120 Elements";
    /*For 4th question*/
    quizApplication[3].options[0] = "Rajshahi";
    quizApplication[3].options[1] = "Dhaka";
    quizApplication[3].options[2] = "Chittagong";
    /*For 5th question*/
    quizApplication[4].options[0] = "Buriganga";
    quizApplication[4].options[1] = "Padma";
    quizApplication[4].options[2] = "Jamuna";
    /*For 6th question*/
    quizApplication[5].options[0] = "Rupee";
    quizApplication[5].options[1] = "Rufiyaa";
    quizApplication[5].options[2] = "Taka";
    /*For 7th question*/
    quizApplication[6].options[0] = "India & Myanmar";
    quizApplication[6].options[1] = "Myanmar & Nepal";
    quizApplication[6].options[2] = "Nepal & Bhutan";
    /*For 8th question*/
    quizApplication[7].options[0] = "Land of the Indian";
    quizApplication[7].options[1] = "Land of the Pakistan";
    quizApplication[7].options[2] = "Land of the Bengalis";
    /*For 9th question*/
    quizApplication[8].options[0] = "Asia";
    quizApplication[8].options[1] = "Australia";
    quizApplication[8].options[2] = "Europ";
    /*For 10th question*/
    quizApplication[9].options[0] = "Rajshahi";
    quizApplication[9].options[1] = "Dhaka";
    quizApplication[9].options[2] = "Chittagong";
    //calling function with argument
    startQuize(quizApplication);
    // cout<<"I = "<<i<<"\tIndex = "<<index<<endl;
    getche();
    return 0;
}
