/*
license à ajouter


*/

#ifndef GEFMOTEUR_HPP
#define GEFMOTEUR_HPP

#include <GefMoteur/GefRender.hpp>

namespace GefMoteur
{
	extern const char Version[];

	class Moteur
	{
	protected:
		GefRender::Scene_directeur& scdir;
	public:
		Moteur(GefRender::Scene_directeur&);
		virtual void Maj();
		virtual void Dessine();
	};
};
#endif

