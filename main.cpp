#include "wheel.hpp"

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <string>


struct Statistics
{
    int min{};
    double average{};
    int mode{};
    int max{};
};


Statistics calculateStatistics(const std::vector<int>& values)
{
    Statistics stats{};

    if (values.empty())
        return stats;


    // ---------------------------------------------------------
    // MINIMUM
    // ---------------------------------------------------------

    stats.min = *std::min_element(
        values.begin(),
        values.end()
    );


    // ---------------------------------------------------------
    // MAXIMUM
    // ---------------------------------------------------------

    stats.max = *std::max_element(
        values.begin(),
        values.end()
    );


    // ---------------------------------------------------------
    // AVERAGE
    // ---------------------------------------------------------

    long long total = 0;

    for (int value : values)
    {
        total += value;
    }

    stats.average =
        static_cast<double>(total) /
        static_cast<double>(values.size());


    // ---------------------------------------------------------
    // MODE
    //
    // Ignore 0 because 0 means:
    // "this loot was not obtained in this simulation".
    //
    // We only want the most common quantity when the loot
    // was actually obtained.
    // ---------------------------------------------------------

    std::map<int, int> frequency;

    for (int value : values)
    {
        ++frequency[value];
    }

    int highestFrequency = 0;

    for (const auto& [value, count] : frequency)
    {
        if (count > highestFrequency)
        {
            highestFrequency = count;
            stats.mode = value;
        }
    }


    return stats;
}


int main()
{
    int spins;
    int simulations;


    // =========================================================
    // USER INPUT
    // =========================================================

    std::cout << "How many spins per simulation? ";
    std::cin >> spins;

    std::cout << "How many Monte Carlo simulations? ";
    std::cin >> simulations;


    if (spins <= 0 || simulations <= 0)
    {
        std::cout << "Values must be greater than 0.\n";
        return 1;
    }


    // =========================================================
    // RESULTS
    //
    // lootResults["Rubies"] contains the total amount of
    // Rubies obtained in EVERY simulation.
    //
    // Example:
    //
    // Rubies -> { 0, 0, 50000, 0, 100000, ... }
    // =========================================================

    std::map<std::string, std::vector<int>> lootResults;


    // =========================================================
    // MONTE CARLO
    // =========================================================

    for (int simulation = 0;
        simulation < simulations;
        ++simulation)
    {
        Wheel wheel;

        wheel.load();

        wheel.spin(spins);


        const auto& loot = wheel.getLoot();


        // -----------------------------------------------------
        // First add the loot that was actually obtained.
        // -----------------------------------------------------

        for (const auto& [name, quantity] : loot)
        {
            lootResults[name].push_back(quantity);
        }


        // -----------------------------------------------------
        // Loot that wasn't obtained in this simulation
        // must receive a 0.
        // -----------------------------------------------------

        for (auto& [name, values] : lootResults)
        {
            if (values.size() <
                static_cast<size_t>(simulation + 1))
            {
                values.push_back(0);
            }
        }


        // -----------------------------------------------------
        // Progress display
        // -----------------------------------------------------

        if ((simulation + 1) % 1000 == 0 ||
            simulation + 1 == simulations)
        {
            std::cout
                << "\rSimulation "
                << simulation + 1
                << " / "
                << simulations
                << std::flush;
        }
    }


    std::cout << "\n\n";


    // =========================================================
    // PRINT RESULTS
    // =========================================================

    std::cout
        << "============================================================\n";

    std::cout
        << "                  MONTE CARLO RESULTS\n";

    std::cout
        << "============================================================\n";

    std::cout
        << "Spins per simulation : "
        << spins
        << '\n';

    std::cout
        << "Simulations          : "
        << simulations
        << '\n';

    std::cout
        << "============================================================\n\n";


    // =========================================================
    // TABLE HEADER
    // =========================================================

    std::cout
        << std::left
        << std::setw(40)
        << "Loot"

        << std::right
        << std::setw(12)
        << "Min"

        << std::setw(15)
        << "Average"

        << std::setw(12)
        << "Mode"

        << std::setw(12)
        << "Max"

        << '\n';


    std::cout
        << std::string(91, '-')
        << '\n';


    // =========================================================
    // TABLE CONTENT
    // =========================================================

    for (const auto& [name, values] : lootResults)
    {
        const Statistics stats =
            calculateStatistics(values);


        std::cout
            << std::left
            << std::setw(40)
            << name

            << std::right
            << std::setw(12)
            << stats.min

            << std::setw(15)
            << std::fixed
            << std::setprecision(2)
            << stats.average

            << std::setw(12)
            << stats.mode

            << std::setw(12)
            << stats.max

            << '\n';
    }


    std::cout
        << '\n';

    return 0;
}