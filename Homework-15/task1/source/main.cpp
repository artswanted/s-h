#include "operation.h"

using namespace std;

int main() {
    POINT begin, end, temp;
    string choice;

    cout << "Input \"scalpel\" for start operation" << endl;
    cin >> choice;

    if (choice == "scalpel"s){
        scalpel_start(begin, end);

        while (choice != "suture"s){
            cout << "What's step is next?" << endl;
            cin >> choice;

            if (choice == "scalpel"s){
                cerr << "You're already cutted the patiend. Input another command!" << endl;
            } else if (choice == "hemostat"s) {
                hemostat_start(begin, end, temp);
            } else if (choice == "tweezers"s){
                tweezers_start(begin, end, temp);
            } else if (choice == "suture"s){
                suture_start (begin, end);
            } else {
                cerr << "Wrong input. Try another command!";
            }
        }

    } else {
        cout << "Wrong command!" << endl << "Input \"scalpel\" for start operation" << endl;
    }

    return 0;
}
