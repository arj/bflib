#ifndef BFLIB_CONTRACTS_H
#define BFLIB_CONTRACTS_H

#include <exception>

namespace bflib {

    inline void Precondition(bool assert_condition, const char* message = "") {
        if (!assert_condition) {
            std::string s(message);
            throw std::domain_error("Precondition failed: " + message);
        }
    }

}

#endif //BFLIB_CONTRACTS_H
