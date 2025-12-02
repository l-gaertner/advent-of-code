#ifndef PRODUCT_ID_RANGE_H
#define PRODUCT_ID_RANGE_H

#include <string>
class ProductIdRanges {
    private: 
        int invalid_id_sum = 0;
    public:
        int invalidIdSum();
        void addProductIdRange(std::string range);
};

#endif
