#include <iostream>
#include <fstream>
using namespace std;

// Function Prototypes
void biometricLogin();
void otpLogin();
void atmMenu();
void checkBalance(int balance);
void withdrawCash(int *balance);
void transferMoney(int *balance);
void changePin(int *pin);
void saveReceipt(int balance);

// MAIN FUNCTION
int main()
{
    int pin = 1234;          // Default PIN
    int enteredPin;
    int balance = 600000;    // Default balance
    int choice;

    cout << "----- WELCOME TO ATM -----\n";

    // Simulated Biometric Login
    biometricLogin();

    // PIN Login
    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (enteredPin != pin)
    {
        cout << "Wrong PIN! Access Denied.\n";
        return 0;
    }

    // OTP Based Cardless Transaction (Simulated)
    otpLogin();

    // ATM Menu Loop
    do
    {
        atmMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            checkBalance(balance);
            break;

        case 2:
            withdrawCash(&balance);
            break;

        case 3:
            transferMoney(&balance);
            break;

        case 4:
            changePin(&pin);
            break;

        case 5:
            saveReceipt(balance);
            cout << "Thank you for using ATM.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}

// ---------------- FUNCTIONS ----------------

// Simulated Biometric Login
void biometricLogin()
{
    cout << "Biometric Scan Successful (Simulated)\n";
}

// Simulated OTP Login
void otpLogin()
{
    int otp = 1111;
    int enteredOtp;

    cout << "Enter OTP (1111): ";
    cin >> enteredOtp;

    if (enteredOtp == otp)
        cout << "OTP Verified Successfully\n";
    else
    {
        cout << "Wrong OTP! Transaction Cancelled.\n";
        exit(0);
    }
}

// ATM Menu
void atmMenu()
{
    cout << "\n----- ATM MENU -----\n";
    cout << "1. Check Balance\n";
    cout << "2. Withdraw Cash\n";
    cout << "3. Transfer Money\n";
    cout << "4. Change PIN\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Check Balance
void checkBalance(int balance)
{
    cout << "Your Balance is: " << balance << endl;
}

// Withdraw Cash
void withdrawCash(int *balance)
{
    int amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= *balance)
    {
        *balance -= amount;
        cout << "Please collect your cash.\n";
    }
    else
        cout << "Insufficient Balance!\n";
}

// Transfer Money
void transferMoney(int *balance)
{
    int amount;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    if (amount <= *balance)
    {
        *balance -= amount;
        cout << "Money transferred successfully.\n";
    }
    else
        cout << "Insufficient Balance!\n";
}

// Change PIN
void changePin(int *pin)
{
    int newPin;
    cout << "Enter new PIN: ";
    cin >> newPin;
    *pin = newPin;
    cout << "PIN changed successfully.\n";
}

// Digital Receipt using File Handling
void saveReceipt(int balance)
{
    ofstream file("ATM_Receipt.txt");

    file << "----- ATM DIGITAL RECEIPT -----\n";
    file << "Remaining Balance: " << balance << endl;
    file << "Thank you for using ATM\n";

    file.close();
}

	
	
