#pragma once

#include <string>

using namespace std;

namespace chants
{
    class Asset
    {
    private:
        string _name;
        int _value;

    public:
        Asset(string name, int value);
        string GetName();
        int GetValue();
    };
}