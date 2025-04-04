//
// Created by Dave Smith on 1/28/23.
//

#include "functions.h"


std::vector<std::vector<std::string>> generateIndex(const std::string &data) {
    std::vector<std::string> strings = split(data, " ");
    std::vector<std::string> x;
    std::vector<std::vector<std::string>> index(26, x);
    for (const std::string &s: strings) {
        std::string t = s;
        t = removePunctuation(t);
        //std::string t = tolower(removePunctuation(s));
        if (!contains(index[charToIndex(s[0])], t)) {
            t = tolower(t);
            index[charToIndex(s[0])].push_back(t);
        }
    }
    for (auto &i: index) {
        sort(i);
    }
    return index;
}

int charToIndex(char c) {
    return toupper(c) - 'A';
}

bool openFile(std::ifstream &fin, const std::string &filename) {
    fin.open(filename);
    return !(fin.fail());
}

std::vector<std::string> getIndex(char c, const std::vector<std::vector<std::string>> &index) {
    /*for (const auto & i : test)
    {
        std::cout << i << " ";
    }*/
    return index[charToIndex(c)];
}

void print(const std::vector<std::vector<std::string>> &index) {
    for (int i = 0; i < index.size(); i++) {
        std::cout << static_cast<char>(i + 'A') << ": ";
        for (const std::string &s: index[i])
            std::cout << s << " ";
        std::cout << std::endl;
    }
}

bool contains(const std::vector<std::string> &vector, const std::string &string) {
    for (const std::string &s: vector)
        if (tolower(s) == tolower(string))
            return true;
    return false;
}

std::string tolower(const std::string &string) {
    std::string s;
    for (char c: string)
        s.push_back(tolower(c));
    return s;
}

void sort(std::vector<std::string> &vector) {
    std::sort(vector.begin(), vector.end());
}

std::string removePunctuation(const std::string &string) {
    int pos = string.size() - 1;
    if (!(isalpha(string[pos])))
        return string.substr(0, pos);
    else
        return string;
}


std::string getFileContent(const std::string &filename) {
    std::ifstream fin;
    std::string s, next;
    if (!openFile(fin, filename))
        exit(28);
    while (getline(fin, next))
        s += next + " ";
    fin.close();
    return s;
}

std::vector<std::string> split(std::string key, const std::string &delimiter) {
    std::vector<std::string> v;
    while ((key.find(delimiter)) != std::string::npos) {
        int pos = key.find(delimiter);
        std::string sub = key.substr(0, pos);
        v.push_back(sub);
        key.erase(0, pos + delimiter.length());
    }
    v.push_back(key);
    return v;
}

void print(const std::vector<std::string> &index) {
    for (const auto &s: index) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

void driver() {
    char answer;
    auto data = getFileContent("key.txt");
    auto index = generateIndex(data);
    do {
        std::cout << "Enter a letter:";
        char c;
        std::cin >> c;
        std::vector<std::string> v = getIndex(c, index);
        print(v);
        std::cout << "Do you want to test another letter? Y/N";
        std::cin >> answer;
    } while (tolower(answer == 'y'));
}

