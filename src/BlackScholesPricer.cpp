#include "pricer/BlackScholesPricer.hpp"

double BlackScholesPricer::price(const Option& option, const MarketData& marketData) const
{
    if (option.type() == OptionType::Call)
    {
        return 10.0; // Dummy for call
    }
    else // Put option
    {
        return 5.0; // Dummy for put
    }
}