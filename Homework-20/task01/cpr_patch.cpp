#include "cpr_patch.h"

void cpr_patch(){
    cpr::Response r = cpr::Patch(cpr::Url{"http://www.httpbin.org/patch"},
                                 cpr::Payload{{"key", "value"}});
    std::cout << r.text << std::endl;
}