#include "force.h"

/*	        1	  q(1)*q(2)
 *	F =  -------- * ------------ * R
 *	      4 e pi	 radius^(2)
 */

void LJ_force(std::vector<Particle>& bin) 
{
	double radius;
	for (int i = 0;i < bin.size();i++) {
		radius = 0.0;
        bin[i].fx = 0.0;
        bin[i].fy = 0.0;
        bin[i].fz = 0.0;
	  	for (int j = 0;j < bin.size();j++) {
			if (i != j) {
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