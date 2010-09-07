#include <GefMoteur/GefRenderSfml.hpp>
using namespace GefMoteur::GefRenderSfml;
using namespace GefMoteur::GefRender;


DessinableSfml::DessinableSfml(RenderTargetSfml& rtsfml) : rendertarget(rtsfml) , Dessinable()
{

}

void DessinableSfml::En_Dessine()
{
	rendertarget.Draw(*d);
}




SpriteSfml::SpriteSfml(RenderTargetSfml& rtsfml) : DessinableSfml(rtsfml)
{
	d = new sf::Sprite();
}


