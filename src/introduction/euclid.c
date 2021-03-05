#include "euclid.h"

/**
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * gcd
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Finds the greatest common divisor of two numbers given in order of size
 * descending (larger first), here named dividend and divisor.
 * 
 * This function takes inspiration from page 8 of "Algorithms in C" while
 * making use of the suggested modification on page 24 to use the modulo 
 * operator instead of iterative deletion of u - v (e.g., dividend - divisor).
 * 
 * @param dividend, the greater of the two integers (if they are not equal)
 * @param divisor, the lesser of the two integers (if they are not equal)
 * @return greatest common divisor on success, -1 on failure
 * 
 */
int gcd(int dividend, int divisor) 
{
    // create a temporary variable to hold the arithmetic outcome
    // of our modulo operation
    int newDivisor = -1;
    
    // failure case - either argument is 0 or less
    if (dividend <= 0 || divisor <= 0) {
        return -1;
    }

    // handle mis-ordering of the arguments, just in case
    // the user does not follow instructions
    if (dividend < divisor) {
        newDivisor = dividend;
        dividend = divisor;
        divisor = newDivisor;
    }

    // iteratively compute the modulo until the divisor reaches 0
    // at which point the gcd will be held in dividend 
    // thanks to Euclid's algorithm
    while (divisor > 0) 
    {
        newDivisor = dividend % divisor;
        dividend = divisor;
        divisor = newDivisor;
    }
    return dividend;
}


/**
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * toLowestTerms
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Returns the lowest terms of a given Fraction, assuming the Fraction
 *  contains a valid numerator and denominator.
 * 
 * @param x; the Fraction to reduce
 * @returns reduced Fraction in its lowest terms
 */
Fraction toLowestTerms(Fraction x) {
    // find the gcd
    int divisor = gcd(x.denominator, x.numerator);

    // if call to gcd() fails, simply return the original input
    if (divisor == -1) {
        return x;
    }

    // divide each 
    x.numerator = x.numerator / divisor;
    x.denominator = x.denominator / divisor;

    return x;
}
