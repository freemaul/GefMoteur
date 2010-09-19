#include <GefMoteur/GefApp.hpp>
using namespace GefMoteur;
using namespace GefMoteur::GefApp;
using namespace GefMoteur::GefRender;

App::App(Scene_directeur& scdir,GefRender::Ressources_directeur& ressdir,Moteur& moteur) : scdir(scdir) , ressdir(ressdir) , moteur(moteur)
{
	moteur.Configure(scdir,ressdir);
	moteur.Lance();
}

