cmake_minimum_required(VERSION 3.24)
project(interview_problems)

set(CMAKE_CXX_STANDARD 20)

add_executable(food_lines problems/food_lines.cpp)
add_executable(unique_snowflakes problems/unique_snowflakes.cpp)
add_executable(constructable_word problems/constructable_word.cpp lib/debug.h)
add_executable(compound_words_c problems/compound_words.c)
add_executable(compound_words_cpp problems/compound_words.cpp)
add_executable(delete_a_letter problems/delete_a_letter.cpp)
add_executable(level_with_most_nodes external_sources/level_with_most_nodes.cpp)