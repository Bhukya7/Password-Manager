#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class PasswordManager {
private:
    map<string, string> passwords;

public:
    void addPassword(const string& website, const string& password) {
        passwords[website] = password;
        cout << "Password added successfully :)\n";
    }

    void displayPasswords() const {
        if (passwords.empty()) {
            cout << "No passwords stored.\n";
        } else {
            cout << setw(15) << left << "Website" << "Password\n";
            cout << string(25, '-') << endl;

            for (const auto& entry : passwords) {
                cout << setw(15) << left << entry.first << entry.second << endl;
            }
        }
    }
};

int main() {
    PasswordManager passwordManager;
    char choice;

    do {
        cout << "Password Manager:\n";
        cout << "1. Add Password\n";
        cout << "2. Display Passwords\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string website, password;
                cout << "Enter the website: ";
                cin >> website;
                cout << "Enter the password: ";
                cin >> password;
                passwordManager.addPassword(website, password);
                break;
            }
            case '2':
                passwordManager.displayPasswords();
                break;
            case '3':
                cout << "Exiting the Password Manager. Have a nice day!\n";
                break;
            default:
                cout << "Invalid choice. Please try again :(\n";
        }
    } while (choice != '3');

    return 0;
}