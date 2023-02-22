#include "cpr_put.h"

void cpr_put(){
    cpr::Response r = cpr::Put(cpr::Url{"http://www.httpbin.org/put"},
                               cpr::Payload{{"key", "value"}});
    std::cout << r.text << std::endl;
}