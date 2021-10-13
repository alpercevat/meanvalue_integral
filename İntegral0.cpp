#include <iostream> 
#include <fstream> 
#include <stdlib.h>
#include <math.h>

using namespace std;

double func(double x);

int main() {

	double a = 0.;   //! Değişebilir
	double b = 1.; //! Değişebilir 
	int n = 1000;  

    double sum, x, fx;
	sum = 0.;
	srand48(time(NULL));

    ofstream out("data.dat");
	for (int i = 1; i <= n; i++) {
        //x = 2*(drand48()-.5);
        x = drand48();  //? Yukarda verilen aralık 0 ile 1 arasında olduğu için burayı modifiye etmeye gerek yok ancak 0 ile 5 arasında olsaydı bu satırı 5 ile çarpardık *5
		//printf("Random number #%d: %f: %f\n", i, drand48(), x);
		out << x << endl;
		fx = func(x);
		sum += fx;
	}
	sum = ((b-a)*sum) / ((double)n);
	cout << " Integral = " << sum << " Exact = " << M_PI << endl;
	//out << sum << endl;
}


double func(double x)
{
	double value;
	value = 4 / (1.+x*x); //! Değişebilir
	//value = 1/x;
	//value = sin(x);
	return value;
}

//! Sınırlar ve fonksiyon değişebilir. drand48 i bu nedenle modifiye etmek gerekir.