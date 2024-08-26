#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    while (true)
    {
        double num1, num2;
        int operation;

        cout << "\nPlease enter your operation from the list down below:\n";
        cout << "1: Sum\n2: Subtraction\n3: Multiplication\n4: Division\n5: Square Root\n\n6: EXIT" << endl;

        cout << "-> ";
        cin >> operation;

        if (operation != 6) {
            cout << "\nPlease enter the first number.\n";
            cout << "-> ";
            cin >> num1;

            if (operation == 5) {
                cout << "\nResult is: " << sqrt(num1) << endl;
            }
            else {
                cout << "\nPlease enter the second number.\n";
                cout << "-> ";
                cin >> num2;

                switch (operation)
                {
                    case 1:
                        cout << "\nResult is: " << num1 + num2 << endl;
                        break;

                    case 2:
                        cout << "\nResult is: " << num1 - num2 << endl;
                        break;

                    case 3:
                        cout << "\nResult is: " << num1 * num2 << endl;
                        break;

                    case 4:
                        cout << "\nResult is: " << num1 / num2 << endl;
                        break;

                    default:
                        cout << "\nWrong operation.\n";
                        break;
                }
            }
        }
        else {
            return 0;
        }
    }
}
