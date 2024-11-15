
#include <iostream>
#include <thread>
#include <string>
#include <vector>

#include "Text_Handler/text_handler.h"
using namespace std;

#define file_name "../../TextFile/Sample.txt"



int main() {

    text_handler txtHanlder;
    string fileNameStr = file_name;

    vector <string> NameOfPlayers[MAX_NO_OF_PLAYERS];

    txtHanlder.text_handler_read_file(fileNameStr, NameOfPlayers);
// Display the contents of NameOfPlayers
    for (int i = 0; i < MAX_NO_OF_PLAYERS; ++i) {
        for (const auto& name : NameOfPlayers[i]) {
        std::cout << name << endl ;
    }
    std::cout << std::endl;
}

    return 0;
}
