#pragma once

#include <string>

using namespace std;

namespace chants
{
    struct Monster
    {
        string Name;
        int Health;

        Monster(string name, int health)
        {
            Name = name;
            Health = health;
        }
    };
}