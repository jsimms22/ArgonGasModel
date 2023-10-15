#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<random>
#include<iomanip>
#include<vector>

extern const double range;
//finite distance potential = 0 at rm
extern const long double sigma;	
//depth of potential well for Argon
extern const long double epsilon;
//const long double rm;

class Particle
{
public:
	Particle() { }
	static Particle init_particle();
	enum class ParticleType;
	//double get_position() { return x, y, z; }
	//void set_position(int, int, int);
//private: // Public until get/set are built
	std::string name = "Argon";
	double m = 39.9;	//grams per mol (Argon)
	double x,y,z;		//positions
	double vx,vy,vz;	//velocities
	double ax,ay,az;	//accelerations
	double fx,fy,fz;	//forces
	double mx,my,mz;	//momentums
};


enum class Particle::ParticleType
{
	/* TODO */
};

double tr1_rand(double from, double to);

void cout_particles(std::vector<Particle>& bin);

void write(std::vector<Particle>& bin);

#endif
