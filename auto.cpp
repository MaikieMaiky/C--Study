#include <iostream>
#include <string>
#include <vector>

std::string GetName() { return "Alex"; }

void HelloWorld() { std::cout << "Hello World" << std::endl; }


int main()
{
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");
    // for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it)
    for (auto it = strings.begin(); it != strings.end(); ++it) { std::cout << *it << std::endl; }
    for (std::string it : strings) { std::cout << it << std::endl; }
    auto helloworld = HelloWorld;
    helloworld();
}