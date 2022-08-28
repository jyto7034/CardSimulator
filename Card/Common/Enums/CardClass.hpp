#include "Common/Constants.hpp"

#include <map>
#include <string>

namespace CardGame{
enum class CardClass : int{
#define X(a) a,
#include "CardClassID.def"
#undef X
};


const std::string CARD_CLASS_STR_EN[] = {
#define X(a) #a,
#include "CardClassNameEn.def"
#undef X
};

}