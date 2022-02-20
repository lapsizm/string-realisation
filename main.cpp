
#include "string.hpp"


int main() {
    BMTSU::string str("egegege");
    str.print();
    BMTSU::string str2(str);
    str2.print();
    BMTSU::string str3 = str + str2;
    str3.print();
}




























