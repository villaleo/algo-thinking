#include <iostream>
#include <vector>

#define MAX_NUM_LINES 100

/// Problem source: https://dmoj.ca/problem/lkp18c2p1

int main() {
    int num_lines;
    int num_people;
    std::cin >> num_lines >> num_people;
    
    std::vector<int> lines(num_lines);
    for (int& line : lines) {
        std::cin >> line;
    }

    for (int _ = 0; _ < num_people; _++) {
        int min = MAX_NUM_LINES + 1;
        int min_index = -1;

        for (int i = 0; i < num_lines; i++) {
            if (lines[i] <= min) {
                min = lines[i];
                min_index = i;
            }
        }

        lines[min_index]++;
        std::cout << min << '\n';
    }

    return 0;
}
