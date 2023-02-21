#include "cpr_get.h"

void cpr_get(){
    cpr::Response rGet = cpr::Get(cpr::Url("http://httpbin.org/get"));
    std::cout << rGet.text;
}
