#include "pricer/BlackScholesPricer.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

// Función de distribución normal acumulada
static double norm_cdf(double x)
{
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

double BlackScholesPricer::price(const Option& option, const MarketData& marketData) const
{
    double S = marketData.spotPrice;
    double K = option.strike();
    double T = option.maturity();
    double r = marketData.riskFreeRate;
    double vol = marketData.volatility;

    if (T <= 0.0)
        return std::max((option.type() == OptionType::Call ? S - K : K - S), 0.0);

    double sqrtT = std::sqrt(T);
    double d1 = (std::log(S / K) + (r + 0.5 * vol * vol) * T) / (vol * sqrtT);
    double d2 = d1 - vol * sqrtT;

    double callPrice = S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);

    if (option.type() == OptionType::Call)
    {
        return callPrice;
    }
    else // Put usando paridad Call-Put
    {
        return callPrice - S + K * std::exp(-r * T);
    }
}
