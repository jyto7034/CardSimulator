#include "Includes/Game/Game.hpp"

namespace CardGame {

Player* Game::GetPlayer1() { return &m_players[0]; }

Player* Game::GetPlayer2() { return &m_players[1]; }

void Game::Initialize() {
    for (auto& pl : m_players) pl.game = this;

    // Set player type
    GetPlayer1()->playerType = PlayerType::PLAYER1;
    GetPlayer2()->playerType = PlayerType::PLAYER2;

    // Set opponent player
    GetPlayer1()->opponent = GetPlayer2();
    GetPlayer2()->opponent = GetPlayer1();

    state = State::RUNNING;
    for (auto& p : m_players) p.state = PlayState::PLAYING;
}

std::array<Card*, START_DECK_SIZE> Game::GetPlayerDeck(PlayerType type) const {
    return type == PlayerType::PLAYER1 ? m_gameConfig.player1Deck
                                       : m_gameConfig.player2Deck;
}

void Game::SetCurrentPlayer(PlayerType type) { m_currentPlayer = type; }

Player* Game::GetCurrentPlayer() {
    if (m_currentPlayer == PlayerType::PLAYER1) return &m_players[0];
    return &m_players[1];
}

Game::Game(const GameConfig& gameConfig) : m_gameConfig(gameConfig) {
    Initialize();
}

void Game::BeginFirst() {
    
    
}
void Game::BeginSuffle() {
    for(auto& pl : m_players){
        std::reverse(
            std::begin(GetPlayerDeck(pl.playerType)),
            std::end(GetPlayerDeck(pl.playerType))
        );
    }
}
void Game::BeginDraw() {
    
}
void Game::BeginMulligan() {}
void Game::MainReady() {}
void Game::MainStartTrigger() {}
void Game::MainResource() {}
void Game::MainDraw() {}
void Game::MainStart() {}
void Game::MainAction() {}
void Game::MainEnd() {}
void Game::MainCleanUp() {}
void Game::MainNext() {}
void Game::FinalWrapUp() {}
void Game::FinalGameOver(){}
void Game::ProcessTasks(){}
void Game::ProcessGraveyard(){}

std::tuple<PlayState, PlayState> Process(Player* player,
                                         std::unique_ptr<ITask> task){}
std::tuple<PlayState, PlayState> Process(Player* player, ITask&& task){}

}  // namespace CardGame