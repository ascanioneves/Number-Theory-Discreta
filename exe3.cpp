#include <bits/stdc++.h>
using namespace std;
 
bool checa_primos(int n)
{
    for (int i = 3 ; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main ()
{
    int n, aux = 2; 
    cin >> n ;

    while (n > 1)
    {
        if(n % aux == 0 && checa_primos(aux))
        {
            if(n / aux == 1)
                cout << aux;
            else
                cout << aux << "x";
            n /= aux;
        }
        else 
        {
            aux++;
        }
    }

    cout << "\n" ;
    return 0 ;
}