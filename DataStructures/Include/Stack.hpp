#ifndef DS_STACK_H
#define DS_STACK_H

#include <stdexcept>

#include "List.hpp"

namespace DS
{
    template <typename T>
    class Stack
    {
      public:
        Stack()
        {
        }

        ~Stack()
        {
        }

        T &Top()
        {
            return _data.Back();
        }

        bool IsEmpty()
        {
            return _data.IsEmpty();
        }

        std::size_t Count()
        {
            return _data.Count();
        }

        void Push(const T &toBePushed)
        {
            _data.AddBack(toBePushed);
        }

        void Pop()
        {
            if (_data.Count() == 0)
            {
                throw std::runtime_error("StackUnderflow!");
            }
            _data.RemoveBack();
        }

      private:
        List<T> _data;
    };
} // namespace DS

#endif // DS_STACK_H
