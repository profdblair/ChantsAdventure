#include <Player.hpp>

namespace chants
{

    Player::Player(string name)
    {
        _name = name;
    }

    int Player::GetHealth()
    {
        return _health;
    }

    void Player::ChangeHealth(int value)
    {
        _health += value;
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