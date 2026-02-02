#pragma once

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
            : _type(type), _strike(strike), _maturity(maturity) {}
    
        OptionType type() const { return _type; }
        double strike() const { return _strike; }
        double maturity() const { return _maturity; }
};