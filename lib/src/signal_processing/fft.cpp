#include <bflib/signal_processing/fft.h>

#include <complex>
#include <vector>

namespace bf {

    void fft(std::valarray<std::complex<double>>& inout)
    {
#ifdef BF_USE_COOLEY_TUKEY_FFT
        // DFT
        unsigned int N = inout.size(), k = N, n;
        double thetaT = 3.14159265358979323846264338328L / N;
        std::complex<double> phiT(cos(thetaT), sin(thetaT));
        std::complex<double> T;
        while (k > 1)
        {
            n = k;
            k >>= 1;
            phiT = phiT * phiT;
            T = 1.0L;
            for (unsigned int l = 0; l < k; l++)
            {
                for (unsigned int a = l; a < N; a += n)
                {
                    unsigned int b = a + k;
                    std::complex<double> t = inout[a] - inout[b];
                    inout[a] += inout[b];
                    inout[b] = t * T;
                }
                T *= phiT;
            }
        }
        // Decimate
        unsigned int m = (unsigned int)log2(N);
        for (unsigned int a = 0; a < N; a++)
        {
            unsigned int b = a;
            // Reverse bits
            b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
            b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
            b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
            b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
            b = ((b >> 16) | (b << 16)) >> (32 - m);
            if (b > a)
            {
                std::complex<double> t = inout[a];
                inout[a] = inout[b];
                inout[b] = t;
            }
        }
#else
        const size_t N = inout.size();
        if (N <= 1) return;

        // divide
        std::valarray<std::complex<double>> even = inout[std::slice(0, N/2, 2)];
        std::valarray<std::complex<double>>  odd = inout[std::slice(1, N/2, 2)];

        // conquer
        fft(even);
        fft(odd);

        // combine
        for (size_t k = 0; k < N/2; ++k)
        {
            std::complex<double> t = std::polar(1.0, -2 * M_PI * k / N) * odd[k];
            inout[k    ] = even[k] + t;
            inout[k+N/2] = even[k] - t;
        }
#endif
    }

    void ifft(std::valarray<std::complex<double>>& inout)
    {
        // conjugate the complex numbers
        inout = inout.apply(std::conj);

        // forward fft
        fft(inout);

        // conjugate the compleinout numbers again
        inout = inout.apply(std::conj);

        // scale the numbers
        inout /= inout.size();
    }

}
