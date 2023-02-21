#include "gpr_post.h"

void cpr_post(){
    cpr::Response r = cpr::Post(cpr::Url{"http://www.httpbin.org/post"},
                                cpr::Payload{{"key", "value"}});
    std::cout << r.text << std::endl;
}