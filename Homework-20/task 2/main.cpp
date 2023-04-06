#include <iostream>
#include <cpr/cpr.h>

int main() {
    auto r = cpr::Get(cpr::Url{"https://httpbin.org/html"}, cpr::Header{{"accept", "text/html"}});
    if (r.status_code == 200) {
        std::string html = r.text;
        size_t start_pos = html.find("<h1>") + 4;
        size_t end_pos = html.find("</h1>", start_pos);
        std::string header = html.substr(start_pos, end_pos - start_pos);
        std::cout << "Header: " << header << std::endl;
    } else {
        std::cerr << "Error: " << r.status_code << std::endl;
    }
    return 0;
}
