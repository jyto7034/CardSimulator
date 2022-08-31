#include <array>

#include "Common/Enums/GameState.hpp"
#include "Includes/Game/GameConfig.hpp"
#include "Includes/Manager/TriggerManager.hpp"
#include "Includes/Models/Entity.hpp"
#include "Includes/Models/Playable.hpp"
#include "Includes/Models/Player.hpp"
#include "Includes/Tasks/SimpleTasks/AttackTask.hpp"
#include "Includes/Tasks/TaskQueue.hpp"
#include "Common/Enums/CardClass.hpp"

#include <algorithm>

namespace CardGame {
class Game {
   public:
    //! 기본 생성자 입니다.
    Game();

    //! \p gameCofig 으로 초기화 되는 생성자입니다.
    //! \param gameConfig 게임의 설정값을 가집니다.
    explicit Game(const GameConfig& gameConfig);

    //! 복사 생성자를 비활성화 시킵니다.
    Game(const Game&) = delete;

    //! 이동 생성자를 비활성화 시킵니다.
    Game(Game&&) noexcept = delete;

    //! 복사 대입 생성자를 비활성화 시킵니다.
    Game& operator=(const Game&) = delete;

    //! 이동 대입 생성자를 비활성화 시킵니다.
    Game& operator=(Game&&) noexcept = delete;

    //! 플레이어와 관련된 변수들을 초기화합니다.
    void Initialize();

    //! Return the first player 
    //! \Return the first player 
    Player* GetPlayer1();

    //! Return the second player 
    //! \Return the second player 
    Player* GetPlayer2();

    //! Returns the play controlling the current turn
    //! \Returns the play controlling the current turn
    Player* GetCurrentPlayer();
    
    //! Set the player controlling the current turn
    //! \param type The player type controlling the current turn.
    void SetCurrentPlayer(PlayerType);


    //! 게임 진행 함수
    void BeginFirst();

    //! 게임 진행 함수
    void BeginSuffle();
    
    //! 게임 진행 함수
    void BeginDraw();
    
    //! 게임 진행 함수
    void BeginMulligan();
    
    //! 게임 진행 함수
    void MainReady();

    //! 게임 진행 함수
    void MainStartTrigger();

    //! 게임 진행 함수
    void MainResource();

    //! 게임 진행 함수
    void MainDraw();

    //! 게임 진행 함수
    void MainStart();

    //! 게임 진행 함수
    void MainAction();

    //! 게임 진행 함수
    void MainEnd();

    //! 게임 진행 함수
    void MainCleanUp();

    //! 게임 진행 함수
    void MainNext();

    //! 게임 진행 함수
    void FinalWrapUp();

    //! 게임 진행 함수
    void FinalGameOver();

    //! Task Queue 를 처리합니다.
    void ProcessTasks();

    //! 카드를 무덤으로 옮깁니다.
    void ProcessGraveyard();

    //! Task 를 직접 수행합니다.
    //! \param player Task 를 수행시킬 주체입니다.
    //! \param task 실행 될 Task 입니다.
    //! \return 게임의 결과를 리턴 합니다. (player1 and player2).
    std::tuple<PlayState, PlayState> Process(Player* player,
                                             std::unique_ptr<ITask> task);
                                             
    //! Task 를 직접 수행합니다.
    //! \param player Task 를 수행시킬 주체입니다.
    //! \param task 실행 될 Task 입니다.
    //! \return 게임의 결과를 리턴 합니다. (player1 and player2).
    std::tuple<PlayState, PlayState> Process(Player* player, ITask&& task);

    
    //! 라운드마다 사용된 카드를 로그로 저장합니다.
    std::vector<std::vector<std::pair<PlayerType, Card*> > > PlayHistory;

    //! 플레이어의 덱을 받습니다.
    //! \param PayerType 플레이어의 종류입니다.
    std::array<Card*, START_DECK_SIZE> GetPlayerDeck(PlayerType) const;
   
    TaskQueue taskQueue;
    TriggerManager TriggerManager;
    State state;

   private:
    std::array<Player, 2> m_players;

    GameConfig m_gameConfig;
    PlayerType m_currentPlayer = PlayerType::INVALID;
};
}  // namespace CardGame