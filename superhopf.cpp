#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

using namespace std;

int n=5000;
float dW;
double mu;

float simulateh(int n, double mu,float dt, double noiseSTD,int dWL)
{
	float x1[n];float x2[n];
	dW = dWL * 0.00001;
	dW = dW - 0.5;
	float x10 = 1;float x20 = -1;
	x1[1]=x10;x2[1]=x20;
	for (int i=2;i<=n;i++){
		x1[i] = x1[i-1]+dt*(mu*x1[i-1]-x2[i-1]-x1[i-1]*(x1[i-1]*x1[i-1]+x2[i-1]*x2[i-1])) + noiseSTD*dW*sqrt(dt);
		x2[i] = x2[i-1]+dt*(x1[i-1]+mu*x2[i-1]-x2[i-1]*(x1[i-1]*x1[i-1]+x2[i-1]*x2[i-1])) + noiseSTD*dW*sqrt(dt);
	}
	return x1[n];
}

int randgen ()
{
	int xRan;
	xRan=rand()%100000+1; // Randomizing the number between 1-15.

	
	return xRan;
}

int main(){
	ofstream out_data("outdata.dat");
	ofstream paramdata("params.dat");
	out_data << "Time" << "\t" << "X" << "\t" <<"dW\n";
	float dt = 0.1;
	double mu = 10;
	double nSTD = 0.1;
	srand (time(0));
	paramdata << "mu = " << mu << "\nNoise STD = " << nSTD << "\ndt = " << dt << "\nL = " << n;
	for (int i=1;i<=n;i++){	
		int dWL = randgen();
		float x = simulateh(i,mu,dt,nSTD,dWL);		
		out_data << dt*i << "\t" << x << "\t" << (dWL * 0.00001) - 0.5 << "\n";
	}
		

return 0;
}