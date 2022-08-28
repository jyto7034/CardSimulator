#include <array>

#include "Includes/Cards/Card.hpp"
#include "Common/Constants.hpp"

namespace CardGame {
class GameConfig {
   public:
    GameConfig() {
        for(int i = 0; i < START_DECK_SIZE; i++){
            player1Deck[i] = nullptr;
            player2Deck[i] = nullptr;
        }
    }

    std::array<Card*, START_DECK_SIZE> player1Deck;
    std::array<Card*, START_DECK_SIZE> player2Deck;
    PlayerType startPlayer = PlayerType::RANDOM;

};
};  // namespace CardGame