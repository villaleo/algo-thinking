#include <iostream>
#include "../lib/debug.h"

auto prefix_len(const std::string& a, const std::string& b) -> int {
    int i = 0;
    while (a[i] == b[i]) { i++; }
    return i - 1;
}

auto suffix_len(const std::string& a, const std::string& b) -> int {
    int len = (int) a.length();
    int i = len;
    while (i >= 2 && a[i] == b[i - 1]) { i--; }
    return len - i;
}

auto main() -> int {
    std::string current, target;
    int len = (int) current.length();
    std::cin >> current >> target;

    int prefix = prefix_len(current, target);
    int suffix = suffix_len(current, target);

    int total = (prefix + 1) - (len - suffix) + 1;
    if (total < 0) { total = 0; }

    std::cout << total << '\n';
    for (int i = 0; i < total; i++) {
        std::cout << 1 + i + current.length() - suffix;
        if (i < total - 1) {
            std::cout << ' ';
            continue;
        }
        std::cout << '\n';
    }
    return 0;
}
