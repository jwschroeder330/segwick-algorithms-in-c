
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
