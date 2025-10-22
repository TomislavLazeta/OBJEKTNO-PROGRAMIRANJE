#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string string;
    std::cout << "Unesi string: ";
    std::getline(std::cin, string);

    for (char& znak : string) {
        if (std::isalpha(znak))
            znak = std::toupper(znak);
        else if (std::isdigit(znak))
            znak = '*';
        else if (znak == ' ' || znak == '\t')
            znak = '_';
    }

    std::cout << "Rezultat: " << string << std::endl;
}
