#ifndef GEFMOTEUR_GEFAPPSFML_HPP
#define GEFMOTEUR_GEFAPPSFML_HPP

//#if @HAVE_SFML_GRAPHICS_HPP@

#include <GefMoteur/GefApp.hpp>
#include <GefMoteur/GefRenderSfml.hpp>
#include <GefMoteur/GefSystemSfml.hpp>

namespace GefMoteur
{
	namespace GefAppSfml
	{
		class AppSfml : public GefApp::App
		{
		protected:
			sf::RenderWindow render_target;
			GefSystemSfml::HorlogeSfml horloge;
			GefRender::Scene_directeur scdir_sfml;
			GefRenderSfml::Ressources_directeurSfml ressdir_sfml;
		public:
			AppSfml(GefMoteur::Moteur&);
			virtual ~AppSfml();
			virtual void Configure(int tx=800,int ty=600,int depth=32,std::string titre="AppSfml");
			virtual void Boucle();
		};
	};
};

//#endif // HAVE_SFML_GRAPHICS_HPP
#endif // GEFMOTEUR__GEFAPPSFML_HPP

