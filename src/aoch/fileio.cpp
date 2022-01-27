#include "aoch/fileio.hpp"

#include <fstream>


namespace aoch {

std::tuple<std::vector<std::string>, bool> get_lines_from_textfile(const std::string& filename) {
    std::ifstream f(filename);
    std::vector<std::string> ret;

    if (!f.good()) {
        // something went wrong, return empty vec and false to indicate an error reading the file
        return std::make_tuple(ret, false);
    }

    while (f.good()) {
        std::string line;
        std::getline(f, line);
        ret.emplace_back(line);
    }

    // trim trailing empty lines
    while (ret.size() && ret.back().empty()) ret.pop_back();

    return std::make_tuple(ret, true);
}

} //namespace aoch
