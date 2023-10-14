#ifndef PARTICLE_H
#define PARTICLE_H

extern const int nparticles;
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
//private:
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
	argon,
	arsenic,
	sulfur
};

double tr1_rand(double from, double to);

void fill_bin(std::vector<Particle> bin, int n);

void cout_particles(std::vector<Particle> bin, int n);

#endif
