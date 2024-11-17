#ifndef DISPLAY_HANDLER_H
#define DISPLAY_HANDLER_H

#include <fstream>
#include <vector>
#include <string>
#include "../TeamGenerator/TeamGenerator.h"



using namespace std;

class DisplayHandler{

    public:
        DisplayHandler();
        
        ~DisplayHandler();

        void GenerateHTML(const TeamsContext_t& team_context,
         const std::string& filename);

    private:


};

#endif //DISPLAY_HANDLER_H