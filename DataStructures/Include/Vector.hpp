#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include <cassert>

namespace DS
{
    template <typename T> class Vector
    {
      public:
        Vector(std::size_t initCapacity)
        {
            if (initCapacity == 0)
            {
                initCapacity = 4;
            }

            _data = new T[initCapacity];
            _capacity = initCapacity;
            _length = 0;
        }

        Vector(std::size_t initCapacity, const T &defValue)
        {
            if (initCapacity == 0)
            {
                initCapacity = 4;
            }

            _data = new T[initCapacity];
            _capacity = initCapacity;
            _length = 0;

            for (std::size_t i = 0; i < Capacity(); ++i)
            {
                _data[i] = defValue;
            }
        }

        ~Vector()
        {
            delete[] _data;
            _data = nullptr;
        }

        bool IsEmpty() const
        {
            return Length() == 0;
        }

        std::size_t Length() const
        {
            return _length;
        }

        std::size_t Capacity() const
        {
            return _capacity;
        }

        void AddBack(const T &toBeAdded)
        {
            AddAt(toBeAdded, Length());
        }

        void AddFront(const T &toBeAdded)
        {
            AddAt(toBeAdded, 0);
        }

        void AddAt(const T &toBeAdded, std::size_t index)
        {
            assert(index < Length() + 1);

            Resize();
            for (std::size_t i = Length(); i > index; --i)
            {
                _data[i] = _data[i - 1];
            }
            _data[index] = toBeAdded;
            ++_length;
        }

        T &Back() const
        {
            return At(Length() - 1);
        }

        T &Front() const
        {
            return At(0);
        }

        T &At(std::size_t index) const
        {
            assert(Length() != 0);
            assert(index < Length());
            return _data[index];
        }

        T RemoveBack()
        {
            RemoveBack(Length() - 1);
        }

        T RemoveFront()
        {
            RemoveAt(0);
        }

        T RemoveAt(std::size_t index)
        {
            assert(Length() != 0);
            assert(index < Length());

            Resize();
            for (std::size_t i = index; i < Length() - 1; ++i)
            {
                _data[i] = _data[i + 1];
            }
            --_length;
        }

        void ShrinkToFit()
        {
            _capacity = Length();
            T *tmp = new T[Capacity()];

            for (std::size_t i = 0; i < Length(); ++i)
            {
                tmp[i] = _data[i];
            }

            delete[] _data;
            _data = tmp;
        }

      private:
        T *_data = nullptr;
        std::size_t _length;
        std::size_t _capacity;

        void Resize()
        {
            if (Length() == Capacity())
            {
                T *tmp = new T[Capacity() + Capacity() / 2];

                for (std::size_t i = 0; i < Length(); ++i)
                {
                    tmp[i] = _data[i];
                }

                delete[] _data;
                _data = tmp;
                _capacity += Capacity() / 2;
            }
        }
    };
} // namespace DS

#endif // DS_VECTOR_H
