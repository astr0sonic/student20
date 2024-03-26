#include <cmath>
#include "sundaram.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    int k;
    std::vector<int>mass(2*n+2,0);
    mass[0]=1;
    for(int i=1;i<=(sqrt(2*n+1)-1)/2;i++)
    {
        for(int j=i;j<=(n-i)/(2*i+1);j++)
        {
            k=i+j+2*i*j;
            if(k<=n)
            {
                mass[k]=1;
            }
        }
    }
    if(n>0) {
        primes.push_back(2);
    }
    for(int i=0;i<n;i++)
    {
        if(mass[i]==0&&i*2+1<=n)
        {
            primes.push_back(i*2+1);
        }
    }
    return primes;
}
