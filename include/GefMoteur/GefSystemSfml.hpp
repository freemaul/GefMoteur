#ifndef GEFMOTEUR_GEFSYSTEMSFML_HPP
#define GEFMOTEUR_GEFSYSTEMSFML_HPP

//#if @HAVE_SFML_GRAPHICS_HPP@ 
//#if @HAVE_SFML_SYSTEM_HPP@

#include <GefMoteur/GefSystem.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

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

	namespace Entree
	{
		class SourieSfml : public GefSystem::Entree::Sourie
		{
		protected:
			const sf::Input& inputsfml;
		public:
			SourieSfml(const sf::RenderWindow&);
			virtual int Position_x();
			virtual int Position_y();
		};
	};

}; // GefSystemSfml
}; // GefMoteur

//#endif // HAVE_SFML_SYSTEM_HPP
//#endif // HAVE_SFML_GRAPHICS_HPP
#endif // GEFMOTEUR_GEFSYSTEM_HPP

