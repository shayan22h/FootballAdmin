
#include <iostream>
#include <thread>
#include <string>

#include "Text_Handler/text_handler.h"
using namespace std;

#define file_name "../../TextFile/Sample.txt"
int main() {

    text_handler txtHanlder;
    std::cout << "Hellow World" << std::endl;
    string fileNameStr = file_name;
    txtHanlder.text_handler_read_file(fileNameStr);
    return 0;
}
