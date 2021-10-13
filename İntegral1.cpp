#include <iostream> 
#include <stdlib.h>
#include <math.h>

using namespace std;

double func(double x);

int main() {

	double a = 0.;
	double b = M_PI;
	int n = 1000;

	double sum, x, fx;
	sum = 0.;
	srand48(time(NULL));

	for (int i = 1; i <= n; i++) {
		x = drand48()*M_PI;
		printf("Random number #%d: %f: %f\n", i, drand48(), x);
		fx = func(x);
		sum += fx;
	}
	sum = ((b-a)*sum) / ((double)n);
	cout << " Integral = " << sum << " Exact= 2" << endl;
}

double func(double x)
{
	double value;
	//value = 4 / (1.+x*x);
	//value = 1/x;
	value = sin(x);
	return value;
}
