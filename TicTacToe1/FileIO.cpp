//
// Created by hoben on 9/20/2023.
//

#include "FileIO.h"

void FileIO::openFile(std::ifstream &in, const std::string &filename) {
    in.open(filename);
}

void FileIO::closeFile(std::ofstream &out) {
    out.close();
}

