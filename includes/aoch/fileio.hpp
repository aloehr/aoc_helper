#pragma once

#include <string>
#include <vector>
#include <tuple>


namespace aoch {

std::tuple<std::vector<std::string>, bool> get_lines_from_textfile(const std::string& filename);

} // namespace aoch
