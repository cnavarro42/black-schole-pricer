#pragma once

#include "MarketData.hpp"

enum class OptionType 
{
    Call,
    Put
};

class Option 
{
    private:
        OptionType _type;
        double _strike;
        double _maturity;

    public:
        Option(OptionType type, double strike, double maturity)
            : _type(type), _strike(strike), _maturity(maturity) 
            {
                if (strike <= 0.0)
                    throw std::invalid_argument("Strike must be > 0.");
                if (maturity <= 0.0)
                    throw std::invalid_argument("Maturity must be > 0.");
            }
    
        OptionType type() const { return _type; }
        double strike() const { return _strike; }
        double maturity() const { return _maturity; }
};