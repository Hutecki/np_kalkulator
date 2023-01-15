#include <iostream>
#include <vector>
#include <string>
#include "number.h"

std::vector<std::pair<std::string, NumberOperation>> OPERATIONS;


void display_user_interface() {
    std::cout << 
        "Witaj użytkowniku\n"
        "Masz do wyboru "
        << OPERATIONS.size()
        << " operacje\n";

    for (size_t i = 0; i < OPERATIONS.size(); i++) {
        std::cout << i + 1
            << ". "
            << OPERATIONS[i].first
            << "\n";
    }
}

int main(int argc, char* argv[]) {
    display_user_interface();

    return 0;
}
