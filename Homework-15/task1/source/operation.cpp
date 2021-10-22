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
}

void tweezers_start (POINT& begin, POINT& end, POINT& temp){

}

void suture_start (POINT& begin, POINT& end){

}