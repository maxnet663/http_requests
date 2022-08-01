#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <vector>

void make_pairs(const std::vector<std::string> &vecArgs, std::vector<cpr::Pair> &vecPairs) {

    for (int i = 0; i < vecArgs.size() - 1; i += 2) {
        if (vecArgs[i] != "post" && vecArgs[i + 1] != "post")
            vecPairs.push_back({vecArgs[i], vecArgs[i + 1]});
        else
            break;
    }
}

std::string add_arguments(const std::vector<std::string> &v) {
    std::string res = "?";
    for (int i = 0; i < v.size() - 1; i += 2) {
        if (v[i] != "get" && v[i + 1] != "get")
            res += v[i] + '=' + v[i + 1] + '&';
        else
            break;
    }
    return res;
}

int main() {
    std::string arg;
    std::vector<std::string> arguments;
    while (arg != "post" && arg != "get") {
        std::cout << "Input:" << std::endl;
        std::cin >> arg;
        arguments.push_back(arg);
    }

    if (arg == "post") {
        std::vector<cpr::Pair> postArgs;
        make_pairs(arguments, postArgs);
        cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                    cpr::Payload(postArgs.begin(), postArgs.end()),
                                    cpr::Header{{"accept", "application/json"}});
        std::cout << r.text << std::endl;
    }

    if (arg == "get") {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get" + add_arguments(arguments)),
                                   cpr::Header{{"accept", "application/json"}});
        std::cout << r.text << std::endl;
    }

    return 0;
}

