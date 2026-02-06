#pragma once

#include <stdexcept>

struct MarketData
{
    double spotPrice;
    double riskFreeRate;
    double volatility;

    MarketData(double spot, double rate, double vol)
        : spotPrice(spot), riskFreeRate(rate), volatility(vol)
    {
        if (spotPrice <= 0.0)
            throw std::invalid_argument("Spot price must be > 0");

        if (volatility <= 0.0)
            throw std::invalid_argument("Volatility must be > 0");

        if (riskFreeRate < 0.0)
            throw std::invalid_argument("Risk-free rate must be >= 0");
    }
};