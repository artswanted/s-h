#include <iostream>
#include <cpr/cpr.h>
#include "cpr_get.h"
#include "cpr_put.h"
#include "cpr_patch.h"
#include "cpr_del.h"
#include "gpr_post.h"

int iUserChoice (){
    int choice;
    std::cout << "Make your choice\n1.Get\n2.Post\n3.Put\n4.Delete\n5.Patch\n6.Exit" << std::endl;
    std::cin >> choice;
    do {
        if(choice >= 1 && choice<=6){
            return choice;
        }
    }while(true);
}

int main() {
    int choice = iUserChoice();
    switch (choice) {
        case 1:
        {
            cpr_get();
        }break;
        case 2:
        {

        }break;
        case 3:
        {

        }break;
        case 4:
        {

        }break;
        case 5:
        {

        }break;
        case 6:
        {
            //
        }break;
        default:
        {
            //
        }break;
    }
    return 0;
}
