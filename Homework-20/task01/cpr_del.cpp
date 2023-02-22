#include "cpr_del.h"

void cpr_del(){
    cpr::Response delete_response = cpr::Delete(cpr::Url{"http://www.httpbin.org/delete"});
    std::cout << delete_response.text << std::endl;
}