#include <iostream>
#include <string>

#include "pricer/BlackScholesPricer.hpp"
#include "pricer/Option.hpp"
#include "pricer/MarketData.hpp"

bool readPositiveDouble(const std::string& label, double& value, bool allowZero = false)
{
    std::cout << label;
    std::cin >> value;

    if (!std::cin)
    {
        std::cerr << "Invalid input (not a number).\n";
        return false;
    }

    if (allowZero)
    {
        if (value < 0.0)
        {
            std::cerr << "Value must be >= 0.\n";
            return false;
        }
    }
    else
    {
        if (value <= 0.0)
        {
            std::cerr << "Value must be > 0.\n";
            return false;
        }
    }

    return true;
}

int main()
{
    double spot, strike, maturity, rate, volatility;
    char type;

    if (!readPositiveDouble("Spot price: ", spot)) return 1;
    if (!readPositiveDouble("Strike: ", strike)) return 1;
    if (!readPositiveDouble("Maturity (years): ", maturity)) return 1;
    if (!readPositiveDouble("Risk-free rate (e.g. 0.05): ", rate, true)) return 1;
    if (!readPositiveDouble("Volatility (e.g. 0.2): ", volatility)) return 1;

    std::cout << "Option type (C = Call, P = Put): ";
    std::cin >> type;

    if (!std::cin || (type != 'C' && type != 'c' && type != 'P' && type != 'p'))
    {
        std::cerr << "Invalid option type. Use C or P.\n";
        return 1;
    }

    OptionType optionType =
        (type == 'C' || type == 'c') ? OptionType::Call : OptionType::Put;

    Option option{optionType, strike, maturity};
    MarketData marketData{spot, rate, volatility};

    BlackScholesPricer pricer;
    double price = pricer.price(option, marketData);

    std::cout << "\nOption price: " << price << std::endl;

    return 0;
}
