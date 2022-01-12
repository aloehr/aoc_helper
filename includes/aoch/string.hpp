#pragma once

#include <string>
#include <vector>

namespace aoch {

std::vector<std::string> split(const std::string& str, char sep = ' ', bool keep_empty_splits = false);

} // namespace aoch
