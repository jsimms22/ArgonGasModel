#include"particle.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<random>
#include<iomanip>

const int nparticles = 2;
const double range = 4e-10;
//finite distance potential = 0 at rm
const long double sigma = 3.4e-10;	
//depth of potential well for Argon
const long double epsilon = 1.653e-21;
//const long double rm = 1.1225*sigma;

double tr1_rand(double from, double to)
{
	std::mt19937 gen(time(NULL) * rand() / RAND_MAX);
	std::uniform_real_distribution<double> unif(from,to);
	double a_random_double = unif(gen);
	return a_random_double;
}

Particle Particle::init_particle()
{
	Particle particle = Particle();
	//particle.m = 1.0;
	particle.x = tr1_rand(-1*range,range);
	particle.y = tr1_rand(-1*range,range);
	particle.z = tr1_rand(-1*range,range);
	particle.vx = 0;
	particle.vy = 0;
	particle.vz = 0;
	particle.ax = 0;
	particle.ay = 0;
	particle.az = 0;

	return particle;
}

void fill_bin(std::vector<Particle> bin, int n)
{
	for(int i = 0;i < n;i++)
	{
		bin.push_back(Particle::init_particle());
	}
}

void cout_particles(std::vector<Particle> bin, int n)
{
	for(Particle p : bin)
	{
		//std::cout << "p" << i << std::setw(1);
		/*if(i < bin.size()) {*/ std::cout << " "; //}
		std::cout << "|" << p.name << std::setw(2);
		if(p.name == "proton") { std::cout << "  "; } 	
		std::cout << "|" << p.x << std::setw(2);
	       	if(p.x >= 1.0) { std::cout << " "; }	
		std::cout << "|" << p.y << std::setw(2);
	       	if(p.y >= 1.0) { std::cout << " "; }	
		std::cout << "|" << p.z << std::setw(2);
	       	if(p.z >= 1.0) { std::cout << " "; }
		std::cout << "\n";	
	}
}