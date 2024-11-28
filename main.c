#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This function should return 1 if x is prime and 0 otherwise */
int isPrime(int x){
    if (x <= 1) return 0; // Numbers less than or equal to 1 are not prime
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0; // If divisible by any number other than 1 and itself 3%2=2
    }
    return 1; // Prime number
}

/* This function should return 1 if gcd(x,2)=1 and 0 otherwise, it is odd if x%2!=0 */
int isGcd1(int x){
    return (x % 2 != 0) ? 1 : 0; // Return 1 if x is odd, otherwise 0
}

/* This function should return 1 if 9^x-2 mod 5 = 2 and 0 otherwise (Every other from x=1 is true)
 * This function should return 1 if 9^x-2 divided 5 has a rest of 2 else return 0.
 */

int is2mod5(int x){
    int mod_result = 1;
    for (int i = 0; i < x; i++) {
        mod_result = (mod_result * 9) % 5;
    }
    return ((mod_result - 2) % 5 == 2) ? 1 : 0;
}

int main(void){
    int x;
    int p, q, r;

    printf("What number do you want to test?\n");
    scanf("%d", &x);
    printf("x is %d\n", x);

    p = isPrime(x);
    q = isGcd1(x);
    r = is2mod5(x);

    if ((p && !r) || !(p || !q || r) || (!p && !q && r)){
        printf("You have found a valid x\n");
        printf("p is %d, q is %d, and r is %d\n", p,q,r);
    } else {
        printf("Try again!\n");
    }

    return EXIT_SUCCESS;
}
