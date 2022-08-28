#include "Includes/Tasks/ITask.hpp"

#include <memory>
#include <queue>

namespace CardGame{
class TaskQueue{
    public:
    TaskQueue() = default;
    std::queue<std::unique_ptr<ITask>>& GetCurrentQueue();
    
    private:
    std::queue<std::unique_ptr<ITask>> m_Queue;
};
};