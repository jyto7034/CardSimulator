#include "Includes/Game/Game.hpp"

namespace CardGame {

Player* Game::GetPlayer1(){
    return &m_players[0];
}

Player* Game::GetPlayer2(){
    return &m_players[1];
}

void Game::Initialize() {
    for (auto& pl : m_players) 
        pl.game = this;
    
    // Set player type
    GetPlayer1()->playerType = PlayerType::PLAYER1;
    GetPlayer2()->playerType = PlayerType::PLAYER2;

    // Set opponent player
    GetPlayer1()->opponent = GetPlayer2();
    GetPlayer2()->opponent = GetPlayer1();

    state = State::RUNNING;
    for(auto& p : m_players)
        p.state = PlayState::PLAYING;
}

std::array<Card*, START_DECK_SIZE> Game::GetPlayerDeck(PlayerType type) const{
    return type == PlayerType::PLAYER1 ? m_gameConfig.player1Deck 
                                       : m_gameConfig.player2Deck;
}

void Game::SetCurrentPlayer(PlayerType type){
    m_currentPlayer = type;
}

Player* Game::GetCurrentPlayer(){
    if(m_currentPlayer == PlayerType::PLAYER1)
        return &m_players[0];
    return &m_players[1];
}


Game::Game(const GameConfig& gameConfig) : m_gameConfig(gameConfig) {
    Initialize();
}


}  // namespace CardGame