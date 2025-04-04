#include <iostream>
#include "ZipCode.h"

int main() {
ZipCode zip1(99504);
ZipCode zip2(12345);
ZipCode zip3(67890);
ZipCode zip4("100101010011100001100110001");
ZipCode zip5("110100001011100001100010011");
ZipCode zip6("100011000110101000011100101");

std::cout << "Digits" << " " << "Bar Code" << std::endl;
std::cout << zip1.getZipCode() <<"    " << zip1.getBarCode() << std::endl;
std::cout << zip2.getZipCode() <<"    " << zip2.getBarCode() << std::endl;
std::cout << zip3.getZipCode() <<"    " << zip3.getBarCode() << std::endl;
std::cout << std::endl;
std::cout << zip4.getZipCode() <<"    " << zip4.getBarCode() << std::endl;
std::cout << zip5.getZipCode() <<"    " << zip5.getBarCode() << std::endl;
std::cout << zip6.getZipCode() <<"    " << zip6.getBarCode() << std::endl;
}
