#ifndef BFLIB_SIGNAL_PROCESSING_FFT_H_
#define BFLIB_SIGNAL_PROCESSING_FFT_H_

#include <complex>
#include <valarray>

namespace bflib {

    //! Fast fourier transformation
    void fft(std::valarray<std::complex<double>>& inout);

    //! Inverse fast fourier transformation
    void ifft(std::valarray<std::complex<double>>& inout);
}

#endif // BFLIB_SIGNAL_PROCESSING_FFT_H_
