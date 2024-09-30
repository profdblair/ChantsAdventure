#pragma once

#include <string>
#include <vector>
#include <Asset.hpp>

using namespace std;

namespace chants
{
    class Player
    {
    private:
        string _name;
        int _health;
        vector<Asset> _assets;

    public:
        Player(string name);
        int GetHealth();
        void ChangeHealth(int value);
        void AddAsset(Asset asset);
        int GetTotalAssetValue();
    };
}
