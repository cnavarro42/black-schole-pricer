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

    EXPECT_GE(price, 0.0);
}

TEST(Pricer, ReturnPossitivePriceForCallOption)
{
    Option call{OptionType::Call, 100.0, 1.0};
    MarketData marketData{100.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double price = pricer.price(call, marketData);
    EXPECT_GE(price, 0.0);
}

TEST(Pricer, CallAndPutHaveDifferentPrices)
{
    Option call{OptionType::Call, 100.0, 1.0};
    Option put{OptionType::Put, 100.0, 1.0};

    MarketData marketData{120.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double callPrice = pricer.price(call, marketData);
    double putPrice = pricer.price(put, marketData);
    EXPECT_NE(callPrice, putPrice);
}

TEST(Pricer, CallPriceIncreaseWithSpotPrice)
{
    Option call{OptionType::Call, 100.0, 1.0};

    MarketData marketDataLow{90.0, 0.05, 0.2};
    MarketData marketDataHigh{110.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double lowPrice = pricer.price(call, marketDataLow);
    double highPrice = pricer.price(call, marketDataHigh);

    EXPECT_LT(lowPrice, highPrice);
}

TEST(Pricer, PutPriceDecreaseWithSpotPrice)
{
    Option put{OptionType::Put, 100.0, 1.0};

    MarketData marketDataLow{90.0, 0.05, 0.2};
    MarketData marketDataHigh{110.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double lowPrice = pricer.price(put, marketDataLow);
    double highPrice = pricer.price(put, marketDataHigh);

    EXPECT_GT(lowPrice, highPrice);
}

TEST(Pricer, CallPriceDecreasewithStrike)
{
    Option callLowStrike{OptionType::Call, 90.0, 1.0};
    Option callHighStrike{OptionType::Call, 110.0, 1.0};

    MarketData marketData{100.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double lowStrikePrice = pricer.price(callLowStrike, marketData);
    double highStrikePrice = pricer.price(callHighStrike, marketData);

    EXPECT_GT(lowStrikePrice, highStrikePrice);
}

TEST(Pricer, PutPriceIncreasewithStrike)
{
    Option putLowStrike{OptionType::Put, 90.0, 1.0};
    Option putHighStrike{OptionType::Put, 110.0, 1.0};

    MarketData marketData{100.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double lowStrikePrice = pricer.price(putLowStrike, marketData);
    double highStrikePrice = pricer.price(putHighStrike, marketData);

    EXPECT_LT(lowStrikePrice, highStrikePrice);
}

TEST(Pricer, CallPriceIncreaseWithVolatility)
{
    Option call{OptionType::Call, 100.0, 1.0};

    MarketData marketDataLowVol{150.0, 0.05, 0.1};
    MarketData marketDataHighVol{150.0, 0.05, 0.3};

    BlackScholesPricer pricer;

    double lowVolPrice = pricer.price(call, marketDataLowVol);
    double highVolPrice = pricer.price(call, marketDataHighVol);

    EXPECT_LT(lowVolPrice, highVolPrice);
}

TEST(Pricer, PutPriceIncreaseWithVolatility)
{
    Option put{OptionType::Put, 100.0, 1.0};

    MarketData marketDataLowVol{50.0, 0.05, 0.1};
    MarketData marketDataHighVol{50.0, 0.05, 0.3};

    BlackScholesPricer pricer;

    double lowVolPrice = pricer.price(put, marketDataLowVol);
    double highVolPrice = pricer.price(put, marketDataHighVol);

    EXPECT_LT(lowVolPrice, highVolPrice);
}

TEST(Pricer, CallPriceIncreaseWithMaturity)
{
    Option shortMaturityCall{OptionType::Call, 100.0, 0.5};
    Option longMaturityCall{OptionType::Call, 100.0, 2.0};

    MarketData marketData{120.0, 0.05, 0.2};

    BlackScholesPricer pricer;

    double shortMaturityPrice = pricer.price(shortMaturityCall, marketData);
    double longMaturityPrice = pricer.price(longMaturityCall, marketData);

    EXPECT_LT(shortMaturityPrice, longMaturityPrice);
}