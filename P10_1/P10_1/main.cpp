/*
 Exercise P10.1.
 If a string has n letters, then the number of permutations is given by the factorial function:
 n! = 1 × 2 × 3 × ... × n
 For example,
 3! = 1 × 2 × 3 = 6 and there are six permutations of the three-character
 string "eat". Implement a recursive factorial function, using the definitions
 n! = (n − 1)! × n
 and
 0! = 1
*/

#include <iostream>

using namespace std;

int factorial(int n);

int main(int argc, const char * argv[]) {
    int n = 2;
    while (n < 10){
        int f = factorial(n);
        cout << n << "! = " << f << endl;
        n++;
    }
    return 0;
}

int factorial(int n){
    if (n == 0) return 1;
    else return n * factorial(n-1);
}
