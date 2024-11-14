
#include <fstream>
#include <vector>

using namespace std;

class text_handler{

    public:
    //Constuctor 
    text_handler();

    //Destructor 
    ~text_handler();

    // Read File 
    void text_handler_read_file(string& fileName,vector<string> (&nameof)[28]);

    private:
    ifstream in_stream;
};
