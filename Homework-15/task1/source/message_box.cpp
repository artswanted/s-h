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
        case SCALPEL_FIRST:{
            cout << "Enter coordinates for first point:" << endl;
        } break;
        case SCALPEL_SECOND:{
            cout << "Enter coordinates for finish point" << endl;
        } break;
        case HEMOSTAT_START:{
            cout << "Enter X and Y where you need place hemostat:" << endl;
        } break;
        case HEMOSTAT_ERROR:{
            cout << "You cannot place hemostat here!" << endl << "Input new coordinates:" << endl;
        } break;
        default:{
            cerr << "Unauthorized command!" << endl;
        } break;
    }
}

void print_message_advance(int iType, double x, double y){
    switch (iType) {
        case SCALPEL_CUT_1:{
            cout << "Operation is started with first point. X:" << x << ", Y:" << y << endl;
        }break;
        case SCALPEL_CUT_2:{
            cout << "Second operation point. X:" << x << ", Y:" << y << endl;
        }break;
        case HEMOSTAT_CUT:{
            cout << "Hemostat is located: X:" << x << ", Y:" << y << endl;
        }break;
        case TWEEZERS_CUT:{
            cout << "Tweezers is applied: X:" << x << ", Y:" << y << endl;
        }break;
        default:{
            cerr << "Unauthorized command!" << endl;
        } break;
    }
}