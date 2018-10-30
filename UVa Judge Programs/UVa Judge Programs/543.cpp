/*//////////////////////////////////////////////////////////////////////////////
*	Jesse Houk :   Goldbach's Conjecture :   543 :   euclid5
*
*	Data Structures : bitset
*
*	Tricks of the Trade : use the sieve of Eratosthenes and a little algebra, 
        ie. N = p1 + p2 where p1, p2 are primes. p1 = N - p2 is more easily 
        calculated.
*
*	Problem : Reading in any even number, N, determine which primes add up
        to equal N such that their difference is maximal.
*
*	Runtime : 0.010			Eh
//////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <bitset>

using namespace std;

// the stopping point for the sieve
const long long numbers = 1000001;
// a bitset that will be used to mark all prime numbers
bitset<numbers - 1> primes;

// used to find all primes within a range
void SieveOfE();
// determine if a number, n, is prime
bool isPrime(long long n);
// return pair of prime numbers that add up to N
pair<long long, long long> findMaxGodlbachNumber(int N);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // variable for even numbers that are read in
    int N;
    // mark the prime numbers
    SieveOfE();
    // read in all the input and watch for the sentinal
    while (cin >> N && N != 0) {
        // store the pair of prime numbers that add to N as AB
        pair<long long, long long> AB = findMaxGodlbachNumber(N);
        // as long as there is a valid pair of primes that add to N...
        if (AB.first != -1) {
            // print that sum as N = a + b
            cout << N << " = " << AB.first << " + " << AB.second << '\n';
        }
        else {
            cout << "Goldbach's conjecture is wrong.\n";
        }
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
// given a number N, find the pair of prime integers that add to N and have a maximal distance between them.
pair<long long, long long> findMaxGodlbachNumber(int N) {
    // keep track of i, our "first prime"
    long long i = 1;
    // bool to know when to stop looking for a pair of primes
    bool notFound = true;
    // a variable for when to stop the addition checking
    long long n = N / 2;
    // from i to n and while there is not yet a pair of primes...
    for (; i <= n && notFound; i++) {
        // check that i and N - i are prime
        if (isPrime(i) && isPrime(N - i)) {
            // if so, state that a pair of promes have been found
            notFound = false;
            // and return that pair
            return pair<long long, long long>(i,  N - i);
        }
    }
    // else, the Goldbach conjecture is wrong and there is no such pair of primes
    // that add to N
    return pair<long long, long long>(-1, -1);
}