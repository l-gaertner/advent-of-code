#include "ProductIdRanges.hpp"
#include <sstream>

int ProductIdRanges::invalidIdSum() {
    return invalid_id_sum;
}

void ProductIdRanges::addProductIdRange(std::string range) {
    char range_delimiter = '-';

    int index = range.find(range_delimiter);
    std::string start = range.substr(0, index);

    if (start[0] == start[start.length() - 1]) {
        invalid_id_sum = std::stoi(start);
    }

    std::string end = range.substr(index + 1, range.length() - 1);

    if (end[0] == end[end.length() - 1]) {
        invalid_id_sum = std::stoi(end);
    }
}
