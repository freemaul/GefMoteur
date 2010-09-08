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


Animable::Animable(Dessinable& d) : dessinable(d)
{
	current = 0;
}

void Animable::Maj()
{
	En_Maj();
}

const Dessinable& Animable::Donne_Dessinable()
{
	return dessinable;
}

