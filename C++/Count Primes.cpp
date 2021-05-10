// https://leetcode.com/problems/count-primes/

/*Short Explanation -
Use "Sieve of Eratosthenes" :
1. Create a boolean array/vector of size n, initialized with true values. [Initially all numbers are potential primes]
2. Mark base cases, i.e prime[0] = prime[1] = false.
3. Now for each i in [2,sqrt(n)], if 'i' is prime, mark all its multiples as non-prime.
4. Count number of 'true' values in our boolean vector

Read more here - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 or n == 1)return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (!prime[i])continue;
            for (int j = i + i; j < n; j += i)prime[j] = false;
            // In above line you can also start with 'int j = i*i'
            // as lower multiple(s) of 'i' are already processed
        }
        return count(prime.begin() , prime.end() , true);
    }
};
