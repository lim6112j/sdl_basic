#if !defined(SWARM_H_)
#define SWARM_H_
#include "Particle.h"
namespace sdlBasic
{

   class Swarm {
    public:
        const static int NPARTICLES = 5000;
    private:
        sdlBasic::Particle *  m_particles;
    public:
        Swarm();
        virtual ~Swarm();
        const sdlBasic::Particle * const getParticle() {return m_particles;};
   };
} // namespace sdlBasic


#endif // SWARM_H_
