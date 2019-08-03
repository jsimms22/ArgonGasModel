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

void LJ_force(Particle bin[nparticles]) 
{
	double radius;
	for(int i = 0;i < nparticles;i++)
	{
		radius = 0.0;
    bin[i].fx = 0.0;
    bin[i].fy = 0.0;
    bin[i].fz = 0.0;
	  	for(int j = 0;j < nparticles;j++)
	  	{
			if(i != j)
			{
        radius = sqrt(pow(bin[j].x - bin[i].x,2) 
				+ pow(bin[j].y - bin[i].y,2) 
				+ pow(bin[j].z - bin[i].z,2));

        bin[i].fx += 4.0 * epsilon * (12.0*(pow(sigma,12)/pow(radius,13)) - 6.0*(pow(sigma,6)/pow(radius,7))) * (bin[i].x - bin[j].x) / radius;
        bin[i].fy += 4.0 * epsilon * (12.0*(pow(sigma,12)/pow(radius,13)) - 6.0*(pow(sigma,6)/pow(radius,7))) * (bin[i].y - bin[j].y) / radius;
        bin[i].fz += 4.0 * epsilon * (12.0*(pow(sigma,12)/pow(radius,13)) - 6.0*(pow(sigma,6)/pow(radius,7))) * (bin[i].z - bin[j].z) / radius;		
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

	for(int i = 0;i < 1;i++)
	{
		LJ_force(bin);
    cout << bin[0].fx << ", " << bin[0].fy << ", " << bin[0].fz << "\n";
    cout << bin[1].fx << ", " << bin[1].fy << ", " << bin[1].fz << "\n";
	}

	return 0;
}

