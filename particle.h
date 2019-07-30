// particle.h
#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <random>
#include <iomanip>

using namespace std;

const int nparticles = 2;
const double range = 4e-10;
//finite distance potential = 0 at rm
const long double sigma = 3.4e-10;	
//depth of potential well for Argon
const long double epsilon = 1.65e-21;
const long double rm = 1.122*sigma;

struct Particle
{
	string name = "Argon";
	double m = 39.9;	//grams per mol (Argon)
	double x,y,z;		//positions
	double fx,fy,fz;	//forces
	double mx,my,mz;	//momentums
} particle;
double tr1_rand(double from, double to)
{
	mt19937 gen(time(NULL) * rand() / RAND_MAX);
	uniform_real_distribution<double> unif(from,to);
	double a_random_double = unif(gen);
	return a_random_double;
}

Particle init_particles()
{
	//particle.m = 1.0;
	particle.x = tr1_rand(-1*range,range);
	particle.y = tr1_rand(-1*range,range);
	particle.z = tr1_rand(-1*range,range);
	particle.v = 0.0;
	particle.a = 0.0;

	return particle;
}

void fill_bin(Particle bin[nparticles])
{
	for(int i = 0;i < nparticles;i++)
	{
		bin[i] = init_particles();
	}
}

void cout_particles(Particle bin[nparticles])
{
	for(int i = 0;i < nparticles;i++)
	{
		cout << "p" << i << setw(1);
		if(i < 10) { cout << " "; }
		cout << "|" << bin[i].name << setw(2);
		if(bin[i].name == "proton") { cout << "  "; } 	
		cout << "|" << bin[i].x << setw(2);
	       	if(bin[i].x >= 1.0) { cout << " "; }	
		cout << "|" << bin[i].y << setw(2);
	       	if(bin[i].y >= 1.0) { cout << " "; }	
		cout << "|" << bin[i].z << setw(2);
	       	if(bin[i].z >= 1.0) { cout << " "; }
		cout << "\n";	
	}
}
#endif
