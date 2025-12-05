#include "ProductIdRanges.hpp"
#include <cassert>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

long long ProductIdRanges::invalidIdSum() {
    long long invalid_id_sum = 0;
    for (std::string range : ranges_collection) {
        char range_delimiter = '-';

        int index = range.find(range_delimiter);
        long start = stol(range.substr(0, index));
        long end = stol(range.substr(index + 1, std::string::npos));

        assert(start < end);

        for (long value_long = start; value_long <= end; value_long++) {
            std::string value = std::to_string(value_long);
            if (value.length() % 2 == 1) {
                continue;
            }

            std::string prefix = value.substr(0, value.length() / 2);
            std::string suffix = value.substr(value.length() / 2, std::string::npos);

            if (prefix == suffix)
                invalid_id_sum += std::stol(value);
        }
    }
    return invalid_id_sum;
}

long long ProductIdRanges::invalidIdSum_ex2() {
    long long invalid_id_sum = 0;
    for (std::string range : ranges_collection) {
        char range_delimiter = '-';

        int index = range.find(range_delimiter);
        long start = stol(range.substr(0, index));
        long end = stol(range.substr(index + 1, std::string::npos));

        assert(start < end);

        for (long value_long = start; value_long <= end; value_long++) {
            std::string value = std::to_string(value_long);
            for (int a = 1; a < value.length() / 2 + 1; a++) {
                if (value.length() % a == 0) {
                    std::string prefix = value.substr(0, a);
                    bool does_pattern_match = true;
                    for (size_t b = 0; b < value.length() / a; b++) {
                        std::string substring = value.substr(b * prefix.length(), prefix.length());
                        if (substring != prefix) {
                            does_pattern_match = false;
                            break;
                        }
                    }

                    if (does_pattern_match) {
                        invalid_id_sum += std::stol(value);
                        break;
                    }
                }

            }
        }
    }
    return invalid_id_sum;
}

void ProductIdRanges::addProductIdRange(std::string range) {
    ranges_collection.push_back(range);
}

void ProductIdRanges::addMultipleProductIdRanges(std::string ranges) {
    char delimiter = ',';
    auto pos = ranges.find(delimiter);
    while (pos != std::string::npos) {
        ranges_collection.push_back(ranges.substr(0, pos));
        ranges.erase(0, pos + 1);
        pos = ranges.find(delimiter);
    }
    ranges_collection.push_back(ranges);
}
