#include <GefMoteur/GefMoteur.hpp>
using namespace GefMoteur;
using namespace GefMoteur::GefRender;

const char GefMoteur::Version[]="0.B";

Moteur::Moteur() : scdir(NULL) , ressdir(NULL)
{

}

void Moteur::Configure(Scene_directeur& scdir,Ressources_directeur& ressdir)
{
	this->scdir = &scdir;
	this->ressdir = &ressdir;
}

void Moteur::Maj()
{
	scdir->Maj();
}

void Moteur::Dessine()
{
	scdir->Dessine();
}

