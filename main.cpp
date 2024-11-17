
#include <iostream>
#include <thread>
#include <string>
#include <vector>

#include "Text_Handler/text_handler.h"
#include "TeamGenerator/TeamGenerator.h"
using namespace std;

#define file_name "../../TextFile/Sample.txt"



int main() {

    text_handler txtHanlder;
    TeamGenerator teamObj(MAX_NO_OF_TEAMS,MAX_NO_OF_PLAYERS);

    string fileNameStr = file_name;

    vector <string> NameOfPlayers[MAX_NO_OF_PLAYERS];

    txtHanlder.text_handler_read_file(fileNameStr, NameOfPlayers);

    uint8_t noOfCaptains = teamObj.ExtractCaptainsFromList(NameOfPlayers);

    TeamsContext_t team_context;
    team_context.noOfTeams = noOfCaptains;

    if (team_context.noOfTeams)
    {
        teamObj.GenerateTeams(NameOfPlayers,&team_context);
    }
    else
    {
        std::cout << "There was No Captains in the Text File " << endl;
    }
    
    return 0;
}
