#ifndef BFLIB_SIGNAL_PROCESSING_FILTER_H_
#define BFLIB_SIGNAL_PROCESSING_FILTER_H_

#include <deque>
#include <vector>

namespace bflib {

    class finite_impulse_response_filter
    {
    public:
        finite_impulse_response_filter(unsigned int number_of_coefficients);

        std::vector<double> get_coefficients() const;

    private:
        std::vector<double> coefficients_;
        std::deque<double> ring_buffer_;
    };

}

#endif // BFLIB_SIGNAL_PROCESSING_TREE_H_
