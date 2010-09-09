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

}

const Dessinable& Sprite::Donne_Dessinable() const
{
	return dessinable;
}


Animable::Animable(Sprite& sp) : sprite(sp)
{
	current = 0;
}

void Animable::Maj()
{
	En_Maj();
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

}

void Scene_directeur::Dessine()
{
	std::vector<Dessinable*>::size_type sz = dessinables.size();
	unsigned int i;
	for(i=0;i<sz;i++)
		dessinables[i]->Dessine();
}

