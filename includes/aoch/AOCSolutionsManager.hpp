#pragma once

#include <chrono>
#include <optional>
#include <vector>

#include "aoch/AOCSolutionTypes.hpp"


#define DECL_AND_ADD_SOLUTION(SOLUTION, VEC) { aoch::Result SOLUTION(aoch::Input&); VEC.push_back(SOLUTION); }

namespace aoch {

class AOCSolutionsManager {

    public:

    void add_solution(
        int day,
        Solve_fnc solution,
        Input input_filename,
        std::optional<Result> expected_result = std::nullopt
    );

    void run();
    void print_result_table();


    private:

    struct AOCSolution {
        int       day;
        Solve_fnc solution;
        Input     input_data;
        Result    returned_result;
        std::chrono::nanoseconds time_taken;
        std::optional<Result>    expected_result;

        AOCSolution(int d, Solve_fnc s, Input id, std::optional<Result> er)
            : day(d), solution(s), input_data(id), expected_result(er) {}
    };

    std::vector<AOCSolution> m_solutions;
    bool m_ran_solutions = false;
};

} // namespace aoch
