/**
 * @file AlphanumericHistogram.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Project: An alphanumeric histogram console application
 * @version 0.1
 * @date 2022-12-06
 * @since TuesDay; 11:31 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#pragma pack(0)
using namespace std;

class Histogram{
private:
    string line{}, capitalLetters{}, smallLellers{}, numbers{}; 
    const unsigned short int alphabetNumber{26}, decimalBase{10};
    unsigned int perFive {0};
    size_t *smallAlphebet, *capitalAlphabet, *digits;
public:
    Histogram(){
        /*Calloc - by default initialized by zero*/
        smallAlphebet = (size_t*) calloc(alphabetNumber, sizeof(size_t));
        capitalAlphabet = (size_t*) calloc(alphabetNumber, sizeof(size_t));
        digits = (size_t*) calloc(decimalBase, sizeof(size_t));
    }
    void inputLine(void){
        cout<<"Enter a line here: ";
        getline(cin, line);
    }
    void countingFrequencies(void){
        for(auto x: line){
            if(islower(x)){
                smallLellers.push_back(x);
                smallAlphebet[x - 'a']++;
            }else if(isupper(x)){
                capitalLetters.push_back(x);
                capitalAlphabet[x - 'A']++;
            }else if(isdigit(x)){
                numbers.push_back(x);
                digits[x - '0']++;                
            }else{
                continue;
            }
        }
    }
    void smallAlphabetFrequenciesHistogram(void){
        cout<<"\tHistogrm of Small Alphabet: "<<smallLellers<<endl;
        char smallLetter {'a'};
        for(unsigned short int i {0}; i < alphabetNumber; i++){
            cout<<smallLetter++<<"|";
            perFive = 0;
            for(size_t j {1}; j <= *(smallAlphebet + i); j++){
                if(j % 5 == 0){
                    perFive ++;
                    cout<<(perFive * 5);
                }else{
                    cout<<"*";
                }
            }
            if(*(smallAlphebet + i) != 0){
                cout<<"("<<*(smallAlphebet + i)<<")"<<endl;
            }else{
                cout<<endl;
            }
        }
        cout<<endl;
    }
    void capitalAlphabetFrequenciesHistogram(void){
        cout<<"\tHistogrm of Capital Alphabet: "<<capitalLetters<<endl;
        char capitalLetter {'A'};
        for(unsigned short int i {0}; i < alphabetNumber; i++){
            perFive = 0;
            cout<<capitalLetter++<<"|";
            for(size_t j {1}; j <= *(capitalAlphabet + i); j++){
                if(j % 5 == 0){
                    perFive ++;
                    cout<<(perFive * 5);
                }else{
                    cout<<"*";
                }
            }
            if(*(capitalAlphabet + i) != 0){
                cout<<"("<<*(capitalAlphabet + i)<<")"<<endl;
            }else{
                cout<<endl;
            }
        }
        cout<<endl;
    }
    void digitFrequenciesHistogram(void){
        cout<<"\tHistogram of Digit Wise: "<<numbers<<endl;
        char digit {'0'};
        for(unsigned short int i {0}; i < decimalBase; i++){
            perFive = 0;
            cout<<digit++<<"|";
            for(size_t j {1}; j<= *(digits + i); j++){
                if(j % 5 == 0){
                    perFive++;
                    cout<<(perFive * 5);
                }else{
                    cout<<"*";
                }
            }
            if(*(digits + i) != 0){ /*Frequency element*/
                cout<<"("<<*(digits + i)<<")"<<endl;
            }else{
                cout<<endl;
            }
        }
        cout<<endl;
    }
    ~Histogram(){
        free(smallAlphebet), free(capitalAlphabet), free(digits);
    }
};

/*Driver code*/
int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    Histogram histogram;
    histogram.inputLine();
    histogram.countingFrequencies();
    histogram.smallAlphabetFrequenciesHistogram();
    histogram.capitalAlphabetFrequenciesHistogram();
    histogram.digitFrequenciesHistogram();
    system("pause > 0");

    return 0;
}
