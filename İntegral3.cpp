#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double func(double x);

int main() {

	double a = 0.;
	//double b = M_PI;
	double b = 2.0;
	int n = 10000;
	int m = 10000;

	double sum, x, fx;
	sum = 0.;
	srand48(time(NULL));

    ofstream out("sum1k.dat");

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			//x = drand48()*M_PI;
			//cout << drand48() << endl;
			x = drand48()*2.0;
			fx = func(x);
			sum += fx;
		}
		sum = ((b-a)*sum) / ((double)n);
		out << sum << endl;
	}
}

double func(double x)
{
	double value;
	//value = 4 / (1.+x*x);
	//value = 1/x;
	//value = sin(x);
	//double val = 1./(x*(2-x));
	//value = pow(sin(val),2.);
	value = sin(1./(x*(2-x)))*sin(1./(x*(2-x)));
	return value;
}


//! Frequency histogramını çizdirmek için şu kod gnuplota yazılır.------->   n=50; min=1.9; max=2.1; width=(max-min)/n; hist(x,width)=width*floor(x/width)+width/2.0;  plot "sum1k.dat" using(hist($1,width)):(1.0) smooth frequency with boxes lc rgb"blue" notitle