#ifndef BFLIB_2D_BOUNDING_BOX_H
#define BFLIB_2D_BOUNDING_BOX_H

#include <bflib/math/interval.h>

#include <type_traits>

namespace bflib {

    template <typename T>
    class BoundingBox2D
    {
    public:
        static_assert(std::is_arithmetic<T>::value, "BoundingBox2D must be instantiated with a arithmetic type");

        BoundingBox2D(const T& x1, const T& y1, const T& x2, const T& y2)
                : m_x(x1, x2), m_y(y1, y2)
        {
        }

        bool contains(const T& x, const T& y)
        {
            return m_x.contains(x) && m_y.contains(y);
        }

        const Interval<T>& x() const { return m_x; }
        const Interval<T>& y() const { return m_y; }

        const T& left() const { return m_x.left(); }
        const T& right() const { return m_x.right(); }

        const T& top() const { return m_y.left(); }
        const T& bottom() const { return m_y.right(); }

    private:
        Interval<T> m_x;
        Interval<T> m_y;
    };
}

#endif // BFLIB_2D_BOUNDING_BOX_H
