
/**
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * gcd
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Finds the greatest common devisor of two integers, u and v. 
 * 
 * See: pg 8, Algorithms in C
 * 
 * Makes use of Euclid's observation in Elements that the greatest common
 * divisor of u and v is the same as the greatest common divisor of v and
 * u - v.
 * 
 * See also: https://www.khanacademy.org/computing/computer-science/
 * cryptography/modarithmetic/a/the-euclidean-algorithm
 * 
 */
int gcd(int u, int v) 
{

    // handle 0-cases gracefully
    if ( u == 0 ) {
        return v;
    }
    if ( v == 0 ) {
        return u;
    }
    
    if ( u < 0 || v < 0 ) {
        return 0;
    }
    int t;
    while (u > 0) 
    {
        // ensure that u >= v by exchanging values, if necessary
        if (u < v)
        {
            t = u; 
            u = v; 
            v = t;
        }
        u = u - v;
    }
    return v;
}
