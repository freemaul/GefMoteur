#include <GefMoteur/GefRender.hpp>
using namespace GefMoteur::GefRender;


Dessinable::Dessinable()
{
	cache = false;
}

void Dessinable::Cache(bool cache)
{
	this->cache = cache;
}

void Dessinable::Dessine() const
{
	if(!cache)
		En_Dessine();
}


Sprite::Sprite(Dessinable& d) : dessinable(d)
{
	posx=0;
	posy=0;
}

const Dessinable& Sprite::Donne_Dessinable() const
{
	return dessinable;
}

void Sprite::Change_Position(int px,int py)
{
	posx = px;
	posy = py;
	En_Change_Position(px,py);
}

void Sprite::Deplace(int mx,int my)
{
	posx += mx;
	posy += my;
}

Animable::Animable(Sprite& sp) : sprite(sp)
{
	current = 0;
	image = NULL;
}

void Animable::Maj_Image()
{
	int px1,px2,py1,py2;

	px1 = ( (current%nb_image_x) * ta_image_x ) / nb_image_x;
	px2 = px1 + ta_image_x / nb_image_x;

	py1 = ( (current / nb_image_x) * ta_image_y ) / nb_image_y;
	py2 = py1 + ta_image_y / nb_image_y;

	sprite.Definit_Rectangle(px1,py1,px2,py2);
}

void Animable::Maj(float temp)
{
	temp_total += temp;
	if(temp_total > duree)
	{
		temp_total -= duree;
		current++;
		if(current >= nb_image_x*nb_image_y)
			current = 0;
		Maj_Image();
	}

}

void Animable::Definit_Image(void *image,int nb_image_x,int nb_image_y,int duree)
{
	Definit_Image(image);
	this->nb_image_x	= nb_image_x;
	this->nb_image_y	= nb_image_y;
	this->duree		= duree;
}

const Sprite& Animable::Donne_Sprite() const
{
	return sprite;
}


Scene_directeur::Scene_directeur(GefSystem::Horloge& h) : horloge(h)
{

}

Scene_directeur& Scene_directeur::operator << (const Dessinable& d)
{
	dessinables.push_back(&d);
	return *this;
}

Scene_directeur& Scene_directeur::operator << (const Sprite& s)
{
	*this << s.Donne_Dessinable();
	return *this;
}

Scene_directeur& Scene_directeur::operator << (Animable& a)
{
	animables.push_back(&a);
	*this << a.Donne_Sprite();
	return *this;
}

void Scene_directeur::Maj()
{
	std::vector<Animable*>::size_type sz = animables.size();
	float temps = horloge.Temps();
	horloge.Zero();

	unsigned int i;
	for(i=0;i<sz;i++)
		animables[i]->Maj(temps);
}

void Scene_directeur::Dessine()
{
	std::vector<Dessinable*>::size_type sz = dessinables.size();
	unsigned int i;
	for(i=0;i<sz;i++)
		dessinables[i]->Dessine();
}

