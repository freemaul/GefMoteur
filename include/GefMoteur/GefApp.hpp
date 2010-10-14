#ifndef GEFMOTEUR_GEFAPP_HPP
#define GEFMOTEUR_GEFAPP_HPP

#include <GefMoteur/GefRender.hpp>
#include <GefMoteur/GefMoteur.hpp>
#include <string>

namespace GefMoteur
{
	namespace GefApp
	{
		/************************************************************
		* Classe App
		* 
		* Gère l'application, permet de faire une interface entre le moteur
		*du jeu et le moteur graphique
		************************************************************/
		class App
		{
		protected:
			GefRender::Scene_directeur &scdir;
			GefRender::Ressources_directeur &ressdir;
			GefMoteur::Moteur &moteur;
		public:
			// Constructeur
			App(GefRender::Scene_directeur&,GefRender::Ressources_directeur&,GefMoteur::Moteur&);
			// Configuration de l'application
			virtual void Configure(int,int,int,std::string)=0;
			// Lancement de l'application
			virtual void Boucle()=0;
		};
	};
};

#endif // GEFMOTEUR__GEFAPP_HPP

