#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int n ;
    cin >> n ;
    if((n % 2 == 0 && n != 2) || n == 1)
    {
        printf("Nao eh primo\n");
        return 0;
    }
    for (int i = 3 ; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
        {
            printf("Nao eh primo\n");
            return 0;
        }
    }
    printf("Eh primo\n");
    return 0 ;
}