#include <bits/stdc++.h>
using namespace std;

int modulo_positive(int a, int n)
{
	a %= n;
	return a < 0 ? a + n : a;
}

void modulo_make_positive(int &a, int n)
{
	a %= n;
	if (a < 0) a += n;
}

int gcd(int a, int b)
{
	int r;
	while ((r = a%b) != 0)
	{
		a = b; b = r;
	}

	return b;
}

int _gcd_loop_(int a, int b, int& x, int& y)
{
	int a1 = a, b1 = b;

	if (b1 > a1) swap(a1, b1);

	constexpr int max_count = 100;

	int r, count = 0, q[max_count];

	while ((r = a1 % b1) != 0)
	{
		q[count++] = -(a1 / b1);

		if (count >= max_count)
			return 0;

		a1 = b1; b1 = r;
	}


	if (count == 0)
	{
		x = 0; y = 1;
	}
	else
	{
		x = 1; y = q[count - 1];

		for (int i = count - 2; i >= 0; --i)
		{
			int t = x; x = y;
			y = t + y * q[i];
		}
	}

	if ((a*x + b*y) != b1)
		swap(x, y);

	return b1;
}

int _gcd_recur_(int a, int b, int& x, int& y)
{
	int r = a % b;

	if (r == 0)
	{
		x = 0; y = 1; return b;
	}
	else
	{
		int g = _gcd_recur_(b, r, x, y);

		int q = -(a / b);

		if (x == 0)
		{
			x = 1; y = q;
		}
		else
		{
			int t = x; x = y;
			y = t + y * q;
		}

		return g;
	}
}

int gcd_recursion(int a, int b, int& x, int& y)
{
	int a1 = a, b1 = b;

	if (b1 > a1) swap(a1, b1);

	int g = _gcd_recur_(a1, b1, x, y);

	if ((a * x + b * y) != g)
		swap(x, y);

	return g;
}

int gcd_loop(int a, int b, int& x, int& y)
{
	int g = _gcd_loop_(a, b, x, y);

	if (g == 0)
	{
		return gcd_recursion(a, b, x, y);
	}
	else
		return g;
}

vector<int> LinearCongruence(int a, int k, int b)
{
	vector<int> sol;

	int g = gcd(a, b);

	if (g == 1)
	{
		int x, y;

		gcd_recursion(a, b, x, y);

		modulo_make_positive(x, b);

		sol.emplace_back(x * k % b);
	}
	else
	{
		if ((k%g) == 0)
		{
			int a1 = a / g, b1 = b / g, k1 = k / g;
			int x, y;
			
			gcd_recursion(a1, b1, x, y);
			modulo_make_positive(x, b1);

			y = x * k1 % b1;
			
			sol.emplace_back(y);

			for (int i = 1; i < g; ++i)
			{
				y += b1;
				sol.emplace_back(y);
			}
		}
	}

	return sol;

}

ostream& operator<<(ostream& os, const vector<int>& v)
{
	if (v.empty()) return os;

	auto last_element = --v.cend();

	os << "{";

	for (auto itr = v.cbegin(); itr != last_element; ++itr)
		os << *itr << ", ";

	os << *last_element << "}";

	return os;
}


int main()
{
	int a, b, m;
	cin >> a >> b >> m;
	vector<int> solution = LinearCongruence(a, b, m);
	if(solution.empty())
	{
		cout << "Nao existe solucao!\n";
	}
	else
	{
		cout << "Solucoes : " << solution << endl;
	}
	return 0;
}