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
		SpriteSfml(sf::RenderTarget&);
		virtual void Definit_Rectangle(int px1,int py1,int px2,int py2);
		virtual void Definit_Image(void* image);
	};

	class AnimableSfml : public GefRender::Animable
	{
	protected:
		SpriteSfml spritesfml;
	public:
		AnimableSfml(sf::RenderTarget&);
		~AnimableSfml();
		virtual void Definit_Image(void* image);
		virtual void Definit_Image(const std::string& fichier_image);
	};

}; // GefRender
}; // GefMoteur

#endif

