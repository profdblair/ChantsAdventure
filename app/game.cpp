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
    cout << "\033[2J\033[1;1H"; // clear screen

    // Output contents of this Node
    cout << "Location: " << viewPort.GetName() + "\n\n";
    cout << viewPort.Description << endl
         << "There are paths leading towards " << endl;
    for (Node *node : viewPort.GetConnections())
    {
        cout << node->GetId() << " " << node->GetName() << endl;
    }

    // Show all assets in Node
    for (Asset *asset : viewPort.GetAssets())
    {
        cout << "Asset at this node: " << asset->GetName() << " " << asset->GetValue() << endl;
    }

    // Show any monsters at this Node
    for (Monster *monster : viewPort.GetMonsters())
    {
        cout << "Monstter at this node: " << monster->GetName() << " " << monster->GetHealth() << endl;
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

//
// All this game setup will be moved to gamemap and out of the main function
//
int main()
{
    cout << "Hello and welcome to Chants Adventure!\n";
    cout << "[Enter the node number to move to that node]\n";
    vector<Node> GameMap;

    // build all nodes
    Node home(0, "Home");
    home.Description = "You are standing in the front yard of a warm and comfortable home that exudes charm and\ntranquility, inviting visitors to feel welcome even before they step inside.\n";

    Node mountain(1, "Mountain");
    mountain.Description = "A majestic mountain rises grandly from the landscape, its towering\npeak piercing the sky and exuding a sense of awe and reverence.\n";

    Node city(2, "City");
    city.Description = "A typical city is a bustling hub of activity, blending diverse elements of\narchitecture, culture, and human interaction. It features a variety of neighborhoods,\neach with its own character, from high-rise apartment buildings and business\ndistricts to residential areas and parks.\n";

    Node ocean(3, "Ocean");
    ocean.Description = "The sea appears restless and chaotic, with surging swells that seem to roil\nand churn, as if the ocean itself is furious, thrashing in a wild, unpredictable rhythm.\n";

    Node island(4, "Island");
    island.Description = "In the midst of an angry sea, the island appears as a defiant outpost,\nbattered but unyielding against the surrounding chaos. Jagged cliffs rise abruptly\nfrom the churning waters, their rugged faces streaked with dark, wet stone, dripping\nwith the constant assault of waves.\n";

    Node hut(5, "Hut");
    hut.Description = "A hut stands as a weathered refuge, small and sturdy against the backdrop of\nthe raging sea. Its wooden walls, gray and splintered from years of exposure to\nsalt and wind, are patched together with whatever materials the island could provide—driftwood,\npalm fronds, and rough-hewn stone.\nThe roof is thatched with dried leaves, lashed tightly\nto withstand the powerful gusts that whip across the island.\n";

    Node quicksand(6, "Quick Sand");
    quicksand.Description = "A patch of treacherous quicksand lurks, deceptively blending into the surrounding\nterrain. It lies at the edge of a narrow clearing, where the ground transitions\nfrom rocky soil to a stretch of damp, silty earth.\n";

    Node cave(7, "Cave");
    cave.Description = "Here is a cave nestled into the rocky cliffs that rise above the angry sea, is a cave that\nseems carved by nature's fury over centuries. Its entrance is half-hidden by\nthick vines and jagged boulders, giving it an air of mystery and shelter.\nThe mouth of the cave is wide and low, just tall enough\nfor a person to crouch and enter, and it faces away from\nthe wind, offering some protection from the relentless storm.\n";

    Node beach(8, "Beach");
    beach.Description = "A beautiful beach stretches out in a graceful curve, bordered by soft, powdery sand that\ngleams white under the sunlight. Each grain feels fine and smooth beneath bare\nfeet, as though sculpted by the gentle hands of time and tide. The shoreline\nis kissed by the crystal-clear waters of the ocean,\nwhere the surf laps quietly and rhythmically, creating a soft,\nsoothing sound with each wave.\n";

    // connect nodes paths
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

    cave.AddConnection(&home); // one way connection
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
    GameMap.push_back(city);
    GameMap.push_back(ocean);
    GameMap.push_back(island);
    GameMap.push_back(hut);
    GameMap.push_back(quicksand);
    GameMap.push_back(cave);
    GameMap.push_back(beach);

    // get ready to play game below
    int nodePointer = 0; // start at home
    string input;

    // game loop
    while (true)
    {
        // show current node info
        AtNode(GameMap[nodePointer]);

        cout << "Go to node? e(x)it: ";
        cin >> input;

        // exit app?
        if (input == "x")
            break;

        int nodeAddr = -1;
        if (isNumber(input))
        {
            nodeAddr = stoi(input);
        }

        bool validConnection = false;
        for (Node *node : GameMap[nodePointer].GetConnections())
        {
            if (node->GetId() == nodeAddr)
            {
                validConnection = true;
            }
        }

        int dir = -1;
        if (validConnection)
        {
            dir = FindNode(input, &GameMap);
        }

        cout << "Dir: " << dir << endl;
        if (dir >= 0)
            nodePointer = dir;
        else
            cout << "Not a valid node address\n";

        cout << endl;
    }
}
