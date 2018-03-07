#include <bflib/signal_processing/filter.h>

#include <cmath>

namespace bflib {

    finite_impulse_response_filter::finite_impulse_response_filter(unsigned int number_of_coefficients)
        : ring_buffer_(number_of_coefficients, 0u)
    {
        for (unsigned int i = 0; i < number_of_coefficients; ++i) {
            coefficients_.push_back(0.5 * std::sin(M_PI/2.0*(i-5)));
        }
    }

    std::vector<double> finite_impulse_response_filter::get_coefficients() const
    {
        return coefficients_;
    }
}
