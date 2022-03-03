#include <iostream>
#include <fstream>
#include <cstdbool>
using namespace std;

class User {
    private:
        string firstName, lastName, password;
    public:
        //setter
        void setFirstName ();
        void setLastName ();
        void setPassword ();
        void setFile();
        //getter
        void getFile ();
        string getFullName ();
        string getPassword ();
};
void presentation(int &);
int main () {
    int choice;
    bool loop = 1;

    while (loop) {
        presentation(choice);

        if (choice == 0) exit(0);
        else if (choice == 1) {
            User newUser;
            newUser.setFirstName();
            newUser.setLastName();
            newUser.setPassword();
            newUser.setFile();
        }
        else if (choice == 2) {
            User logIn;
            logIn.getFile();
        }
        else {
            cout<< "enter a correct choice !!!"<< endl;
        }
    }
}
void presentation (int &choice) {
    cout<< "0.quit"<< endl;
    cout<< "1.new account"<< endl;
    cout<< "2.log in"<< endl;
    cout<< "enter your choice: "; cin>> choice;
}
/*setter*/
void User::setFirstName () {
    cout<< "enter your first name: "; cin>> firstName;
}
void User::setLastName () {
    cout<< "enter your last name: "; cin>> lastName;
}
void User::setPassword () {
    cout<< "enter your password: "; cin>> password;
}
void User::setFile () {
    fstream fout(getFullName(), ios::out);
    fout<< getFullName()<< endl;
    fout<< getPassword()<< endl;
}
/*getter*/
void User::getFile () {
    int counter = 0, check = 0;
    string str, testpassword;
    setFirstName();
    setLastName();
    fstream fin(getFullName(), ios::in);
    cout<< "enter your password: "; cin>> testpassword;
    while (fin>> str) {
        counter++;
        if (counter == 3) {
            if (testpassword == str) {
                check = 1;
            }
        }
    }
    if (check == 1) cout<< "Welcome to your account, "<< getFullName()<< endl;
    else cout<< "check if your informations are correct!!!"<< endl;
}
string User::getFullName () {
    return (firstName + " " + lastName);
}
string User::getPassword () {
    return password;
}