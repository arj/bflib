#ifndef BFLIB_INTERVAL_H_
#define BFLIB_INTERVAL_H_

#include <type_traits>
#include <stdexcept>

namespace bflib
{
    template <typename T>
    class Interval
    {
    public:
        static_assert(std::is_arithmetic<T>::value, "Interval must be instantiated with an arithmetic type");

        Interval(const T& left, const T& right)
            : m_left(left), m_right(right)
        {
            if (left > right) {
                throw std::invalid_argument("Invalid interval: left > right");
            }
        }

        bool contains(const T& v)
        {
            return m_left <= v && v <= m_right;
        }

        bool contains(const Interval& other)
        {
            return contains(other.m_left) && contains(other.m_right);
        }

        bool overlaps(const Interval& other)
        {
            return contains(other.m_left) || contains(other.m_right);
        }

        const T& left() const { return m_left; }
        const T& right() const { return m_right; }

    private:
        T m_left;
        T m_right;
    };
}

#endif //BFLIB_INTERVAL_H_
