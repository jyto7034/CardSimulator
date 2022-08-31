

namespace CardGame{

enum class ZoneNums : int  {
#define X(a) a,
#include "Common/Enums/ZoneEnums.def"
#undef X
};

}