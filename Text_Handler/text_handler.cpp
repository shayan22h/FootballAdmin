
#include "text_handler.h"
#include <iostream>



text_handler::text_handler(){
    std::cout << "text Handler Constructor" << endl;
};

text_handler::~text_handler(){
    if (in_stream.is_open()) 
    {
        in_stream.close();
    }
}
void text_handler::text_handler_read_file(string& fileNameStr)
{
 if (in_stream.is_open()) {
        in_stream.close(); // Close previous file if open
    }

    // Open the file directly using the passed fileNameStr
    in_stream.open(fileNameStr);
    
    if (in_stream.fail()) {
        std::cerr << "Could not open file to read: " << fileNameStr << "\n";
        return;
    }

        // Output the content of the file to the console, similar to 'cat'
    std::string line;
    while (std::getline(in_stream, line)) {
        std::cout << line << "\n";
    }
    in_stream.close(); // Close file after reading
};