#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include <stdexcept>

#include "List.hpp"

namespace DS
{
    template <typename T>
    class Queue
    {
      public:
        Queue()
        {
        }

        ~Queue()
        {
        }

        bool IsEmpty()
        {
            return _data.IsEmpty();
        }

        std::size_t Count()
        {
            return _data.Count();
        }

        T& Front()
        {
            return _data.Front();
        }

        T& Back()
        {
            return _data.Back();
        }

        void Push(const T& toBePushed)
        {
            _data.AddBack(toBePushed);
        }

        void Pop()
        {
            if (IsEmpty())
            {
                throw std::runtime_error("QueueUnderflow!");
            }
            _data.RemoveFront();
        }

      private:
        List<T> _data;
    };
} // namespace DS

#endif // DS_QUEUE_H
