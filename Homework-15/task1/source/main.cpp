#include "operation.h"

using namespace std;

int main() {
    POINT begin, end, temp;
    string choice;

    print_message(WELCOME);
    cin >> choice;

    if (choice == "scalpel"s){
        scalpel_start(begin, end);

        while (choice != "suture"s){
            print_message(NEXT_STEP);
            cin >> choice;

            if (choice == "scalpel"s){
                print_message(ALREADY_STARTED);
            } else if (choice == "hemostat"s) {
                hemostat_start(begin, end, temp);
            } else if (choice == "tweezers"s){
                tweezers_start(begin, end, temp);
            } else if (choice == "suture"s){
                suture_start (begin, end);
            } else {
                print_message(WRONG_INPUT);
            }
        }

    } else {
        print_message(WRONG_START);
    }

    return 0;
}
