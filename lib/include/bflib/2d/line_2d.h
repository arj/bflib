#ifndef BFLIB_LINE_2D_H
#define BFLIB_LINE_2D_H

#include <cmath>

namespace bflib {

    class Line2D
    {
    public:
        static Line2D from_points(double x1, double y1, double x2, double y2) {
            // TODO Null check!
            double m = (y2-y1) / (x2-x1);
            double b = y1 - m*x1;

            return Line2D(m,b);
        }

        static Line2D from_cartesian(double m, double b) {
            return Line2D(m,b);
        }

        static Line2D from_polar(double r, double theta) {
            double sin_theta = std::sin(theta);

            if (sin_theta == 0.0) {
                return Line2D(0, 0);
            } else {
                double m = -std::cos(theta) / std::sin(theta);
                double b = r / sin_theta;
                return Line2D(m,b);
            }

        }

        double m() const { return m_m; }
        double b() const { return m_b; }

        double eval(double x) {
            return m_m*x + m_b;
        }

        double inverse_eval(double y) {
            return (y - m_b)/m_m;
        }

    private:

        Line2D(double m, double b)
        : m_m(m), m_b(b)
        {}

        double m_m;
        double m_b;
    };

}

#endif //BFLIB_LINE_2D_H
