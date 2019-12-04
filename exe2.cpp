#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
 
bool checa_primos(int n)
{
    for (int i = 3, end = sqrt(n); i <= end; i+=2)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int i = 3 ;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    while(duration.count() < 60)
    {
        
        if(checa_primos(i))
        {
            cout << i << endl ;
        }

        i+=2;
        stop = high_resolution_clock::now();
        duration = duration_cast<seconds>(stop - start);
    }
}
int main ()
{
    printf("2\n");
    solve();
    return 0 ;
}