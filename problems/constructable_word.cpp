//
// Created by Leonardo Villalobos on 1/11/23.
//

#include <iostream>
#include <map>
#include <vector>
#include <utility>

/// Finds a string in `words` such that all the characters from the word are in `key`.
/// @returns the word found; "-" if no word matches the key.
auto find(const std::vector<std::string>& words, const std::string& key) -> std::string;

auto test() -> void {
    std::vector<std::string> input { "baby", "cat", "axe", "from", "dome", "dada" };
    std::vector<std::string> tests { "ofjjjjrem", "xetax", "adxtad", "read", "ybab" };

    int test_num = 1;
    for (const std::string& test : tests) {
        std::cout << "Test #" << test_num << ":\n";
        std::cout << "\t" << "(" << test << ") -> " << find(input, test) << '\n';
        test_num++;
    }
}

auto main() -> int {
    test();
    return 0;
}

auto find(const std::vector<std::string>& words, const std::string& key) -> std::string {
    struct MapEntry {
        /// Maps characters to a reference count
        std::map<char, int> chars {};
        /// Amount of non-zero characters in the map
        int hits {0};
    };

    std::map<std::string, MapEntry> dict;
    for (const std::string& word : words) {
        MapEntry entry{{}, 0};
        for (const char& c : word) entry.chars[c]++;
        dict[word] = entry;
    }

    for (const char& c : key) {
        for (auto& [word, map_entry] : dict) {
            if (word.find(c) != std::string::npos && map_entry.chars[c] != 0) {
                map_entry.chars[c]--;
                map_entry.hits++;
            }
        }
    }

    for (auto& [word, map_entry] : dict) {
        if (map_entry.hits == word.length()) return word;
    }
    return "-";
}
