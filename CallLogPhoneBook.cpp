/**
 * @file CallLogPhoneBook.cpp
 * @author Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Simple project CALLL_LOG PHONE_BOOK not using pointer concept by stack DS with class.
 * @version 0.1
 * @date 2022-08-13
 * @since SaturDay; 07:17 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
using namespace std;
/*User defined data dype contains name and number*/
typedef struct{
    string name;
    unsigned int number;
}Contact;
const int size = 10;
class CallLogPhoneBook{
    private:
    Contact myContacts[size];
    unsigned int top;
    public:
    CallLogPhoneBook(){
        top = 0;
    }
    /*Insert an element*/
    void push(string name, unsigned int number){
        if(top < size){
            myContacts[top].name = name;
            myContacts[top].number = number;
            ++top;
        }else{
            cout<<"Stack is full..."<<endl;
        }
    }
    /*Delete an element*/
    void pop(){
        if(top == 0){
            cout<<"Stack is empty..."<<endl;
        }else{
            --top;
            cout<<"Your last contact:"<<endl;
            cout<<myContacts[top].name<<endl;
            cout<<myContacts[top].number<<endl;
        }
    }

    void allContacts(){
        if(top == 0){
            cout<<"You have no contack at all."<<endl;
        }
        else{
            cout<<"All contatck list below:\n";
            for(int i = top - 1; i>=0; i--){
                cout<<"Name: "<<myContacts[i].name<<endl;
                cout<<"Number: "<<myContacts[i].number<<endl;
            }
        }
    }
};
/*Driver Code*/
int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    CallLogPhoneBook myPhoneBook;
    string name;
    unsigned int number;

    int option;
    do{
        cout<<"\t1 for Push call:"<<endl;
        cout<<"\t2 for Pop call:"<<endl;
        cout<<"\t3 for Display call:"<<endl;
        cout<<"\t0 for EXIT"<<endl;
        cout<<"\tEnter your choise here: ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Enter a new contact name and number:"<<endl;
            cin>>name>>number;
            myPhoneBook.push(name, number);
            break;
        case 2: 
            myPhoneBook.pop();
            break;
        case 3:
            myPhoneBook.allContacts();
            break;
        case 0:
            cout<<"Your program is terminated."<<endl;
            break;
        default:
            cout<<"Enter your right choise..."<<endl;
            break;
        }
    } while (option != 0);
    
    return 0;
}
