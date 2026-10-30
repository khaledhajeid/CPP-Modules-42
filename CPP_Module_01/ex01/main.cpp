#include "Zombie.hpp"
#include <cstddef>
#include <iostream>

int main()
{
    int N = 5;
    Zombie *horde = zombieHorde(N, "Walker");

    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;

    std::cout << "--- one zombie ---" << std::endl;
    horde = zombieHorde(1, "Alone");
    horde->announce();
    delete[] horde;

    std::cout << "--- bad sizes ---" << std::endl;
    if (zombieHorde(0, "Nobody") == NULL && zombieHorde(-3, "Nobody") == NULL)
        std::cout << "no horde for 0 or -3" << std::endl;

    return 0;
}
