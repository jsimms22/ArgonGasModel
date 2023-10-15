#include<iostream>
#include<cstdlib>
#include "particle.h"
#include "force.h"

constexpr int nparticles = 2;

void fill_bin(std::vector<Particle>& bin, int n)
{
	for (int i = 0;i < n;i++) { bin.push_back(Particle::init_particle()); }
}

int main() 
{
	srand(time(NULL));

	std::vector<Particle> bin;
	fill_bin(bin, nparticles);
	cout_particles(bin);

	for(int i = 0;i < 1;i++)
	{
		LJ_force(bin);
    	std::cout << bin[0].fx << ", " << bin[0].fy << ", " << bin[0].fz << "\n";
    	std::cout << bin[1].fx << ", " << bin[1].fy << ", " << bin[1].fz << "\n";
	}

	return 0;
}

