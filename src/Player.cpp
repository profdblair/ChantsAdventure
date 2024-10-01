#include <Player.hpp>

namespace chants
{

    Player::Player(string name, int health, int coefficient) : Combatant(name, health, coefficient)
    {
    }

    void Player::AddAsset(Asset asset)
    {
        _assets.push_back(asset);
    }

    int Player::GetTotalAssetValue()
    {
        int val = 0;
        for (Asset asset : _assets)
        {
            val += asset.GetValue();
        }
        return val;
    }
}