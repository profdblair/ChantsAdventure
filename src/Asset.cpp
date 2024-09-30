#include <Asset.hpp>

namespace chants
{
    Asset::Asset(string name, int value)
    {
        _name = name;
        _value = value;
    }

    string Asset::GetName()
    {
        return _name;
    }

    int Asset::GetValue()
    {
        return _value;
    }
}