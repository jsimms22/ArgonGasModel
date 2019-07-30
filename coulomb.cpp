#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <random>
#include "particle.h"

using namespace std;

/*	        1	  q(1)*q(2)
 *	F =  -------- * ------------ * R
 *	      4 e pi	 radius^(2)
 */

void lennard-jones_force(Particle bin[nparticles]) 
{
	double radius;
	for(int i = 0;i < nparticles;i++)
	{
		radius = 0.0;
	  	for(int j = 0;j < nparticles;j++)
	  	{
			if(i != j)
			{
                		radius = sqrt(pow(bin[j].x - bin[i].x,2) 
					+ pow(bin[j].y - bin[i].y,2) 
					+ pow(bin[j].z - bin[i].z,2));
				
					
			}
		}
	}
}

void write(Particle bin[nparticles])
{

}

int main() 
{
	srand(time(NULL));

	Particle bin[nparticles];
	fill_bin(bin);
	cout_particles(bin);

	for(int i = 0;i < 2;i++)
	{
		
	}

	return 0;
}

