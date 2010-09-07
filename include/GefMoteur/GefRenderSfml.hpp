#ifndef GEFMOTEUR_GEFRENDERSFML_HPP
#define GEFMOTEUR_GEFRENDERSFML_HPP

#include <GefMoteur/GefRender.hpp>
#include <SFML/Graphics.hpp>

namespace GefMoteur
{
namespace GefRenderSfml
{
	class DessinableSfml 	: public GefMoteur::GefRender::Dessinable
	{
	public:
		virtual void Dessine(GefRender::RenderTarget&);
	};

	class RenderTargetSfml 	: public GefMoteur::GefRender::RenderTarget
	{
	public:
		virtual void Dessine(GefRender::Dessinable&);
	};

}; // GefRender
}; // GefMoteur

#endif

