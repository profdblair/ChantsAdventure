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

void AtNode(Node viewPort)
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
        cout << "Monstter at this node: " << monster->Name << " " << monster->Health << endl;
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

    Player spock("Spock");

    // build all nodes
    Node home(0, "Home");
    Node mountain(1, "Mountain");
    Node ocean(2, "Ocean");

    // define all assets
    Asset hammer("Hammer", 100);
    Asset laser("Laser", 500);
    Asset shark("Shark", 300);

    Monster franky("Frankenstine", 10000);
    Monster goblin("Goblin", 8000);
    Monster kraken("Kraken", 12000);

    // add assets to nodes
    home.AddAsset(&hammer);
    mountain.AddAsset(&laser);
    ocean.AddAsset(&shark);

    // add monsters to nodes
    home.AddMonster(&franky);
    mountain.AddMonster(&goblin);
    ocean.AddMonster(&kraken);

    // connect nodes
    home.AddConnection(&mountain);
    mountain.AddConnection(&home);

    home.AddConnection(&ocean);
    ocean.AddConnection(&home);

    ocean.AddConnection(&mountain);
    mountain.AddConnection(&ocean);

    // build map
    GameMap.push_back(home);
    GameMap.push_back(mountain);
    GameMap.push_back(ocean);

    bool runningGame = true;
    int nodePointer = 0;
    string input;
    while (runningGame)
    {
        // show current node info
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
