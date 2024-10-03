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

int Battle(Player player, Monster monster)
{
    srand(time(nullptr));

    return player.GetHealth();
}

int main()
{
    cout << "Hello and welcome to Chants Adventure!\n";
    vector<Node> GameMap;

    Player spock("Spock", 100, 100);

    // build all nodes
    Node home(0, "Home");
    Node mountain(1, "Mountain");
    Node ocean(2, "Ocean");
    Node city(3, "City");
    Node island(4, "Island");
    Node cave(5, "Cave");
    Node beach(6, "Beach");
    Node quicksand(7, "Quick Sand");
    Node hut(8, "Hut");

    // connect nodes
    home.AddConnection(&mountain);
    home.AddConnection(&city);

    mountain.AddConnection(&home);
    mountain.AddConnection(&ocean);
    mountain.AddConnection(&city);

    ocean.AddConnection(&mountain);
    ocean.AddConnection(&city);
    ocean.AddConnection(&island);

    city.AddConnection(&home);
    city.AddConnection(&mountain);
    city.AddConnection(&ocean);

    island.AddConnection(&ocean);
    island.AddConnection(&cave);
    island.AddConnection(&beach);
    island.AddConnection(&quicksand);
    island.AddConnection(&hut);

    cave.AddConnection(&home); // one way
    cave.AddConnection(&beach);
    cave.AddConnection(&island);

    beach.AddConnection(&cave);
    beach.AddConnection(&island);

    hut.AddConnection(&island);
    hut.AddConnection(&quicksand);

    quicksand.AddConnection(&hut);
    quicksand.AddConnection(&island);

    // build map in same order as Node Ids above.
    // The index of each node must match it's id.
    GameMap.push_back(home);
    GameMap.push_back(mountain);
    GameMap.push_back(ocean);
    GameMap.push_back(city);
    GameMap.push_back(island);
    GameMap.push_back(cave);
    GameMap.push_back(beach);
    GameMap.push_back(quicksand);
    GameMap.push_back(hut);

    // ######## add assets below ########
    // Flashlight
    // Atomic Map
    // Compass
    // Screwdriver
    // Hammer
    // Polyglot (translator)
    // Treasure
    // Hobgoblin Shield
    // Garden Hose
    // Chest
    // Sign
    // Rabbit Cage
    // Paper Bag
    // Captain’s Chair
    // Purple Haze
    // Drinking Glass
    // Rusty Nail

    // ######## add monsters below ########
    // Hobgoblin
    // Specter
    // Frankenstein
    // Vampire
    // Zombie
    // Warewolf
    // Ghoul
    // Troll
    // Phantom

    // get ready to play game below
    bool runningGame = true;
    int nodePointer = 0; // start at home
    string input;

    while (runningGame)
    {
        // show current node info
        AtNode(GameMap[nodePointer]);
        cout << "To do? e(x)it: ";
        cin >> input;
        if (input == "x")
            break;

        int dir = FindNode(input, &GameMap);
        if (dir >= 0)
            nodePointer = dir;
        cout << endl;
    }
}
