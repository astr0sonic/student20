#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    std::vector<int>mass(n,0);
    mass[0]=1;
    mass[1]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(mass[i]==0) {

            for (int j = i * i; j <= n; j += i) {
                mass[j]=1;
            }
        }
    }
    for(int i=0;i<mass.size();i++)
    {
        if(mass[i]==0)
        {
            primes.push_back(i);
        }
    }
    return primes;
}
