
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
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
        }
        .container {
            display: grid;
            grid-template-rows: 50% 50%;
            grid-template-columns: 50% 50%;
            height: 100vh;
        }
        .team {
            border: 2px solid #000;
            padding: 20px;
            box-sizing: border-box;
        }
        .team:nth-child(1) { background-color: #ffcccc; } /* Team A: Top Left */
        .team:nth-child(2) { background-color: #ccffcc; } /* Team B: Top Right */
        .team:nth-child(3) { background-color: #ccccff; } /* Team C: Bottom Left */
        .team:nth-child(4) { background-color: #ffffcc; } /* Team D: Bottom Right */
        .team h2 {
            text-align: center;
            margin-top: 0;
        }
        .team ul {
            list-style-type: none;
            padding: 0;
        }
        .team li {
            margin: 5px 0;
        }
        .captain {
            font-weight: bold;
            color: red;
        }
    </style>
</head>
<body>
    <div class="container">
)";

    // Generate teams
    for (int i = 0; i < team_context.noOfTeams; ++i) {
        html_file << "<div class=\"team\">\n";
        html_file << "<h2>Team " << char('A' + i) << "</h2>\n<ul>\n";
        for (const auto& player : team_context.Teams[i]) {
            if (player.back() == 'c') {
                html_file << "<li class=\"captain\">" << player.substr(0, player.size() - 3) << " (Captain)</li>\n";
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