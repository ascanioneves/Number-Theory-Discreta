#include <bits/stdc++.h>
using namespace std;

int mdc(int x, int y)
{
  return (y == 0) ? x : mdc(y , x  %  y) ;
}
int main ()
{
  int x , y ;
  cin >> x >> y ;
  cout << mdc (x , y) << endl;
}