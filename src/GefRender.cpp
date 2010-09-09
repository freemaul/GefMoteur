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
	En_Change_Position(0,0);
}

const Dessinable& Sprite::Donne_Dessinable() const
{
	return dessinable;
}

void Sprite::Change_Position(int px,int py)
{
	posx = px;
	posy = py;
}

void Sprite::Deplace(int mx,int my)
{
	posx += mx;
	posy += my;
}

Animable::Animable(Sprite& sp) : sprite(sp)
{
	current = 0;
}

void Animable::Maj_Image()
{
// changement d'image
}

void Animable::Maj(float temp)
{
//	En_Maj();
	temp_total += temp;
	if(temp_total > duree)
	{
		temp_total -= duree;
		current++;
		if(current > image_max)
			current = 0;
		Maj_Image();
	}

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

