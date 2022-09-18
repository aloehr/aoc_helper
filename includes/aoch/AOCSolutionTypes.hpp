#pragma once

#include <string>
#include <vector>

namespace aoch {

struct Result {
    std::string part1 = "";
    std::string part2 = "";
};

using Input = std::vector<std::string>;
using Solve_fnc = Result (*) (Input&);

} //namespace aoch
