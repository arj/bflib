//
// Created by Robert Jakob on 12/09/17.
//

#ifndef BFLIB_NAIVE_BAYES_H
#define BFLIB_NAIVE_BAYES_H

#include <cassert>

namespace bf {


    // https://web.stanford.edu/class/cs124/lec/naivebayes.pdf
    template <typename Label>
    class ClassifierGaussianNaiveBayes {
    public:
        ClassifierGaussianNaiveBayes();

        void fit(const std::vector<std::vector<double>>& features, const std::vector<Label>& labels) {

            assert(features.size() == labels.size());
            assert(features.size() >= 1);

            std::vector<double> sums(features.front().size(), 0.0);

            for (int i = 0; i<features.size(); ++i) {



            }
        }

        Label predict(const Data& data) const;
    private:
        struct Estimation
        {
            double mean;
            double variance;
        };

        std::vector<Estimation> m_means;
    };

}

#endif //BFLIB_NAIVE_BAYES_H
