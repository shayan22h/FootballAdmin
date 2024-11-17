
#include <algorithm>  // For std::shuffle
#include <random>

#include "TeamGenerator.h"


TeamGenerator::TeamGenerator(uint32_t _maxNofOTeams, uint32_t _maxNoOfPlayers):
NoOfTeams(_maxNofOTeams), MaxNoOfPlayers(_maxNoOfPlayers)
{}

TeamGenerator::~TeamGenerator(){}

uint8_t TeamGenerator::ExtractCaptainsFromList(vector <string> (&nameof)[28])
{
    uint8_t CaptainIdx = 0;
    for (uint32_t i = 0; i < MaxNoOfPlayers; ++i) 
    {
        for (auto it = nameof[i].begin(); it != nameof[i].end();) 
        {
            if (*it == "c" && it != nameof[i].begin())
            {
                Captains[CaptainIdx] = *(it - 1);
                CaptainIdx++;
                nameof[i].clear();
                break; // Exit the inner loop since the vector is now empty
            }
            else
            {
                it++;
            }
        }
    }

    // Debug: Display the Captains array
    std::cout << "Captains: ";
    for (int i = 0; i < CaptainIdx; ++i) 
    {
        std::cout << Captains[i] << " ";
    }
    std::cout << std::endl;
    return ((!CaptainIdx) ? (CaptainIdx++) : CaptainIdx);
}

void TeamGenerator::GenerateTeams(vector<string> (&nameof)[28], TeamsContext_t* _pToTeamsContext)
{
    // Random number generator
    random_device rd;
    mt19937 gen(rd());

    // Shuffle the array of vectors
    shuffle(begin(nameof), end(nameof), gen);


    // Exclude Captains from the Max No of Players as they will be added later
    uint8_t noOfPlayerInEachTeam = (28 - _pToTeamsContext->noOfTeams) / _pToTeamsContext->noOfTeams;
    uint8_t noOfPlayersCount = 0;
    auto it = begin(nameof);

    for (int teamIdx = 0; teamIdx < _pToTeamsContext->noOfTeams; teamIdx++)
    {
         int teamPlayerCount = 0;

        // The Very First Thing for Creating Each Team Add The Captain
         _pToTeamsContext->Teams[teamIdx].push_back(Captains[teamIdx]);
         
        // fill One Team at the Time Captains will be added Later 
        while(teamPlayerCount < noOfPlayerInEachTeam && it != std::end(nameof))
        {

            
            // Add all valid players from the current vector
            for (const auto& player : *it)
            {

                if (teamPlayerCount < noOfPlayerInEachTeam && !player.empty())
                {
                    _pToTeamsContext->Teams[teamIdx].push_back(player);
                    ++teamPlayerCount;
                    ++noOfPlayersCount;
                }
                else
                {
                    cout << "either Empty Entry or Max No Of Players Reached for the team" << endl;
                }
            }

            // Move to the next vector
            ++it;

            // Stop if we've distributed all players
            if (noOfPlayersCount == (28 - _pToTeamsContext->noOfTeams))
            {
                break;
            }
        }

        // This Loop can not be called more than No Of Player In EachTeam Ex 28 - 4 (Exclude Captains)
        if (noOfPlayersCount == (28 - _pToTeamsContext->noOfTeams))
        {
            break;
        }

    }

    // if Shuffled array of vectors to shown on Debug set to 1
#if 1
    //std::cout << "Shuffled array of vectors:\n";
    for (int i = 0; i < 4; ++i) {
        for (const auto& team : _pToTeamsContext->Teams[i]) {
            std::cout << team << " ";
        }
        std::cout << std::endl;
    }
#endif
}
