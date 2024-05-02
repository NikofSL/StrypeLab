#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

int main()
{
    std::cout << std::fixed << std::setprecision( std::numeric_limits<double>::digits10 ) ;

    const double d = 1'000'000.0 ;
    const double first = d  - 0.000'000'1 ;
    const double second = d + 0.000'000'1 ;

    std::cout << "compare " << first << "\nand    " << second << '\n' ;

    // 1. absolute difference
    std::cout << "absolute difference: " << std::abs(first-second) << '\n' ;


    // 2. relative difference: the general method to check if two values are 'close enough'
    // but it may bomb horribly in the presence of catastrophic cancellation
    std::cout << "relative difference: "
              << std::abs(first-second) / std::min( std::abs(first), std::abs(second) ) * 100.0 << " %\n" ;
    // TO DO: handle special cases (zero, NaN, inf, denormalised)


    // 3. float distance: count of how many representable floating-point values lie between the two values
    // an accurate measure, but usable only when the two values are expected to be very close to each other
    const double lower = std::min(first,second) ;
    const double higher = std::max(first,second) ;
    unsigned long long dist = 0 ;
    for( double from = lower ; from < higher ; ++dist ) from = std::nexttoward( from, higher+100 ) ;
    std::cout << "float distance: " << dist << '\n' ;
}
