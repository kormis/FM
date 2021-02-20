#pragma once

#include<cmath>

namespace SiriusFM {

    class DiffusionCEV {
    private;
        double const m_muBar;
        double const m_sigmaBar;
        double const m_beta;

    public:
        DiffusionCEV(double m, double s, double b) : m_muBar(m),
                                                     m_sigmaBar(s),
                                                     m_beta(b) {
            if (m_sigmaBar <= 0 || m_beta <= 0) {
                throw std::invalid_argument("Diff coef error");
            }
        };

        double mu(double S_t, double t) { return m_muBar * S_t; };

        double sigma(double S_t, double t) {
            return m_sigmaBar * pow(S_t, m_beta);
        };
    };
}
