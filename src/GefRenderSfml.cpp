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

void SpriteSfml::En_Change_Position(int posx,int posy)
{
	sprite.SetPosition(posx,posy);
}

void SpriteSfml::Definit_Rectangle(int px1,int py1,int px2,int py2)
{
	sprite.SetSubRect(sf::IntRect(px1,py1,px2,py2));
}

void SpriteSfml::Definit_Image(void* image)
{
	sprite.SetImage(*(sf::Image*)image);
}


AnimableSfml::AnimableSfml(sf::RenderTarget& rtsfml) : spritesfml(rtsfml) , Animable(spritesfml)
{

}

AnimableSfml::~AnimableSfml()
{
	if(this->image != NULL)
	{
		delete (sf::Image*)(this->image);
		this->image = NULL;
	}
}

void AnimableSfml::Definit_Image(void* image)
{
	if(this->image != NULL)
	{
		delete (sf::Image*)(this->image);
		this->image = NULL;
	}

	spritesfml.Definit_Image(image);
	ta_image_x = ((sf::Image*)image)->GetWidth();
	ta_image_y = ((sf::Image*)image)->GetHeight();
}

void AnimableSfml::Definit_Image(const std::string& fichier_image)
{
	if(image != NULL)
		((sf::Image*)image)->LoadFromFile(fichier_image);
	else
	{
		image = new sf::Image();
		((sf::Image*)image)->LoadFromFile(fichier_image);
	}
	
}

