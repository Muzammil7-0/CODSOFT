

#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

void ReverseGuessingGame();

int main()
{
    char name[30];
    char no, again;
    int choice, secretNumber;
    int min, max;
    const int num_of_guess = 10;
    int player_guess[num_of_guess];
    int total_guess;

    cout << "Enter your name: ";
    cin.getline(name, 30);
    while (true)
    {
        cout << "\nIs your name: " << name << " ? (y/n)\n";
        cin >> no;
        if ((no != 'y') && (no != 'Y') && (no != 'N') && (no != 'n'))
        {
            cout << "Please enter y or n only. ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (no == 'n' || no == 'N')
        {
            cout << "Enter your name: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin.getline(name, 20);
        }
        else
            break;
    }
    while (true)
    {
        system("cls");
        cout << "Welcome to the Guessing Game, " << name << "!" << endl;
        cout << "\nChoose an option: \n";
        cout << "1. Guessing Game\n"
             << "2. Reverse Guessing Game\n"
             << "3. Exit\n";
        cin >> choice;
        if (choice == 3)
        {
            cout << "\nThank you for playing, " << name << ". Goodbye!\n";
            break;
        }
        else if (choice == 1)
        {
            while (true)
            {
                bool badInput = true;
                system("cls");
                do
                {
                    cout << "Enter the minimum value: ";
                    cin >> min;
                    if (badInput = cin.fail() || (min < 0))
                    {
                        cout << "Please enter a positive number.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (badInput);
                do
                {
                    cout << "\nEnter the maximum value: ";
                    cin >> max;
                    if (badInput = cin.fail() || (max <= min))
                    {
                        cout << "Enter a number greater than " << min << ".\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (badInput);
                srand(time(NULL));
                secretNumber = rand() % (max - min + 1) + min;
                system("cls");
                cout << "You have 10 tries to guess the number. Good luck, " << name << "!\n";
                for (total_guess = 0; total_guess < num_of_guess; total_guess++)
                {
                    cout << "Attempt #" << total_guess + 1 << ": ";
                    cin >> player_guess[total_guess];
                    if (cin.fail())
                    {
                        cout << "Please enter a number between " << min << " and " << max << ".\n";
                        total_guess--;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else if ((player_guess[total_guess] < min) || (player_guess[total_guess] > max))
                    {
                        cout << "Please enter a number between " << min << " and " << max << ".\n";
                        total_guess--;
                    }
                    else if (player_guess[total_guess] < secretNumber)
                    {
                        cout << "Too low, try again.\n";
                    }
                    else if (player_guess[total_guess] > secretNumber)
                    {
                        cout << "Too high, try again.\n";
                    }
                    else
                    {
                        cout << "Congratulations! You guessed the number " << secretNumber << " in " << total_guess + 1 << " tries.\n";
                        cout << "Your guesses were: ";
                        for (int j = 0; j <= total_guess; j++)
                        {
                            cout << player_guess[j] << " ";
                        }
                        cout << endl;
                        break;
                    }
                }
                if (total_guess == num_of_guess)
                {
                    cout << "Sorry, you've used all your guesses. The number was " << secretNumber << ".\n";
                    cout << "Your guesses were: ";
                    for (int j = 0; j < num_of_guess; j++)
                    {
                        cout << player_guess[j] << " ";
                    }
                    cout << endl;
                }
                cout << "Would you like to play again? (y/n) ";
                cin >> again;
                if ((again != 'y') && (again != 'Y'))
                {
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            ReverseGuessingGame();
        }
    }
    return 0;
}

void ReverseGuessingGame()
{
    int myNumber = 0;
    char HighOrLow, again;
    int maxNum = 0;
    int minNum = 0;
    int computerguess, max_allowed_guesses = 10;
    int i = 0;
    bool badInput = true;
    do
    {
        do
        {
            cout << "Enter the minimum value: ";
            cin >> minNum;
            if (badInput = cin.fail() || (minNum < 0))
            {
                cout << "Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (badInput);
        do
        {
            cout << "\nEnter the maximum value: ";
            cin >> maxNum;
            if (badInput = cin.fail() || (maxNum <= minNum))
            {
                cout << "Enter a number greater than " << minNum << ".\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (badInput);
        cout << "Enter your number between " << minNum << " and " << maxNum << ": ";
        cin >> myNumber;
        while ((myNumber < minNum) || (myNumber > maxNum))
        {
            cout << "Enter your number between " << minNum << " and " << maxNum << ": ";
            cin >> myNumber;
        }
        do
        {
            i++;
            srand(time(NULL));
            computerguess = rand() % (maxNum - minNum + 1) + minNum;

            if (computerguess == myNumber)
            {
                cout << "The computer guessed your number " << myNumber << " correctly!\n";
                break;
            }

            cout << "Is " << computerguess << " too high (h) or too low (l)? ";
            cin >> HighOrLow;

            if ((HighOrLow == 'h') || (HighOrLow == 'H'))
            {
                maxNum = computerguess;
            }
            else if ((HighOrLow == 'l') || (HighOrLow == 'L'))
            {
                minNum = computerguess;
            }
        } while (computerguess != myNumber && i < max_allowed_guesses);

        if (computerguess != myNumber)
        {
            cout << "The computer couldn't guess your number in " << max_allowed_guesses << " tries.\n";
        }
        cout << "Would you like to play again? (y/n) ";
        cin >> again;
    } while ((again == 'y') || (again == 'Y'));
    system("pause");
}
