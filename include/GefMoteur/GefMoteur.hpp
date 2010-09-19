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
		GefRender::Scene_directeur* scdir;
		GefRender::Ressources_directeur* ressdir;
	public:
		Moteur();
		void Configure(GefRender::Scene_directeur&,GefRender::Ressources_directeur&);
		virtual void Maj();
		virtual void Dessine();
		virtual void Lance();
	};
};
#endif

