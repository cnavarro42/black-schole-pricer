#include <iostream>

#include "pricer/BlackScholesPricer.hpp"
#include "pricer/Option.hpp"
#include "pricer/MarketData.hpp"

int main()
{
    double spot;
    double strike;
    double maturity;
    double rate;
    double volatility;
    char type;

    std::cout << "Spot price: ";
    std::cin >> spot;

    std::cout << "Strike: ";
    std::cin >> strike;

    std::cout << "Maturity (years): ";
    std::cin >> maturity;

    std::cout << "Risk-free rate (e.g. 0.05): ";
    std::cin >> rate;

    std::cout << "Volatility (e.g. 0.2): ";
    std::cin >> volatility;

    std::cout << "Option type (C = Call, P = Put): ";
    std::cin >> type;

    OptionType optionType =
        (type == 'C' || type == 'c') ? OptionType::Call : OptionType::Put;

    Option option{optionType, strike, maturity};
    MarketData marketData{spot, rate, volatility};

    BlackScholesPricer pricer;
    double price = pricer.price(option, marketData);

    std::cout << "\nOption price: " << price << std::endl;

    return 0;
}
