#include "ProductIdRanges.hpp"
#include <algorithm>
#include <cassert>
#include <sstream>
#include <vector>

int ProductIdRanges::invalidIdSum() {
    return invalid_id_sum;
}

void ProductIdRanges::addProductIdRange(std::string range) {
    char range_delimiter = '-';

    int index = range.find(range_delimiter);
    int start = stoi(range.substr(0, index));
    int end = stoi(range.substr(index + 1, range.length()));

    assert(start < end);

    std::vector<std::string> values_in_range;
    for (int a = start; a <= end; a++) {
        values_in_range.push_back(std::to_string(a));
    }

    for (std::string value : values_in_range) {
        if (value.length() % 2 == 1) {
            value.insert(0, "0");
        }

        std::string prefix = value.substr(0, value.length() / 2);
        std::string suffix = value.substr(value.length() / 2, std::string::npos);

        if (prefix == suffix)
            invalid_id_sum += std::stoi(value);
    }
}
