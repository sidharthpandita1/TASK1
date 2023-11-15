#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100

    int guess;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100. Try to guess it!" << endl;

    while (true) {
        cout << "Enter your guess: ";
        if (!(cin >> guess)) {
            cout << "Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        if (guess == secretNumber) {
            cout << "Congratulations! You've guessed the correct number!" << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try a higher number." << endl;
        } else {
            cout << "Too high! Try a lower number." << endl;
        }
    }

    return 0;
}