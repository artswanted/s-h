#include "operation.h"

void scalpel_start (POINT& begin, POINT& end){
    print_message(SCALPEL_FIRST);
    cin >> begin.x >> begin.y;
    print_message(SCALPEL_SECOND);
    cin >> end.x >> end.y;
    print_message_advance(SCALPEL_CUT_1, begin.x, begin.y);
    print_message_advance(SCALPEL_CUT_2, end.x, end.y);
}

void hemostat_start (POINT& begin, POINT& end, POINT& temp){
    print_message(HEMOSTAT_START);
    cin >> temp.x >> temp.y;
    while ((end.y - begin.y)/(end.x - begin.y) !=
            (temp.y - begin.y)/(temp.x - begin.y)){
        print_message(HEMOSTAT_ERROR);
        cin >> temp.x >> temp.y;
    }
    print_message_advance(HEMOSTAT_ERROR, temp.x, temp.y);
}

void tweezers_start (POINT& begin, POINT& end, POINT& temp){
    print_message(TWEEZERS_START);
    cin >> temp.x >> temp.y;
    while ((end.y - begin.y)/(end.x - begin.y) !=
           (temp.y - begin.y)/(temp.x - begin.y)){
        print_message(TWEEZERS_ERROR);
        cin >> temp.x >> temp.y;
    }
    print_message_advance(TWEEZERS_ERROR, temp.x, temp.y);
}

void suture_start (POINT& begin, POINT& end){

}