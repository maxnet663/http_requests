#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    std::string command;
    
    while (command != "exit") {
        std::cout << "Enter a command:" << std::endl;
        std::cin >> command;
        if (command == "get") 
            std::cout << cpr::Get(cpr::Url("http://httpbin.org/get")).text << std::endl;
        if (command == "post") 
            std::cout << cpr::Post(cpr::Url("http://httpbin.org/get")).text << std::endl;
        if (command == "put")
            std::cout << cpr::Put(cpr::Url("http://httpbin.org/get")).text << std::endl;
        if (command == "delete")
            std::cout << cpr::Delete(cpr::Url("http://httpbin.org/get")).text << std::endl;
        if (command == "patch")
            std::cout << cpr::Patch(cpr::Url("http://httpbin.org/get")).text << std::endl;
    }
    return 0;
}

