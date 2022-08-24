#include "Includes/Game/GameConfig.hpp"
#include "Includes/Models/Playable.hpp"
#include "Includes/Models/Entity.hpp"
#include "Includes/Models/Player.hpp"

namespace Card {
class Game {
   public:
    //! Constructor game with default values.
    Game();

    //! Constructor game with given \p gameCofig.
    //! param gameConfig The game config holds all configuration values.
    explicit Game(const GameConfig& gameConfig);

    //! Deleted copy constructor.
    Game(const Game&) = delete;

    //! Deleted move constructor.
    Game(Game&&) noexcept = delete;

    //! Deleted copy assignment operator.
    Game& operator=(const Game&) = delete;

    //! Deleted move assignment operator.
    Game& operator=(Game&&) noexcept = delete;

    //! Initializes the game state and player related variables.
    void Initialize();



   private:
    
};
}  // namespace Card