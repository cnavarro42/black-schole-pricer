#include "pricer/BlackScholesPricer.hpp"
#include <iostream>
double BlackScholesPricer::price(const Option& option, const MarketData& marketData) const
{
    if (option.type() == OptionType::Call)
    {
        return std::max(marketData.spotPrice - option.strike(), 0.0) * marketData.volatility * option.maturity() * marketData.riskFreeRate; // Dummy for call
    }
    else // Put option
    {
        return  std::max(option.strike() - marketData.spotPrice, 0.0) * marketData.volatility * option.maturity() / marketData.riskFreeRate; // Dummy for put
    }
}