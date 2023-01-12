#include <array>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

#define NUM_WORDS 1 << 17

std::array<std::string, NUM_WORDS> words {};
std::set<std::string> table{};

void find_compound_words(int num_words) {
    for (int i = 0; i < num_words; i++) {
        unsigned len = words[i].length();
        for (int j = 1; j < len; j++) {
            std::string substr = words[i].substr(j, len - j);
            if (table.find(words[i]) != table.end() && table.find(substr) != table.end()) {
                std::cout << words[i] << '\n';
                break;
            }
        }
    }
}

auto main() -> int {
    int num_words;
    std::cout << "Enter number of words to read:\n";
    std::cin >> num_words;

    std::cout << "Enter the words:\n";
    std::string buffer;
    for (int i = 0; i < num_words; i++) {
        std::cin >> words[i];
        table.insert(words[i]);
    }

    std::cout << "Compound words:\n";
    find_compound_words(num_words);
    return 0;
}
