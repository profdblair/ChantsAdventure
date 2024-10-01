#pragma once

#include <string>
#include <Combatant.hpp>

using namespace std;

namespace chants
{
    class Monster : Combatant
    {
    public:
        Monster(string name, int health, int coefficient);
    };
}