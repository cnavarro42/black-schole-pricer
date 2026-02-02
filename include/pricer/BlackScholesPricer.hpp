#pragma once

#include "Option.hpp"
#include "MarketData.hpp"

class BlackScholesPricer 
{
    public:
        double price(const Option& option, const MarketData& marketData) const
        {
            return 1.0; // Placeholder implementation
        }
};