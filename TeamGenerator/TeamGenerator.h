#ifndef TEAM_GENERATOR_H
#define TEAM_GENERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

#define MAX_NO_OF_TEAMS  4

using namespace std;

typedef struct
{
    vector<string> Teams[MAX_NO_OF_TEAMS];
    uint8_t noOfTeams;
}TeamsContext_t;

class TeamGenerator{

    public:
    TeamGenerator(uint32_t _maxNofOTeams, uint32_t _maxNoOfPlayers);
    ~TeamGenerator();
    uint8_t ExtractCaptainsFromList(vector <string> (&nameof)[28]);
    void GenerateTeams(vector <string> (&nameof)[28], TeamsContext_t* _pToTeamsContext);

    private:
    uint32_t NoOfTeams;
    uint32_t MaxNoOfPlayers;
    string Captains[MAX_NO_OF_TEAMS];


};

#endif //TEAM_GENERATOR_H