#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include "number.h"

std::vector<std::pair<std::string, NumberOperation>> OPERATIONS;

struct UserInput {
    NumberOperation op;
    Number number_a, number_b;
};

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

std::optional<UserInput> read_user_input() {
    size_t idx;
    Number a, b;

    std::cout << "Podaj numer operacji: ";
    if (!(std::cin >> idx && idx - 1 < OPERATIONS.size())) {
        return std::nullopt;
    }

    std::cout << "Podaj pierwsza liczbe: ";
    if (!(std::cin >> a)) {
        return std::nullopt;
    }

    std::cout << "Podaj druga liczbe: ";
    if (!(std::cin >> b)) {
        return std::nullopt;
    }

    return UserInput {
        OPERATIONS[idx - 1].second,
        a,
        b
    };
}

Number eval_user_input(const UserInput& input) {
    return input.op(input.number_a, input.number_b);
}

void handle_user_interaction() {
    while (true) {
        auto input_opt = read_user_input();

        if (input_opt.has_value()) {
            Number result = eval_user_input(*input_opt);
            std::cout << "Wynik wynosi: "
                << result
                << '\n';

            return;
        }
    }
}

int main(int argc, char* argv[]) {
    display_user_interface();
    handle_user_interaction();

    return 0;
}
