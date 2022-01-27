#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#include "aoch/AOCSolutionsManager.hpp"

#include "aoch/fileio.hpp"


namespace sc = std::chrono;
using dbl_ms = sc::duration<double, std::milli>;

namespace aoch {

void AOCSolutionsManager::add_solution(
    int day,
    Solve_fnc solution,
    Input input_data,
    std::optional<Result> expected_result
) {
    m_ran_solutions = false;
    m_solutions.emplace_back(day, solution, std::move(input_data), expected_result);
}

void AOCSolutionsManager::run() {
    for (auto& s : m_solutions) {

        auto start = sc::high_resolution_clock::now();

        s.returned_result = s.solution(s.input_data);

        auto end = sc::high_resolution_clock::now();

        s.time_taken = end - start;
    }

    m_ran_solutions = true;
}


void AOCSolutionsManager::print_result_table() {


    // only print result table if we already ran the solutions;
    if (!m_ran_solutions) {
        std::cout << "Warning: Tried to print results without executing run() beforehand.\n";
        return;
    }

    // sort by day, so we print solutions in order
    std::sort(m_solutions.begin(), m_solutions.end(),
        [] (const AOCSolution& a, const AOCSolution& b) {
            return a.day < b.day;
        }
    );

    const std::string p1 = "Part 1";
    const std::string p2 = "Part 2";
    const std::string t_str = "Time";

    size_t p1_ans_max_length = p1.size();
    size_t p2_ans_max_length = p2.size();
    size_t time_max_length   = t_str.size();

    sc::nanoseconds total_time(0);

    for (const auto& s : m_solutions) {
        p1_ans_max_length = std::max(
            p1_ans_max_length,
            s.returned_result.part1.size()
        );

        p2_ans_max_length = std::max(
            p2_ans_max_length,
            s.returned_result.part2.size()
        );

        // number of digits for time field
        auto t = std::max(sc::duration_cast<sc::milliseconds>(s.time_taken).count(), 1L);
        time_max_length = std::max(time_max_length, (size_t) (std::log10(t)) + 1 + 7);

        total_time += s.time_taken;
    }

    const size_t buffer_size = 2048;
    char buffer[buffer_size];

    // header
    snprintf(
        buffer,
        buffer_size,
        "| Day | %*s | %*s | %*s |\n",
        (int) p1_ans_max_length, p1.c_str(),
        (int) p2_ans_max_length, p2.c_str(),
        (int) time_max_length, t_str.c_str()
    );

    std::string sep_line(strlen(buffer) - 1, '-');

    // header
    std::cout << sep_line << '\n';
    std::cout << buffer;
    std::cout << sep_line << '\n';

    // normally we should check if stdout is a terminal and if it supports colors.
    // (isattty() + ncurses OR use a lib like {fmt})
    const std::string reset = "\033[0m";
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";

    // content
    for (const auto& s : m_solutions) {

        std::string p1_ans_prefix;
        std::string p2_ans_prefix;

        if (s.expected_result) {
            p1_ans_prefix =
                s.expected_result->part1 == s.returned_result.part1 ? green : red;
            p2_ans_prefix =
                s.expected_result->part2 == s.returned_result.part2 ? green : red;
        }

        printf(
            "|  %.2d | %s%*s%s | %s%*s%s | %*.3f ms |\n",
            s.day,
            p1_ans_prefix.c_str(),
            (int) p1_ans_max_length,
            s.returned_result.part1.c_str(),
            reset.c_str(),
            p2_ans_prefix.c_str(),
            (int) p2_ans_max_length,
            s.returned_result.part2.c_str(),
            reset.c_str(),
            (int) time_max_length - 3,
            sc::duration_cast<dbl_ms>(s.time_taken).count()
        );
    }

    // total time
    std::cout << sep_line << '\n';

    printf(
        "| %*.3f ms |\n", (int) (sep_line.size() - 7),
        sc::duration_cast<dbl_ms>(total_time).count()
    );

    std::cout << sep_line << '\n';
}

} // namespace aoch
