#ifndef GEFMOTEUR_GEFRENDERSFML_HPP
#define GEFMOTEUR_GEFRENDERSFML_HPP

#include <GefMoteur/GefRender.hpp>
#include <SFML/Graphics.hpp>

namespace GefMoteur
{
namespace GefRenderSfml
{
	class RenderTargetSfml : public sf::RenderTarget
	{
	};

	class DessinableSfml : public GefRender::Dessinable
	{
	protected:
		sf::Drawable* d;
		RenderTargetSfml& rendertarget;
		virtual void En_Dessine();
	public:
		DessinableSfml(RenderTargetSfml&);
		
	};

	class SpriteSfml : public DessinableSfml
	{
	public:
		SpriteSfml(RenderTargetSfml&);
	};


}; // GefRender
}; // GefMoteur

#endif

