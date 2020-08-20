#include "Particle.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>
namespace sdlBasic
{
   Particle::Particle() : m_x(0), m_y(0) {
       m_direction = (2.0 * M_PI * rand())/RAND_MAX;
       m_speed = (0.01 * rand())/RAND_MAX;
   };
   Particle::~Particle() {
    //    std::cout << "particle destroyed" << std::endl;
   }
   void Particle::update() {

       double m_xspeed = m_speed * cos(m_direction);
       double m_yspeed = m_speed * sin(m_direction);
       m_x += m_xspeed;
       m_y += m_yspeed;
    //    if(m_x < -1 || m_x > 1) {
    //        m_direction = -m_direction;
    //    }
    //    if(m_y < -1 || m_y > 1) {
    //        m_direction = -m_direction;
    //    }
   }
} // namespace sdlBasic
