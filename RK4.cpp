#include <iostream>
#include <fstream>
#include <math.h>
#include <complex>
#include <string>

// mam: dy/dt = f(y, t), y(t=0) = y_0
// y(t) \in R V t
// szukam: y = y(t)


double f(double y, double t){
	return t*sin(2 * y) + cos(t) + t/y - 2;
}

double RK4_step(double y, double t, double h){
	double k1, k2, k3, k4;
	k1 = h * f(y, t);
	k2 = h * f(y + k1/2, t + h/2);
	k3 = h * f(y + k2/2, t + h/2);
	k4 = h * f(y + k3, t + h);
	return y + (k1 + 2*k2 + 2*k3 + k4)/6;
}

int main(int argc, char** argv) {
	
	FILE *fp;
	fp = fopen(argv[1],"w");
	
	double y = -0.1;
	double t = 0.0;
	double h = 0.01;
	while(t < 20){
		fprintf(fp, "%f %f\n", t, y);
		y = RK4_step(y, t, h);
		t += h;
	}
	fclose(fp);

}

