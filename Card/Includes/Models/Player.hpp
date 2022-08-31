#include "Includes/Models/Entity.hpp"

#include <vector>
#include <memory>

namespace CardGame {
class Player : public Entity {
    public:
    std::vector<Card*> m_cards;
    Player* opponent;
    PlayerType playerType;
    PlayState state;
    Game* game;

    
};
}  