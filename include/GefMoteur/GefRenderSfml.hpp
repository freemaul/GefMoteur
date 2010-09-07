#ifndef GEFMOTEUR_GEFRENDERSFML_HPP
#define GEFMOTEUR_GEFRENDERSFML_HPP

#include <GefMoteur/GefRender.hpp>
#include <SFML/Graphics.hpp>

namespace GefMoteur
{
namespace GefRenderSfml
{
	class DessinableSfml : public GefRender::Dessinable
	{
	protected:
		sf::Drawable* d;
		sf::RenderTarget& rendertarget;
		virtual void En_Dessine();
	public:
		DessinableSfml(sf::RenderTarget&);
		
	};

	class SpriteSfml : public DessinableSfml
	{
	public:
		SpriteSfml(sf::RenderTarget&);
		void SetImage(sf::Image&);
	};


}; // GefRender
}; // GefMoteur

#endif

