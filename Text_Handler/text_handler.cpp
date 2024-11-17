
#include "text_handler.h"
#include <iostream>



text_handler::text_handler(){
    SetThePattern();
};

text_handler::~text_handler(){
    if (in_stream.is_open()) 
    {
        in_stream.close();
    }
}

void text_handler::SetThePattern(void){
    // Assign the desired regex pattern to the Pattern object
    Pattern = std::regex(R"(^([1-9]|1[0-9]|2[0-8])\.\s)");
    // Regex for extracting names and captain markers (e.g., "Shayan - c")
    NameExtractionPattern = std::regex(R"(^\d+\.\s*([^\-]+)(?:\s*-\s*(c))?$)");
}

bool text_handler::GetTheNames(const string& _refLine, string& _refStrToPlayerName,
string& _refToCaptain)
{
    bool isLinePlayerName = false;
    if (regex_search(_refLine, Pattern))
    {
        smatch matches;
        if (regex_match(_refLine, matches, NameExtractionPattern)) 
        {
            _refStrToPlayerName = matches[1]; // Group 1: The player's name
            //std::cout << " Player Name : " +  _refStrToPlayerName << endl;
            if (matches[2].matched) 
            {
                _refToCaptain = matches[2]; // Group 2: Captain marker ("c")
            } else 
            {
                _refToCaptain = ""; // No captain marker
            }
            isLinePlayerName = true;
        }
        else{
            std::cout << " could not extract the info " << endl;
        } 
    }
    return isLinePlayerName;
}

//void text_handler_read_file(const std::string& fileNameStr, std::array<std::vector<std::string>, 10>& nameof)
void text_handler::text_handler_read_file(string& fileNameStr, vector<string> (&nameof)[28])
{
    if (in_stream.is_open()) 
    {
        in_stream.close(); // Close previous file if open
    }

    // Open the file directly using the passed fileNameStr
    in_stream.open(fileNameStr);
    
    if (in_stream.fail()) 
    {
        std::cerr << "Could not open file to read: " << fileNameStr << "\n";
        return;
    }



        // Output the content of the file to the console, similar to 'cat'
    string line;
    int index = 0;

    string strPlayerName;
    string captainMarker;

    while (std::getline(in_stream, line)) 
    {
        if( index < MAX_NO_OF_PLAYERS && 
        GetTheNames(line, strPlayerName, captainMarker) )
        {
            nameof[index].push_back(strPlayerName);
            // If there's a captain marker, push it as well
            if (!captainMarker.empty()) 
            {
                nameof[index].push_back(captainMarker);
            }
            index++;
        }
    }
    in_stream.close(); // Close file after reading
}