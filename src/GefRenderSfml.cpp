#include <GefMoteur/GefRenderSfml.hpp>
using namespace GefMoteur::GefRenderSfml;
using namespace GefMoteur::GefRender;


DessinableSfml::DessinableSfml(sf::RenderTarget& rtsfml) : rendertarget(rtsfml) , Dessinable()
{

}

void DessinableSfml::En_Dessine() const
{
	rendertarget.Draw(*d);
}




SpriteSfml::SpriteSfml(sf::RenderTarget& rtsfml) : DessinableSfml(rtsfml)
{
	d = new sf::Sprite();
}

void SpriteSfml::SetImage(sf::Image& image)
{
	((sf::Sprite*)d)->SetImage(image);
}


AnimableSfml::AnimableSfml(sf::RenderTarget& rtsfml) : spritesfml(rtsfml) , Animable(spritesfml)
{

}

void AnimableSfml::En_Maj()
{

}

