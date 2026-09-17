#include <iostream>
#include "wheel.hpp"

int main()
{
    int ticket{};

    std::cout << "How many tickets do you have? ";
    std::cin >> ticket;

    Wheel wheel;

    wheel.load();
    wheel.spin(ticket);
    wheel.printLoot();

    return 0;
}

