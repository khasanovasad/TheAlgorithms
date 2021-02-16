#ifndef DS_LIST_H
#define DS_LIST_H

#include <cassert>
#include <initializer_list>

namespace DS
{
    template <typename T> class ListNode
    {
      public:
        ListNode() = default;

        ListNode(const T &element_)
        {
            this->_element = element_;
            this->_next = nullptr;
            this->_prev = nullptr;
        }

        T _element;
        ListNode<T> *_next = nullptr;
        ListNode<T> *_prev = nullptr;
    };

    template <typename T> class ListIterator
    {
      public:
        T &operator*()
        {
            return _v->_element;
        }

        bool operator==(const ListIterator &it) const
        {
            return _v == it._v;
        }

        bool operator!=(const ListIterator &it) const
        {
            return _v != it._v;
        }

        // pre increment
        auto operator++() -> ListIterator &
        {
            _v = _v->_next;
            return *this;
        }

        // pre decrement
        auto operator--() -> ListIterator &
        {
            _v = _v->_prev;
            return *this;
        }

        // post increment
        auto operator++(int) -> ListIterator
        {
            auto tmp = ListIterator(this->_v);
            _v = _v->_next;
            return tmp;
        }

        // post decrement
        auto operator--(int) -> ListIterator
        {
            auto tmp = ListIterator(this->_v);
            _v = _v->_prev;
            return tmp;
        }

        template <typename TU> friend class List;

      private:
        explicit ListIterator(ListNode<T> *node)
        {
            _v = node;
        }

        ListNode<T> *_v;
    };

    template <typename T> class List
    {
      public:
        List()
        {
            InitHeadTail();
        }

        List(std::initializer_list<T> list)
        {
            InitHeadTail();
            for (T elem : list)
            {
                AddBack(elem);
            }
        }

        List(const List &list)
        {
            InitHeadTail();
            for (auto x : list)
            {
                AddBack(x);
            }
        }

        ~List()
        {
            Erase();
            delete _head;
            delete _tail;
        }

        [[nodiscard]] bool IsEmpty() const
        {
            if (_head->_next == _tail && _tail->_prev == _head)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        [[nodiscard]] std::size_t Count() const
        {
            std::size_t size = 0;
            ListNode<T> *tmp = _head->_next;
            while (tmp != _tail)
            {
                tmp = tmp->_next;
                ++size;
            }
            return size;
        }

        void AddFront(const T &toBeAdded)
        {
            AddAt(toBeAdded, begin());
        }

        void AddBack(const T &toBeAdded)
        {
            AddAt(toBeAdded, end());
        }

        void AddAt(const T &toBeAdded, const ListIterator<T> &it)
        {
            auto *newNode = new ListNode<T>(toBeAdded);
            if (!IsEmpty())
            {
                it._v->_prev->_next = newNode;
                newNode->_prev = it._v->_prev;
                it._v->_prev = newNode;
                newNode->_next = it._v;
            }
            else
            {
                _head->_next = newNode;
                newNode->_prev = _head;
                _tail->_prev = newNode;
                newNode->_next = _tail;
            }
        }

        T &Front() const
        {
            return _head->_next->_element;
        }

        T &Back() const
        {
            return _tail->_prev->_element;
        }

        T &At(const ListIterator<T> &it) const
        {
            return it._v->_element;
        }

        T RemoveFront()
        {
            return RemoveAt(begin());
        }

        T RemoveBack()
        {
            return RemoveAt(--end());
        }

        T RemoveAt(const ListIterator<T> &it)
        {
            assert(!IsEmpty());
            assert(it != end());

            it._v->_prev->_next = it._v->_next;
            it._v->_next->_prev = it._v->_prev;

            T deleted = it._v->_element;
            delete it._v;

            return deleted;
        }

        void Erase()
        {
            ListNode<T> *tmp;
            while (_head->_next != _tail)
            {
                tmp = _head->_next;
                _head->_next = tmp->_next;
                delete tmp;
            }
            _tail->_prev = _head;
        }

        auto begin() const -> ListIterator<T>
        {
            return ListIterator<T>(_head->_next);
        }

        auto end() const -> ListIterator<T>
        {
            return ListIterator<T>(_tail);
        }

        /* NEED TO IMPLEMENT */
        void cbegin() const;
        void cend() const;

        void rbegin() const;
        void rend() const;

        void crbegin() const;
        void crend() const;
        /* NEED TO IMPLEMENT */

      private:
        void InitHeadTail()
        {
            _head = new ListNode<T>();
            _tail = new ListNode<T>();
            _head->_next = _tail;
            _head->_prev = nullptr;
            _tail->_prev = _head;
            _tail->_next = nullptr;
        }

        ListNode<T> *_head;
        ListNode<T> *_tail;
    };
} // namespace DS

#endif // DS_LIST_H
