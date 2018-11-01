#include <fstream>

void writeScore(std::string name, int score)
{
    if (!name.empty())
    {
        name = "anonymous";
    }

    std::ofstream file("scores.dat", std::ios_base::app | std::ios_base::out);
    file << "\n"
         << name << " " << score;
};