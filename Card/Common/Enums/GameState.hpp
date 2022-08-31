namespace CardGame {
enum class Step {
    INVALID,
    SELECT_GAME_MODE,
    SELECT_CLASS,
    SELECT_DECKS,
    BEGIN_FIRST,
    BEGIN_SUFFLE,
    BEGIN_DRAW,
    BEGIN_MULLIGAN,
    MAIN_BEGIN,
    MAIN_DRAW,
    MAIN_START,
    MAIN_ACTION,
    MAIN_COMBAT,
    MAIN_END,
    MAIN_NEXT,
    MAIN_START_TRIGGER,
    END_GAMEOVER
};

enum class State{
    INVALID,
    LOADING,
    RUNNING,
    COMPLETE
};

enum class PlayState{
    INVALID,
    PLAYING,
    WINNING,
    LOSING,
    WON,
    LOST,
};

enum class ZoneType{
    INVALID,
    DECK,
    HAND,
    USED,
    REVERSE,
    ACTIVE,
    PASSIVE,
    ADDICTIONAL,
    REMOVEDFROMGAME,
};

enum class PlayerType{
    INVALID,
    RANDOM,
    PLAYER1,
    PLAYER2
};


enum class Turn{
    PLAYER1,
    PLAYER2
};

enum class DrawResult{
    SUCCESS,
    EMPTY
};

};