
#include <fstream>

using namespace std;

class text_handler{

    public:
    //Constuctor 
    text_handler();

    //Destructor 
    ~text_handler();

    // Read File 
    void text_handler_read_file(string& fileName);

    private:
    ifstream in_stream;
};
