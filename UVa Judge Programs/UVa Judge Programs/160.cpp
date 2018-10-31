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
// constant size of sieve
const long long numbers = 1000001;
// used o mark prime numbers
bitset<numbers - 1> primes;
// used to tally how many times a prime can divide a number
vector<int> numDivisors(numbers, 0);

// mark all prime numbers
void SieveOfE();
// determine i a numbe is prime
bool isPrime(long long n);
// tally the number of times that a prime goes into N factorial
void findNumberOfPrimeDivisors(int N);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// hold the number that will factorialized
    int N;
	// mark all of the primes
	SieveOfE();
	// read all of the values from the input while N is not 0
    while (cin >> N && N != 0) {
		// find the number of prime divisors for each prime
        findNumberOfPrimeDivisors(N);
        // output the value of N in the form of "N! ="
        cout << setw(3) << right << N << "! =";
        // if N! is divisible by 2...
        if (numDivisors[2] != 0) {
            // print it out
            cout << setw(3) << right << numDivisors[2];
        }
        // used to know when to go to the next line
        int count = 1;
        // loop though all numbers from 3 to numbers - 1, also have a variable
        // that is how spaced the numbers need to be from one another, d
        for (int i = 3, d = 3; i < numbers; i++) {
            // if i divides N! (and is prime)...
            if (numDivisors[i] != 0) {
                // d is 9...
                if (d == 9) {
                    // make a new line
                    cout << '\n';
                }
                // print the number of times a particular prime divides N!
                cout << setw(d) << right << numDivisors[i];
                // reset the d to 3
                d = 3;
                // increment how many times a number has been printed out
                count++;
                // every 15th number...
                if (count % 15 == 0) {
                    // make a larger spacing between numbers (will really be an
                    // offset from the beginning of a new line)
                     d = 9;
                }
            }
        }
        cout << '\n';
        // fill the vector with all 0s
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
// using globally declared variables, take in a number, N and count the prime
// facotrs of N factorial (N!)
void findNumberOfPrimeDivisors(int N) {
    // a dummy variable for the term of N!
    int temp;
    // simulate N!
    for (int i = N; i > 1; i--) {
        // assign temp to ith term of N!
        temp = i;
        // loop through the possible divisors of i
        for (int j = 2; j <= i; j++) {
            // while temp is divisible by j, a prime number,...
            while (isPrime(j) && temp % j == 0) {
                // reduce temp by a factor of j
                temp /= j;
                // and increase the counter related to that prime
                numDivisors[j]++;
            }
        }
    }
}