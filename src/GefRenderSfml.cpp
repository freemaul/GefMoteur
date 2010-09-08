#include <GefMoteur/GefRenderSfml.hpp>
using namespace GefMoteur::GefRenderSfml;
using namespace GefMoteur::GefRender;


DessinableSfml::DessinableSfml(sf::Drawable& d,sf::RenderTarget& rtsfml) : drawable(d), rendertarget(rtsfml) , Dessinable()
{

}

void DessinableSfml::En_Dessine() const
{
	rendertarget.Draw(drawable);
}




SpriteSfml::SpriteSfml(sf::RenderTarget& rtsfml) : dessinablesfml(sprite,rtsfml) , Sprite(dessinablesfml)
{

}

void SpriteSfml::Definit_Image(void* image)
{
	sprite.SetImage(*(sf::Image*)image);
}


AnimableSfml::AnimableSfml(sf::RenderTarget& rtsfml) : spritesfml(rtsfml) , Animable(spritesfml)
{

}

void AnimableSfml::En_Maj()
{

}

