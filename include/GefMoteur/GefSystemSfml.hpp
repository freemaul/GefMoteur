#ifndef GEFMOTEUR_GEFSYSTEMSFML_HPP
#define GEFMOTEUR_GEFSYSTEMSFML_HPP

#include <GefMoteur/GefSystem.hpp>
#include <SFML/System.hpp>

namespace GefMoteur
{
namespace GefSystemSfml
{
	class HorlogeSfml : public GefSystem::Horloge
	{
	protected:
		sf::Clock clock;
	public:
		virtual void Zero();	// remise a zero du compteur
		virtual float Temps();	// donne le temps passé en seconde (nombre rationel)
	};

}; // GefSystemSfml
}; // GefMoteur

#endif // GEFMOTEUR_GEFSYSTEM_HPP

