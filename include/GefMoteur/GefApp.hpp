#ifndef GEFMOTEUR_GEFAPP_HPP
#define GEFMOTEUR_GEFAPP_HPP

#include <GefMoteur/GefRender.hpp>
#include <GefMoteur/GefMoteur.hpp>

namespace GefMoteur
{
	namespace GefApp
	{
		class App
		{
		protected:
			GefRender::Scene_directeur &scdir;
			GefRender::Ressources_directeur &ressdir;
			GefMoteur::Moteur &moteur;
		public:
			App(GefRender::Scene_directeur&,GefRender::Ressources_directeur&,GefMoteur::Moteur&);
		};
	};
};

#endif // GEFMOTEUR__GEFAPP_HPP

