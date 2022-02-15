#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
    ofstream moneyFile("money.txt");
    moneyFile << "1000";
    moneyFile.close();

    int money;
    ifstream readMoney("money.txt");
    readMoney >> money;
    cout << money;
    remove("money.txt");

    string userName;
    srand((unsigned)time(0));
    int randomNumber;
    randomNumber = (rand() % 10) + 1;
    int accountId;
    accountId = (rand() % 100000) + 1;
    int bidAmount;
    int guess;

    cout << "===================================================\n";
    cout << "  CCCC      A      SSSSS  IIIII  NN    N    OOO    \n";
    cout << " C         A A     S        I    N N   N   O    O  \n";
    cout << " C        A   A    SSSSS    I    N  N  N   O    O  \n";
    cout << " C       AAAAAAA       S    I    N   N N   O    O  \n";
    cout << "  CCCC  A       A  SSSSS  IIIII  N    NN     OO    \n";
    cout << "===================================================\n\n\n";

    cout << "Please enter your name: ";
    getline(cin, userName);
    cout << "\n\n";

    cout << "===================\n";
    cout << "BANK ACCOUNT\n\n";
    cout << "Name: " + userName + "\n";
    cout << "Account No: " << accountId << "\n";
    cout << "Money: " << money << "$\n\n";
    cout << "===================\n\n"; 
    Sleep(4000);


    do {
        cout << "Welcome to the casino, " << userName << "! Let's get started!\n\n";

        cout << "========================\n";
        cout << "                        \n";
        cout << "   RULES OF THE GAME    \n";
        cout << "   You bet on a number  \n";
        cout << "  between 1 and 10, and \n";
        cout << " if you bet on the wrong\n";
        cout << "number, you lose it all,\n";
        cout << "  if you bet correctly, \n";
        cout << " you win 10x the money. \n";
        cout << "        Good Luck!      \n";
        cout << "                        \n";
        cout << "========================\n\n\n";
        cout << "How much money do you want to bid? ";
        cin >> bidAmount;
        money = money - bidAmount;

        if (bidAmount > money + 1) {
            cout << "\nYou do not have enough money to bid that amount! Try again: \n\n";
            cout << "How much money do you want to bid? ";
            cin >> bidAmount;
        }
        cout << "\nWhat number are you betting on? ";
        cin >> guess;
        if (guess > 10 || guess < 0) {
            cout << "\nInvalid number, please pick one between 1 and 10. What number are you betting on? ";
            cin >> guess;
        }
        cout << "Your bet: " << bidAmount << "\n";
        cout << "Your number: " << guess << "\n\n";
        Sleep(4000);

        cout << "The number is: " << randomNumber << "\n";
        cout << "Your number: " << guess << "\n\n";
        if (randomNumber == guess) {
            cout << "CONGRATS!\n";
            cout << "You were correct!\n";
            cout << "You just won " << bidAmount * 10 << "$!\n";
            money = money + bidAmount * 10;
        }
        else {
            cout << "YOU LOST!\n";
            cout << "You bet the wrong number!\n";
            cout << "You just lost " << bidAmount << "$!\n";
        }
        if (money <= 0) {
            string playAgain;
            cout << "\nYou are out of money! Would you like to play again and start with $1000 again? (Y/N) ";
            cin >> playAgain;
            if (playAgain == "N" || playAgain == "n") {
                cout << "\nYou have chosen to not play another round. Thank you for playing!";
                return 0;
            }
            if (playAgain == "Y" || playAgain == "y") {
                cout << "\nNew round starting...\n\n\n\n"; 
                money = 1000;
                Sleep(2000);
            }
        }
    } while (money > 0);
    return 0;

}