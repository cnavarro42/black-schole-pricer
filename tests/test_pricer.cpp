#include <gtest/gtest.h>

#include "pricer/BlackScholesPricer.hpp"
#include "pricer/Option.hpp"
#include "pricer/MarketData.hpp"

TEST(Pricer, CanPriceAnOption)
{
    Option call{OptionType::Call, 100.0, 1.0};
    MarketData marketData{100.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double price = pricer.price(call, marketData);

    EXPECT_TRUE(price > 0.0);
}

TEST(Pricer, ReturnPossitivePriceForCallOption)
{
    Option call{OptionType::Call, 100.0, 1.0};
    MarketData marketData{100.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double price = pricer.price(call, marketData);
    EXPECT_GT(price, 0.0);
}

TEST(Pricer, CallAndPutHaveDifferentPrices)
{
    Option call{OptionType::Call, 100.0, 1.0};
    Option put{OptionType::Put, 100.0, 1.0};

    MarketData marketData{100.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double callPrice = pricer.price(call, marketData);
    double putPrice = pricer.price(put, marketData);
    EXPECT_NE(callPrice, putPrice);
}