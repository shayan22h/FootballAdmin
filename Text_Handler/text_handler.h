
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

#define MAX_NO_OF_PLAYERS  28

class text_handler{

    public:
    //Constuctor 
    text_handler();

    //Destructor 
    ~text_handler();

    // Read File 
    void text_handler_read_file(string& fileName,vector<string> (&nameof)[28]);

    private:
    void SetThePattern();
    bool GetTheNames(const string& _refLine, string& _refStrToPlayerName
    ,string& _refToCaptain);
    ifstream in_stream;
    regex Pattern;
    regex NameExtractionPattern; // For extracting names and captain markers
};
