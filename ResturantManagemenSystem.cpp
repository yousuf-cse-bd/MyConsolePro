/**
 * @file ResturantManagemenSystem.cpp
 * @author Md. Yousuf Ali (yousuf.cse@gmail.com)
 * @brief Project: Resturant Managemen System in Console
 * @version 0.1
 * @date 2022-08-28
 * @since SunDay; 05: 27 PM
 * @copyright Copyright (c) 2022
 * Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <conio.h>
using namespace std;

int choice;

int main(int argc, char const *argv[]){
    system("cls");
    int q;
    //purchase variables
    int purchasePizza, purchaseBurger, purchaseSandwich, purcharseIcecream, purchaseCake;
    purchasePizza = purchaseBurger = purchaseSandwich = purcharseIcecream = purchaseCake = 0;

    //selling variables
    int salesPizza, salesBurger, salesSandwich, salesIcecream, salesCake;
    salesPizza = salesBurger = salesSandwich = salesIcecream = salesCake = 0;
    //Total Prices
    int profitPizza, profitBurger, profitSandwich, profitIcecream, profitCake;
    profitPizza = profitBurger = profitSandwich = profitIcecream = profitCake = 0;
    int pizza, burger, sandwich, icecream, cake;
    pizza = burger = sandwich = icecream = cake = 0;
    //Purchase Items Menu
    cout << "\n\t\t\t*****Purchase Items*****"<<endl;
    cout << "\nNumber of Pizza: ";
    cin >> purchasePizza;
    cout << "\nNumber of Burger: ";
    cin >> purchaseBurger;
    cout << "\nNumber of Sandwich: ";
    cin >> purchaseSandwich;
    cout << "\nNumber of Ice-Cream: ";
    cin >> purcharseIcecream;
    cout << "\nNumber of Cake: ";
    cin >> purchaseCake;
    repeat:
    system("cls");

    //Control Panel
    cout << "\n\t\t\t#####Control Panel#####"<<endl;
    cout << "1. Pizza"<<endl;
    cout << "2. Burger"<<endl;
    cout << "3. Sandwich"<<endl;
    cout << "4. Ice-Cream"<<endl;
    cout << "5. Cake"<<endl;
    cout << "6. Details"<<endl;
    cout << "0. EXIT..!"<<endl;
    cout << "\n\nEnter Your Choise: ";
    cin >> choice;
    switch (choice){
    case 1:
        cout << "\nEnter Pizza Quantity: ";
        cin >> q;
        if (purchasePizza - salesPizza >= q){
            salesPizza += q;
            profitPizza += q * 700;
            cout << "\n\n\n\t\t\t" << q << " Pizza Sales Thank You!!!";
        }
        else{
            cout << "\n\n\n\t\t\tSorry " << purchasePizza - salesPizza << " Pizza Remainig in Resturant." << endl;
        }
        break;
    case 2:
        cout << "\nEnter Burger Quantity: ";
        cin >> q;
        if (purchaseBurger - salesBurger >= q){
            salesBurger += q;
            burger += q * 700;
            cout << "\n\n\n\t\t\t" << q << " Burger Sales Thank You!!!";
        }
        else{
            cout << "\n\n\n\t\t\tSorry " << purchaseBurger - salesBurger << " Burger Remainig in Resturant." << endl;
        }
        break;
    case 3:
        cout << "\nEnter Sandwitch Quantity: ";
        cin >> q;
        if (purchaseSandwich - salesSandwich >= q){
            salesSandwich += q;
            sandwich += q * 700;
            cout << "\n\n\n\t\t\t" << q << " Sandwitch Sales Thank You!!!";
        }
        else{
            cout << "\n\n\n\t\t\tSorry " << purchaseSandwich - salesSandwich << " Sandwich Remainig in Resturant." << endl;
        }
        break;
    case 4:
        cout << "\nEnter Ice-Cream Quantity: ";
        cin >> q;
        if (purcharseIcecream - salesIcecream >= q){
            salesIcecream += q;
            icecream += q * 700;
            cout << "\n\n\n\t\t\t" << q << " Ice-Cream Sales Thank You!!!";
        }
        else{
            cout << "\n\n\n\t\t\tSorry " << purcharseIcecream - salesIcecream << " Ice-Cream Remainig in Resturant." << endl;
        }
        break;
    case 5:
        cout << "\nEnter Cake Quantity: ";
        cin >> q;
        if (purchaseCake - salesCake >= q){
            salesCake += q;
            cake += q * 700;
            cout << "\n\n\n\t\t\t" << q << " Cake Sales Thank You!!!";
        }
        else{
            cout << "\n\n\n\t\t\tSorry " << purchaseCake - salesCake << " Cake Remainig in Resturant." << endl;
        }
        break;
    case 6:
        system("cls");
        cout<<"\n\t\t%%%%%Details Panel%%%%%"<<endl;
        cout<<" Purchase Pizza Quantity: "<<purchasePizza<<endl;
        cout<<" Salaes Pizza Quantity: "<<salesPizza<<endl;
        cout<<" Remaining Pizza Quantity: "<<purchasePizza - salesPizza<<endl;
        cout<<" Total Pizza Price in a Day: "<<profitPizza<<endl;

        cout<<"\n Purchase Burger Quantity: "<<purchaseBurger<<endl;
        cout<<" Sales Burger Quantity: "<<salesBurger<<endl;
        cout<<" Remaining Burger Quantity: "<<purchaseBurger - salesBurger<<endl;
        cout<<" Total Burger Price in a Day: "<<profitBurger<<endl;

        cout<<"\n Purchase Sandwich Quantity: "<<purchaseSandwich<<endl;
        cout<<" Sales Sandwich Quantity: "<<salesSandwich<<endl;
        cout<<" Remaining Sandwich Quantity: "<<purchaseSandwich - salesSandwich<<endl;
        cout<<" Total Sandwich Price in a Day: "<<profitSandwich<<endl;

        cout<<"\n Purchase Ice-Cream Quantity: "<<purcharseIcecream<<endl;
        cout<<" Sales Ice-Cream Quantity: "<<salesIcecream<<endl;
        cout<<" Remaining Ice-Cream Quantity: "<<purcharseIcecream - salesIcecream<<endl;
        cout<<" Total Ice-Cream Price in a Day: "<<profitIcecream<<endl;

        cout<<"\n Purchase Cake Quantity: "<<purchaseCake<<endl;
        cout<<" Sales Cake Quantity: "<<salesCake<<endl;
        cout<<" Remaining Cake Quantity: "<<purchaseCake - salesCake<<endl;
        cout<<" Total Cake Price in a Day: "<<profitCake<<endl;

        cout<<"\n\n Total Day Price: "<<profitBurger + profitPizza + profitCake + profitIcecream + profitSandwich<<endl;

        break;
    case 0:
        exit(0); //return 0;

    default:
        cout << "Invalid Value...Please Try Again...!"<<endl;
    }
    getch();
    goto repeat;
  
    return 0;
}
