//
// Created by hoben on 2/8/2023.
//

#include "ZipCode.h"

ZipCode::ZipCode(int zipcode):zipcode(zipcode){
}

ZipCode::ZipCode(std::string barcode){
    toZipCode(barcode);
}

int ZipCode::getZipCode()
{
    return zipcode;
}

std::string ZipCode::getBarCode()
{
    toBarCode(zipcode);
    return barcode;
}

void ZipCode::toBarCode(int zipcode)
{
    barcode = "1";
    std::string temp = std::to_string(zipcode);

    for (int i = 0; i < temp.length(); i++) {
        switch (temp.at(i)) {
            case '0': barcode += std::string("11000");
                break;
            case '1': barcode += std::string("00011");
                break;
            case '2': barcode += std::string("00101");
                break;
            case '3': barcode += std::string("00110");
                break;
            case '4': barcode += std::string("01001");
                break;
            case '5': barcode += std::string("01010");
                break;
            case '6': barcode += std::string("01100");
                break;
            case '7': barcode += std::string("10001");
                break;
            case '8': barcode += std::string("10010");
                break;
            case '9': barcode += std::string("10100");
                break;
        }
    }
    barcode += std::string("1");
}

void ZipCode::toZipCode(std::string barcode)
{
    zipcode = 0;
    std::string tempZipcode;
    std::vector<std::string> temp(5);
    for(int i=0; i<5;i++)
    {
        temp[i] = barcode.substr(1,5);
        barcode.erase(1,5);
        tempZipcode += std::string(getSum(temp[i]));

    }
    zipcode = std::stoi(tempZipcode);
}

std::string ZipCode::getSum(std::string s)
{
    int sum = 0;
    if (s.at(0) == '1') {
        sum += 7;
    }
    if (s.at(1) == '1') {
        sum += 4;
    }
    if (s.at(2) == '1') {
        sum += 2;
    }
    if (s.at(3) == '1') {
        sum += 1;
    }
    if (s.at(4) == '1') {
        sum += 0;
    }
    if (sum == 11) {
        sum = 0;
    }
    return std::to_string(sum);
}