#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <numeric>

#define MAX_NUM_SNOWFLAKES 100'000
#define SNOWFLAKE_SIZE 6

using Snowflake = std::array<int, SNOWFLAKE_SIZE>;
using Matrix = std::array<Snowflake, MAX_NUM_SNOWFLAKES>;

/// Problem source: https://dmoj.ca/problem/cco07p2

auto has_pair(const Matrix& snowflakes, int num_snowflakes) -> void;
auto identify_identical(const std::vector<Snowflake>& snowflakes) -> bool;
auto are_identical(const Snowflake& a, const Snowflake& b) -> bool;
auto is_identical_right(const Snowflake& a, const Snowflake& b, int start) -> bool;
auto is_identical_left(const Snowflake& a, const Snowflake& b, int start) -> bool;

auto main() -> int {
    int num_snowflakes;
    std::cin >> num_snowflakes;

    Matrix snowflakes;
    for (int i = 0; i < num_snowflakes; ++i) {
        for (int j = 0; j < SNOWFLAKE_SIZE; ++j) {
            std::cin >> snowflakes[i][j];
        }
    }

    has_pair(snowflakes, num_snowflakes);
    return 0;
}

auto has_pair(const Matrix& snowflakes, int num_snowflakes) -> void {
    // Map the sum of the snowflakes to the matching snowflake(s)
    std::map<int, std::vector<Snowflake>> sums_to_snowflakes;
    for (int i = 0; i < num_snowflakes; i++) {
        int snowflake_sum = std::accumulate(snowflakes[i].begin(), snowflakes[i].end(), 0);
        if (sums_to_snowflakes.count(snowflake_sum) == 0) {
            sums_to_snowflakes.emplace(snowflake_sum, std::vector<Snowflake>{ snowflakes[i] });
        } else {
            sums_to_snowflakes.at(snowflake_sum).push_back(snowflakes[i]);
        }
    }

    bool result = false;
    for (const auto& [_, list] : sums_to_snowflakes) {
        if (list.size() >= 2) {
            // Compare the snowflakes in the list
            if (result) {
                std::cout << "Twin snowflakes found.\n";
                return;
            }
            result = identify_identical(list);
        }
    }

    std::cout << (result? "Twin snowflakes found.\n" : "No two snowflakes are alike.\n");
}

auto identify_identical(const std::vector<Snowflake>& snowflakes) -> bool {
    for (uint i = 0; i < snowflakes.size(); ++i) {
        for (uint j = i + 1; j < snowflakes.size(); ++j) {
            if (are_identical(snowflakes[i], snowflakes[j])) {
                return true;
            }
        }
    }
    return false;
}

auto are_identical(const Snowflake& a, const Snowflake& b) -> bool {
    for (int i = 0; i < SNOWFLAKE_SIZE; ++i) {
        if (is_identical_right(a, b, i) || is_identical_left(a, b, i)) return true;
    }
    return false;
}

auto is_identical_right(const Snowflake& a, const Snowflake& b, int start) -> bool {
    for (int i = 0; i < SNOWFLAKE_SIZE; ++i) {
        if (a[i] != b[(i + start) % SNOWFLAKE_SIZE]) return false;
    }
    return true;
}

auto is_identical_left(const Snowflake& a, const Snowflake& b, int start) -> bool {
    int index;
    for (int i = 0; i < SNOWFLAKE_SIZE; ++i) {
        index = start - i;
        if (index < 0) index += SNOWFLAKE_SIZE;
        if (a[i] != b[index]) return false;
    }
    return true;
}
