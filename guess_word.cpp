#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    srand(time(0));
    cout << "\t\tThe guessing word game" << endl;
    vector<pair<string, string>> words = {
        {"chamomile", "A flower with a yellow centre and white petals"},
        {"rain", "It falls from the sky and helps plants grow"},
        {"penguin", "A bird that cannot fly and lives in Antarctica"},
        {"honey", "The golden liquid produced by beetles"},
        {"food", "What people use to replenish their energy"}
    };

    int random = rand() % words.size();
    string word = words[random].first;
    string hint = words[random].second;
    string guessword(word.length(), '*');

    int ushint = 0;
    bool isgues = false;
    Sleep(1000);
    cout << "The quession is: ";
    setColor(10);
    cout << hint << endl;
    setColor(7);
    Sleep(1000);
    cout << "Word: ";
    cout << guessword << endl;
    
    while (!isgues) {
        cout << "Choose the option: \n1) Try guess all word\n2) Try gues a one letter\n3) Use a hint\n";
        int choice;
        cin >> choice;
        
        switch (choice)
        {
        case 1: {
            string guesetall;
            cout << "Enter the guess for word: ";
            cin >> guesetall;
            if (guesetall == word) {
                isgues = true;
                setColor(10);
                cout << "Attention!!!"<<endl;
                setColor(7);
                Sleep(1000);
                cout << "You guess the word: " << word << endl;
            }
            else {
                setColor(10);
                cout << "Attention!!!" << endl;
                setColor(7);
                Sleep(1000);
                cout << "Incorrect guess. Try again!" << endl;
            }
            break;
        }
        case 2: {
            char letter;
            cout << "Enter a letter: ";
            cin >> letter;
            bool found = false;

            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] == letter && guessword[i] == '*') {
                    guessword[i] = letter;
                    found = true;
                }
            }

            if (found) {
                cout << "Good job! Current word: " << guessword << endl;
            }
            else {
                cout << "The letter is not in the word. Try again!\n";
            }

            if (guessword == word) {
                isgues = true;
                cout << "Congratulations! You completed the word: " << word << endl;
            }
            break;
        }
        case 3: {
            ushint++;
            bool hintUsed = false;

            for (size_t i = 0; i < word.length(); ++i) {
                if (guessword[i] == '*') {
                    guessword[i] = word[i];
                    hintUsed = true;
                    break;
                }
            }

            if (hintUsed) {
                cout << "Hint used! Current word: " << guessword << endl;
            }
            else {
                cout << "No more hints available!" << endl;
            }
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

