#include "Zombie.hpp"

int main()
{
    // Stack
    Zombie stackZombie("Foo");
    stackZombie.announce();

    // Heap
    Zombie *heapZombie = newZombie("Heap");
    heapZombie->announce();

    // Stack
    randomChump("Chump");

    delete heapZombie;
    return 0;
}
