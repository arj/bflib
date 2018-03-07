//
// Created by Robert Jakob on 14/09/17.
//

#ifndef BFLIB_NORMAL_DISTRIBUTION_H
#define BFLIB_NORMAL_DISTRIBUTION_H

#include <cmath>
#include <numeric>

namespace bf {

    class normal_distribution {
    public:

        normal_distribution(double mean, double variance)
            : m_mean(mean), m_variance(variance) {

        }

        double mean() const { return m_mean; }
        double variance() const { return m_variance; }
        double standard_deviation() const { return std::sqrt(m_variance); }

        double probability_density(double value) const {
            static auto pi = std::atan(1)*4;

            double factor = std::sqrt(2.0 * pi * m_variance);

            double exponent = std::pow(value - m_mean, 2.0) / (2.0 * m_variance);

            return std::exp(-exponent) / factor;
        }

        double cumulative_density(double value) const {
            double x = value;
            double sum = value;

            for (int i = 0; i <= 100; ++i) {
                value = (value*x*x/(2.0*i+1.0));
                sum = sum+value;
            }

            static auto pi = std::atan(1)*4;
            return 0.5+(sum/std::sqrt(2*pi))*std::exp(-(x*x)/2);
        }

        //! Create a standard normal distribution with mean = 0.0 and standard deviation = 1.0
        //!
        static normal_distribution standard() {
            return normal_distribution(0.0, 1.0);
        }

        //! Estimate the normal distribution based on a set of data using maximum likelihood estimation.
        //! \param data A list of data.
        //! \return The estimated distribution.
        //!
        static normal_distribution ml_estimation(const std::vector<double>& data) {
            auto sum = std::accumulate(data.cbegin(), data.cend(), 0.0);
            double estimated_mean = sum / data.size();


            auto add_mean_subtract = [=](double acc, double v) { return acc + (v - estimated_mean) * (v - estimated_mean); };

            sum = std::accumulate(data.cbegin(), data.cend(), 0.0, add_mean_subtract);
            double estimated_variance = sum / data.size();

            return normal_distribution(estimated_mean, estimated_variance);
        }

    private:
        double m_mean;
        double m_variance;
    };

}

#endif //BFLIB_NORMAL_DISTRIBUTION_H
