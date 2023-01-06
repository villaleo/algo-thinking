//
// Created by Leonardo Villalobos on 1/6/23.
//

#ifndef INTERVIEW_PROBLEMS_DEBUG_H
#define INTERVIEW_PROBLEMS_DEBUG_H

#include <string>
#include <iostream>
#include <cstdio>

// Returns "true" or "false" depending on `val`
inline auto as_str(bool val) -> std::string {
    return val ? "true" : "false";
}

#endif //INTERVIEW_PROBLEMS_DEBUG_H
