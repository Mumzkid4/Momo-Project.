#include <iostream>


using namespace std;

// Default PIN and balance
const string DEFAULT_PIN = "0000";
int balance = 1000;

// Function to check if PIN is correct
bool checkPin(string pin) {
    return pin == DEFAULT_PIN;
}

// Function to reset/change PIN
void resetPin() {
    int oldPin, newPin, confirmPin,DEFAULTPIN;
    cout << "Enter old PIN: ";
    cin >> oldPin;
    if (checkPin) {
        cout << "Enter new PIN: ";
        cin >> newPin;
        cout << "Confirm new PIN: ";
        cin >> confirmPin;

        if (newPin == confirmPin) {
            DEFAULTPIN=newPin;
            cout << "PIN changed successfully!" << endl;
        } else {
            cout << "New PINs do not match. PIN change failed." << endl;
        }
    } else {
        cout << "Incorrect PIN. PIN change failed." << endl;
    }
}

// Function to check balance
void checkBalance() {
    cout << "Your balance is: " << balance << endl;
}

// Function to send money
void sendMoney() {
    string recipient;
    int amount;
    cout << "Enter recipient's phone number: ";
    cin >> recipient;
    cout << "Enter amount to send: ";

    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance. Transaction failed." << endl;
    } else {
        balance -= amount;
        cout << "Sent " << amount << " to " << recipient << " successfully!" << endl;
        cout << "New balance is: " << balance << endl;
    }
}

int main() {
    string pin;
    int attempts = 0;
    bool loggedIn = false;
    
    while (!loggedIn && attempts < 3) {
        cout << "Enter PIN: ";
        cin >> pin;
        if (checkPin(pin)) {
            cout << "Logged in successfully!" << endl;
            loggedIn = true;
        } else {
            cout << "Incorrect PIN. Please try again." << 

endl;
            attempts++;
        }
    }
    
    if (loggedIn) {
        int choice;
        do {
            cout << endl;
            cout << "Please choose an option:" << endl;
            cout << "1. Reset/change PIN" << endl;
            cout << "2. Check balance" << endl;
            cout << "3. Send money" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    resetPin();
                    break;
                case 2:
                    checkBalance();
                    break;
                case 3:
                    sendMoney();
                    break;

                case 4:
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
                    break;
            }
        } while (choice != 4);
    } else {
        cout << "You have exceeded the maximum number of attempts. Program will now exit." << endl;
    }
    
    return 0;
}

