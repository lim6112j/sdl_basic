#include "Swarm.h"
#include <iostream>
namespace sdlBasic
{
   Swarm::Swarm() {
       m_particles = new Particle[NPARTICLES];
   };
   Swarm::~Swarm() {
       delete [] m_particles;
       std::cout << "swarm destoryed" << std::endl;
   }; 
} // namespace sdlBasic
