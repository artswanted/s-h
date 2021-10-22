//
// Created by dmytro on 22.10.2021.
//
#include "message_box.h"

void print_message(int iType){
    switch (iType) {
        case WRONG_START:{
            cerr << "Wrong command!" << endl << "Input \"scalpel\" for start operation" << endl;
        } break;
        case WRONG_INPUT:{
            cerr << "Wrong input. Try another command!";
        } break;
        case ALREADY_STARTED:{
            cerr << "You're already cutted the patiend. Input another command!" << endl;
        } break;
        case NEXT_STEP:{
            cout << "What's step is next?" << endl;
        } break;
        case WELCOME:{
            cout << "Input \"scalpel\" for start operation" << endl;
        } break;
        default:{
            cerr << "Unauthorized command!" << endl;
        }
    }
}
