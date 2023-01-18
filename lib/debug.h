//
// Created by Leonardo Villalobos on 1/8/23.
//

#ifndef INTERVIEW_PROBLEMS_DEBUG_H
#define INTERVIEW_PROBLEMS_DEBUG_H

#define dbg(x) std::cout << (#x) << " = " << x << '\n'

#include <iostream>
#include <vector>

template <typename Type,typename Alloc = std::allocator<Type>>
std::ostream& operator<<(std::ostream& os, const std::vector<Type, Alloc>& vec) {
    os << '[';
    auto iter = vec.begin();
    while (iter != vec.end()) {
        os << *iter;
        iter++;
        if (iter != vec.end()) os << ", ";
    }
    os << ']';
    return os;
}

#include <map>
#include <utility>

template <typename TypeA,typename TypeB>
std::ostream& operator<<(std::ostream& os, const std::pair<TypeA, TypeB>& pair) {
    os << '<' << pair.first << ", " << pair.second << '>';
    return os;
}

template <
    typename Key,
    typename Value,
    typename Comp = std::less<Key>,
    typename Alloc = std::allocator<std::pair<const Key, Value>>
>
std::ostream& operator<<(std::ostream& os, const std::map<Key, Value, Comp, Alloc>& map) {
    os << '{';
    auto iter = map.begin();
    while (iter != map.end()) {
        os << *iter;
        iter++;
        if (iter != map.end()) os << ", ";
    }
    os << '}';
    return os;
}

#include <array>

template <typename Type, size_t n>
std::ostream& operator<<(std::ostream& os, const std::array<Type, n>& array) {
    os << '[';
    auto iter = array.begin();
    while (iter != array.end()) {
        os << *iter;
        iter++;
        if (iter != array.end()) os << ", ";
    }
    os << ']';
    return os;
}

#include <set>

template <
    typename Key,
    typename Comp = std::less<Key>,
    typename Alloc = std::allocator<Key>
>
auto operator<<(std::ostream& os, const std::set<Key, Comp, Alloc>& set) -> std::ostream& {
    os << '{';
    auto iter = set.begin();
    while (iter != set.end()) {
        os << *iter;
        iter++;
        if (iter != set.end()) os << ", ";
    }
    os << '}';
    return os;
}

#endif //INTERVIEW_PROBLEMS_DEBUG_H
