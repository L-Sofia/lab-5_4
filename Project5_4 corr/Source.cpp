#include <iostream>
#include <cmath>

using namespace std;

double P0(const int N, const int f) // iter
{
	double p = 1;
	for (int i = N; i <= f; i++)
		p *= (i + (1. / (i * i))) / sqrt(1 + exp(1. / i));
	return p;
}

double P1(const int N, const int f, const int i) // rec up ++
{
	if (i > f)
		return 1;
	else
		return (i + (1. / (i * i))) / sqrt(1 + exp(1. / i)) * P1(N, f, i + 1);
}

double P2(const int N, const int f, const int i) // rec up --
{
	if (i < N)
		return 1;
	else
		return (i + (1. / (i * i))) / sqrt(1 + exp(1. / i)) * P2(N, f, i - 1);
}

double P3(const int N, const int f, const int i, double t) // rec down ++
{
	t = t * (i + (1. / (i * i))) / sqrt(1 + exp(1. / i));
	if (i >= f)
		return t;
	else
		return P3(N, f, i + 1, t);
}

double P4(const int N, const int f, const int i, double t)
{
	t = t * (i + (1. / (i * i))) / sqrt(1 + exp(1. / i));
	if (i <= N)
		return t;
	else
		return P4(N, f, i - 1, t);
}

int main()
{
	int N;
	int f = 10;
	cout << "N = "; cin >> N;

	cout << "(iter) P0 = " << P0(N, f) << endl;
	cout << "(rec up ++) P1 = " << P1(N, f, N) << endl;
	cout << "(rec up --) P2 = " << P2(N, f, f) << endl;
	cout << "(rec down ++) P3 = " << P3(N, f, N, 1) << endl;
	cout << "(rec down --) P4 = " << P4(N, f, f, 1) << endl;

	return 0;
}