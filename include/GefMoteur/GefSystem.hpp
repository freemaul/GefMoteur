#ifndef GEFMOTEUR_GEFSYSTEM_HPP
#define GEFMOTEUR_GEFSYSTEM_HPP

namespace GefMoteur
{
namespace GefSystem
{
	class Horloge
	{
	public:
		virtual void Zero()=0;		// remise a zero du compteur
		virtual float Temps()=0;	// donne le temps passé en seconde (nombre rationel)
	};

}; // GefSystem
}; // GefMoteur

#endif // GEFMOTEUR_GEFSYSTEM_HPP

