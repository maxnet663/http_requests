#include <iostream>
#include <cpr/cpr.h>
#include <string>

std::string find_header(std::string *s) {
    int beginHeader = s->find("<h1>");
    int endHeader = s->find("</h1>", beginHeader);

    return beginHeader == s->npos || endHeader == s->npos ?
        "" : s->substr(beginHeader + 4, endHeader - beginHeader - 4);
}

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"), 
            cpr::Header({{"Accept", "text/html"}}));
    std::cout << r.text << std::endl;
    std::cout <<"The header is:" << std::endl << find_header(&r.text) << std::endl;

    return 0;
}
