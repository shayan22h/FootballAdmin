#include <string.h>
#include <algorithm>  // For std::shuffle
#include <random>
#include "DisplayHandler.h"

DisplayHandler::DisplayHandler(){};

DisplayHandler::~DisplayHandler(){};

void DisplayHandler::GenerateHTML(const TeamsContext_t& team_context, const std::string& filename) {
   std::ofstream html_file(filename);
   if (!html_file) {
        std::cerr << "Error: Unable to create HTML file.\n";
        return;
    }

    html_file << R"(
<!DOCTYPE html>
<html>
<head>
    <title>Teams</title>
<style>
    body {
        display: grid;
        grid-template-columns: 1fr 1fr; /* Two equal columns */
        grid-template-rows: auto auto; /* Two rows, adjust automatically */
        gap: 20px; /* Space between grid items */
        margin: 0;
        padding: 20px;
        font-family: Arial, sans-serif;
        background-color: #f9f9f9;
    }

    .team {
        border: 2px solid #ccc;
        border-radius: 10px;
        padding: 20px;
        text-align: center;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        background-color: #fff;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
    }

    .team:nth-child(1) {
        background-color: #0f83cf; /* Blue */
    }

    .team:nth-child(2) {
        background-color: #29c00b; /* Green */
    }

    .team:nth-child(3) {
        background-color: yellow; /* Yellow */
    }

    .team:nth-child(4) {
        background-color: pink; /* Pink */
    }

    .team h2 {
        background-color: #f4f4f4;
        padding: 10px;
        font-size: 1.5em;
        margin: 0;
        border-radius: 5px;
    }

    .team-logo {
        width: 120px;
        height: auto;
        margin: 15px 0;
        border-radius: 10px;
        border: 1px solid #ddd;
        box-shadow: 0 0 5px rgba(0, 0, 0, 0.1);
    }

    ul {
        list-style-type: none;
        padding: 0;
        margin: 0;
    }

    li {
        font-size: 2em;
        margin: 5px 0;
    }

    .captain {
        font-size: 2.5em;
        font-weight: bold;
        color: black;
    }
</style>
</head>
<body>

)";
    string TeamClubsName[12] = { "ManCity", "LiverPool", "Chelsea", "Spurs" ,
    "PSG", "Inter","AC Milan","Barca", "RealMadrid","Roma", "Dortmund", "Napoli"};

    // Random number generator
    random_device rd;
    mt19937 gen(rd());

    // Shuffle the array of vectors
    shuffle(begin(TeamClubsName), end(TeamClubsName), gen);

    bool captainFlag = false;
    // Generate teams
    for (int i = 0; i < team_context.noOfTeams; ++i) {
        captainFlag = false;
        string logoFile = TeamClubsName[i] + "_logo.png"; // Construct logo filename
        html_file << "<div class=\"team\">\n";
        html_file << "<h2>" << TeamClubsName[i] << "</h2>\n"; // Club Name
        html_file << "<img src=\"" << logoFile << "\" alt=\"" << TeamClubsName[i]
                << " Logo\" class=\"team-logo\">\n"; // Team Logo
        html_file << "<ul>\n";
        for (const auto& player : team_context.Teams[i]) {
            if (!captainFlag) {
                captainFlag = true;
                html_file << "<li class=\"captain\">[Captain] " << player << "</li>\n";
            } else {
                html_file << "<li>" << player << "</li>\n";
            }
        }
        html_file << "</ul>\n</div>\n";
    }

    html_file << R"(
    </div>
</body>
</html>
)";
    html_file.close();
    std::cout << "Styled HTML file generated: " << filename << "\n";
}