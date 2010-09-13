#include <GefMoteur/GefMoteur.hpp>
using namespace GefMoteur;
using namespace GefMoteur::GefRender;

const char GefMoteur::Version[]="0.B";

Moteur::Moteur(Scene_directeur& scdir,Ressources_directeur& ressdir) : scdir(scdir) , ressdir(ressdir)
{

}

void Moteur::Maj()
{
	scdir.Maj();
}

void Moteur::Dessine()
{
	scdir.Dessine();
}

