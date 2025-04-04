#include "String.h"



int main() {
    String s = "My dog has fleas";
    //std::vector<String> v = s.split(s);
    std::vector<String> v2 = s.split(s, ' ');
    for (const auto & i : v2) {
        std::cout << i << std::endl;
    }
}
