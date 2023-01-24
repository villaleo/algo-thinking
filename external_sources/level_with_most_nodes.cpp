#include <iostream>
#include <unordered_map>
#include <vector>

#include "../lib/macros.h"

class Graph {
public:
    int value;
    int level;
    std::vector<Graph> children;

    static func of(int value) -> Graph {
        return {.value = value};
    }

    static func of(int value, const std::vector<Graph>& children) -> Graph {
        return {.value = value, .children = children};
    }
};

func assign_levels(Graph& root, int level = 0) -> void;
func level_with_most_nodes(Graph& root) -> int;

static std::unordered_map<int, int> node_levels;
func main() -> int {
    let tree = Graph::of(10, {
        Graph::of(20, {Graph::of(50), Graph::of(60)}),
        Graph::of(30),
        Graph::of(40),
    });

    int result = level_with_most_nodes(tree);
    std::cout << "Map of levels to number of nodes:\n";
    for (const unpack& [level, num_nodes] in node_levels) {
        std::cout << "\tLevel " << level << ": " << num_nodes << '\n';
    }
    std::cout << "Level with most nodes: " << result << '\n';
    return 0;
}

func assign_levels(Graph& root, int level) -> void {
    root.level = level;
    node_levels[root.level]++;
    for (let child in root.children) {
        assign_levels(child, level + 1);
    }
}

func level_with_most_nodes(Graph& root) -> int {
    assign_levels(root);
    let compare_by_node_count = lambda (let a, let b) -> bool {
        return a.second < b.second;
    };
    unpack move [level, _] = *std::max_element(iter(node_levels), compare_by_node_count);
    return level;
}