#include <GefMoteur/GefMoteurH.hpp>
using namespace GefMoteur;
using namespace GefMoteur::MoteurHClasses;
#include <iostream>

MoteurH::MoteurH()
{
	etat = 0;
}

void MoteurH::Lance()
{
	mon_menu = new Menu(*this);
	*scdir << couche_menu;
}

Menu::Menu(MoteurH& moteur)
{
	image_fond = moteur.ressdir->Charge_image("fond.jpg");
	if(image_fond == NULL)
		return;
	sprite_fond = &(moteur.ressdir->Donne_sprite());
	sprite_fond->Definit_Image(image_fond);
	moteur.couche_menu << sprite_fond->Donne_Dessinable();
}

Menu::~Menu()
{

}

