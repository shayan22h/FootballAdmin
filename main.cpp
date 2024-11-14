
#include <iostream>
#include <thread>
#include <string>
#include <vector>

#include "Text_Handler/text_handler.h"
using namespace std;

#define file_name "../../TextFile/Sample.txt"

#define MAX_NO_OF_PLAYERS  28

int main() {

    text_handler txtHanlder;
    std::cout << "Hellow World" << std::endl;
    string fileNameStr = file_name;

    vector <string> NameOfPlayers[28];

    txtHanlder.text_handler_read_file(fileNameStr, NameOfPlayers);
// Display the contents of NameOfPlayers
    for (int i = 0; i < 10; ++i) {
        cout << "print " << i << endl;
        for (const auto& name : NameOfPlayers[i]) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
}

    return 0;
}
