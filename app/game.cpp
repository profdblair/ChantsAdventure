#include <iostream>
#include <Node.hpp>
#include <Asset.hpp>
#include <Player.hpp>
#include <Monster.hpp>

using namespace std;
using namespace chants;

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

void AtNode(Node &viewPort)
{
    cout << "At " << viewPort.GetName() + "\n";
    for (Node *node : viewPort.GetConnections())
    {
        cout << "Connection to: " << node->GetId() << " " << node->GetName() << endl;
    }
    for (Asset *asset : viewPort.GetAssets())
    {
        cout << "Asset at this node: " << asset->GetName() << " " << asset->GetValue() << endl;
    }
    for (Monster *monster : viewPort.GetMonsters())
    {
        // cout << "Monstter at this node: " << monster->GetName() << " " << monster->GetHealth() << endl;
    }

    cout << "\n";
}

int FindNode(string loc, vector<Node> *gameMap)
{
    int intLoc = -1;
    if (isNumber(loc))
    {
        intLoc = stoi(loc);
    }
    for (Node node : *gameMap)
    {
        if (node.GetName() == loc || node.GetId() == intLoc)
            return node.GetId();
    }
    return -1;
}

int Battle(Player player)
{
    srand(time(nullptr));

    return player.GetHealth();
}

int main()
{
    cout << "Hello and welcome to Chants Adventure!\n";
    vector<Node> GameMap;

    Player spock("Spock", 10000, 1000);

    // build all nodes
    Node home(0, "Home");
    Node mountain(1, "Mountain");
    Node ocean(2, "Ocean");
    Node spaceship(3, "Space Ship");
    Node city(4, "Metropolis");
    Node boat(5, "SS Minnow");
    Node cave(6, "Dark Cave");
    Node island(7, "Island");
    Node moon(8, "Moon");

    // define all assets
    Asset hammer("Hammer", "", 100, true);
    Asset laser("Laser", "", 500, true);
    Asset shark("Shark", "", 300, true);

    // Monster franky("Frankenstine", 10000);
    // Monster goblin("Goblin", 8000);
    // Monster kraken("Kraken", 12000);

    // add assets to nodes
    home.AddAsset(&hammer);
    mountain.AddAsset(&laser);
    ocean.AddAsset(&shark);

    // add monsters to nodes
    // home.AddMonster(&franky);
    // mountain.AddMonster(&goblin);
    // ocean.AddMonster(&kraken);

    // connect nodes
    home.AddConnection(&ocean);
    home.AddConnection(&city);
    home.AddConnection(&spaceship);

    ocean.AddConnection(&home);
    ocean.AddConnection(&boat);

    boat.AddConnection(&ocean);
    boat.AddConnection(&island);

    island.AddConnection(&boat);
    island.AddConnection(&cave);

    cave.AddConnection(&island);
    cave.AddConnection(&moon);
    cave.AddConnection(&mountain);
    cave.AddConnection(&city);

    mountain.AddConnection(&cave);
    mountain.AddConnection(&city);

    city.AddConnection(&mountain);
    city.AddConnection(&cave);
    city.AddConnection(&home);

    spaceship.AddConnection(&home);
    spaceship.AddConnection(&moon);

    moon.AddConnection(&spaceship);
    moon.AddConnection(&cave);

    // build map
    GameMap.push_back(home);
    GameMap.push_back(ocean);
    GameMap.push_back(boat);
    GameMap.push_back(island);
    GameMap.push_back(cave);
    GameMap.push_back(mountain);
    GameMap.push_back(city);
    GameMap.push_back(spaceship);
    GameMap.push_back(moon);

    bool runningGame = true;
    int nodePointer = 0;
    string input;
    while (runningGame)
    {
        // show current node info
        cout << "NODEPTR: " << nodePointer << "\n";
        AtNode(GameMap[nodePointer]);
        cout << "To do? e(x)it: ";
        cin >> input;
        if (input == "x")
            break;
        if (input == "a")
        {
            // Battle(spock, GameMap[nodePointer].monsters);
        }
        int dir = FindNode(input, &GameMap);
        if (dir >= 0)
            nodePointer = dir;
        cout << endl;
    }
}
