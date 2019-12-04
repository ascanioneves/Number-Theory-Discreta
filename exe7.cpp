#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  //para aplicar o inverso a entrada deve conter dois co-primos por definição (mdc == 1)
  for(int s = max(a, b); s >= -max(a, b); s--)
  {
    for(int t = 0; t <= max(a, b); t++)
    {
      if((s * a) + (t * b) == 1)
      {
        cout << s << endl;
        return 0;
      }
    }
  }
  return 0;
}