#ifndef GEFMOTEUR_GEFRENDERSFML_HPP
#define GEFMOTEUR_GEFRENDERSFML_HPP

//#if @HAVE_SFML_GRAPHICS_HPP@

#include <GefMoteur/GefRender.hpp>
#include <SFML/Graphics.hpp>

namespace GefMoteur
{
namespace GefRenderSfml
{
	class DessinableSfml : public GefRender::Dessinable
	{
	protected:
		sf::Drawable& drawable;
		sf::RenderTarget& rendertarget;
		virtual void En_Dessine() const;
	public:
		DessinableSfml(sf::Drawable&,sf::RenderTarget&);

	};

	class SpriteSfml : public GefRender::Sprite
	{
	protected:
		sf::Sprite sprite;
		DessinableSfml dessinablesfml;
		virtual void En_Change_Position(int,int);
	public:
        virtual ~SpriteSfml();
		SpriteSfml(sf::RenderTarget&);
		virtual void Definit_Rectangle(int px1,int py1,int px2,int py2);
		virtual void Definit_Image(void* image);
	};

	class AnimableSfml : public GefMoteur::GefRender::Animable
	{
	protected:
		SpriteSfml spritesfml;
	public:
		AnimableSfml(sf::RenderTarget&);
		virtual ~AnimableSfml();
		virtual void Definit_Image(void* image);
		virtual void Definit_Image(const std::string& fichier_image);
	};

	class Ressources_directeurSfml : public GefRender::Ressources_directeur
	{
	protected:
		sf::RenderTarget& rt;
	public:
		Ressources_directeurSfml(sf::RenderTarget&);

		virtual void* Charge_image(const char*);
		virtual GefRender::Sprite& Donne_sprite();
		virtual GefRender::Animable& Donne_animable();

		virtual void Suppr_image(void*);
		virtual void Suppr_sprite(GefRender::Sprite&);
		virtual void Suppr_animable(GefRender::Animable&);
	};

}; // GefRender
}; // GefMoteur

//#endif // HAVE_SFML_GRAPHICS_HPP
#endif

