//
// Created by hoben on 9/20/2023.
//

#ifndef TICTACTOE_FILEIO_H
#define TICTACTOE_FILEIO_H


#include <fstream>
#include <iostream>
class FileIO {
public:
    static void openFile(std::ifstream &in, const std::string &filename);
    static void closeFile(std::ofstream & out);
private:

};


#endif //TICTACTOE_FILEIO_H
