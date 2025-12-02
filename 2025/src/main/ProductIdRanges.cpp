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
}
