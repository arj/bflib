//
// Created by Robert Jakob on 14/09/17.
//

#ifndef BFLIB_ESTIMATOR_H
#define BFLIB_ESTIMATOR_H

#include <numeric>

namespace bf {
    namespace normal_distribution {

        template <typename T>
        T mean_estimator(const std::vector<T>& data) {
            auto add = [](const T& a, const T& b) { return a + b; };

            auto sum = std::accumulate(data.cbegin(), data.cend(), T{}, add);

            return sum / data.size();
        }
    }
}

#endif //BFLIB_ESTIMATOR_H
