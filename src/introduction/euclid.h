typedef struct Fraction {
    int numerator;
    int denominator;
} Fraction;
int gcd(int u, int v);
Fraction toLowestTerms(Fraction x);
char * toBinary(int x);