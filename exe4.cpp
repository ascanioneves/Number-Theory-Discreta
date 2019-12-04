#include <bits/stdc++.h>
using namespace std;

#define k __gcd(a,b);

bool checa_primos(int n)
{
  if(n == 2) return true;
  if(n < 2 || n % 2 == 0) return false;
  for(int i = 3 ; i <= sqrt(n); i += 2)
  {
    if(n % i == 0)
    {
      return false;
    }
  }
  return true;
}
void fatores(int n, map<int, int> &mp)
{
  int aux = 2;
  while (n > 1)
  {
    if(n % aux == 0 && checa_primos(aux))
    {
      mp[aux]++;
      n /= aux;
    }
    else 
    {
      aux++;
    }
  }
}
int main()
{
  int aux = 2, a, b; 
  cin >> a;
  cin >> b;
  
  map<int, int> mp_a;
  map<int, int> mp_b;

  fatores(a, mp_a);
  fatores(b, mp_b);

  long long int mdc = 1;
  long long int mmc = 1;

  for(map<int,int>::iterator it = mp_a.begin(), it2 = mp_b.begin(); it != mp_a.end() && it2 != mp_b.end(); ++it, ++it2)
  {
    if(mp_b.find(it->first) != mp_b.end())
    {
      mdc *= pow(it->first, min(it->second, (mp_b.find(it->first)) -> second));
    }
    else if(mp_a.find(it2->first) != mp_a.end())
    {
      mdc *= pow(it->first, min(it->second, (mp_b.find(it->first)) -> second));  
    }
    mdc = k;
  }
  for(int i = 2; i <= max(a, b); i++)
  {
    if(checa_primos(i))
    {
      if(mp_a.find(i) != mp_a.end() && mp_b.find(i) != mp_b.end())
      {
        mmc *= pow(i, max(mp_a[i], mp_b[i]));
      }
      else if(mp_a.find(i) != mp_a.end())
      {
        mmc *= pow(i, mp_a[i]);
      }
      else if(mp_b.find(i) != mp_b.end())
      {
        mmc *= pow(i, mp_b[i]);
      }
    }
  }
  cout << mdc << " " << mmc << endl;
  return 0 ;
}