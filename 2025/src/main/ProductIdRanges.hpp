#ifndef PRODUCT_ID_RANGE_H
#define PRODUCT_ID_RANGE_H

#include <string>
#include <vector>
class ProductIdRanges {
    private: 
        std::vector<std::string> ranges_collection;
    public:
        long long invalidIdSum();
        long long invalidIdSum_ex2();
        void addProductIdRange(std::string range);
        void addMultipleProductIdRanges(std::string range);
};

#endif
