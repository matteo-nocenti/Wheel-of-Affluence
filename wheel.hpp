#pragma once

#include <string>
#include <map>
#include <vector>
#include <random>

struct data
{
    int quantity{};
    int probability{};
};

class Wheel
{
private:
    int _stage{ 1 };
    int _ticketUsed{};

    std::vector<std::pair<std::string, data>> _roll;
    std::map<int, std::vector<std::pair<std::string, data>>> _jackpot;
    std::map<std::string, int> _totalGain;

    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::uniform_int_distribution<int> distribution{ 1, 9999 };

public:
    void load();
    void stageUpdate();
    void spinJackpot();
    void spin(int i);
    void printLoot() const;

    const std::map<std::string, int>& getLoot() const;
};