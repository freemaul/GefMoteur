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
