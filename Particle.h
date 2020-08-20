#if !defined(PARTICLE_H_)
#define PARTICLE_H_
namespace sdlBasic
{
    struct Particle {
    double m_x;
    double m_y;
    public:
        Particle();
        virtual ~Particle();
    };
} // namespace sdlBasic



#endif // PARTICLE_H_
