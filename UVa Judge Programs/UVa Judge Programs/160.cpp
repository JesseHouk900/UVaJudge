/*//////////////////////////////////////////////////////////////////////////////
*	Jesse Houk :   Factors and Factorials :   160 :   euclid5
*
*	Data Structures : bitset, vector
*
*	Tricks of the Trade : use the sieve of Eratosthenes 
*
*	Problem : given a integer, N, find the number of times each prime can divide N.
*
*	Runtime : 0.000
//////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm> // fill
#include <iomanip>

using namespace std;

const long long numbers = 1000001;
bitset<numbers - 1> primes;
vector<int> numDivisors(numbers, 0);

void SieveOfE();
bool isPrime(long long n);
void findNumberOfPrimeDivisors(int N);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    long long a, b;
    SieveOfE();
    while (cin >> N && N != 0) {
        findNumberOfPrimeDivisors(N);
        
        cout << setw(3) << right << N << "! =";
        if (numDivisors[2] != 0) {
            cout << setw(3) << right << numDivisors[2];
        }
        int count = 1;
        for (int i = 3, d = 3; i < numbers; i++) {
            if (numDivisors[i] != 0) {
                if (d == 9) {
                    cout << '\n';
                }
                cout << setw(d) << right << numDivisors[i];
                d = 3;
                count++;
                if (count % 15 == 0) {
                     d = 9;
                }
            }
        }
        cout << '\n';
        fill(numDivisors.begin(), numDivisors.end(), 0);
    }
}
// using predefined constants and a global bitset, mark all of the prime numbers
void SieveOfE() {
    // consider all numbers prime
    primes.set();
    // declare 0 and 1 to be non prime
    primes[0] = primes[1] = 0;
    // consider all numbers from 2 to numbers...
    for (long long i = 2; i <= numbers; i++) {
        // if that number is still considered a prime...
        if (primes[i]) {
            // begin observing the multiples of that number
            for (long long j = i * i; j <= numbers; j += i) {
                // and mark them as non-prime
                primes[j] = 0;
            }
        }
    }
}
// return whether a number is prime or not
bool isPrime(long long n) {
    // if the prime has been previously calculated
    if (n < numbers) {
        // return it's stored value
        return primes[n];
    }
    return false;
}
void findNumberOfPrimeDivisors(int N) {
    int temp;
    for (int i = N; i > 1; i--) {
        temp = i;
        for (int j = 2; j <= i; j++) {
            while (isPrime(j) && temp % j == 0) {
                temp /= j;
                numDivisors[j]++;
            }
        }
    }
}