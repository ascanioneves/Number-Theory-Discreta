#include <bits/stdc++.h>
using namespace std;

int euclides(int a, int b)
{
  return (b == 0) ? a : euclides(b, a % b);
}

int main()
{
  int a, b;
  cin >> a >> b;
  int mdc = euclides(a, b);
  for(int s = 0; s >= -max(a, b); s--)
  {
    for(int t = 0; t <= max(a, b); t++)
    {
      if((s * a) + (t * b) == mdc)
      {
        cout << s << " " << t << endl;
        return 0;
      }
    }
  }
  return 0;
}