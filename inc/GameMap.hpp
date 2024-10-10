#include <string>
#include <Node.hpp>

using namespace std;

namespace chants
{
    class GameMap
    {
    private:
        vector<Node> locations;

        void buildMapNodes();

    public:
        GameMap();
    };
}