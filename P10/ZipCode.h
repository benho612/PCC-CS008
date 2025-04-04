//
// Created by hoben on 2/8/2023.
//

#ifndef P10_ZIPCODE_H
#define P10_ZIPCODE_H

#include <iostream>
#include <string>
#include <vector>
class ZipCode {
private:
    std::string barcode;
    int zipcode;

public:
    ZipCode(int zipcode);
    ZipCode(std::string barcode);
    int getZipCode();
    std::string getBarCode();
    void toBarCode(int zipcode);
    void toZipCode(std::string barcode);
    std::string getSum(std::string s);
};

#endif //P10_ZIPCODE_H
