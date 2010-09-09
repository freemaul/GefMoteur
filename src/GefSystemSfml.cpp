#include <GefMoteur/GefSystemSfml.hpp>
using namespace GefMoteur;
using namespace GefMoteur::GefSystem;
using namespace GefMoteur::GefSystemSfml;
using namespace GefMoteur::GefSystemSfml::Entree;

void HorlogeSfml::Zero()
{
	clock.Reset();
}

float HorlogeSfml::Temps()
{
	return clock.GetElapsedTime();
}



SourieSfml::SourieSfml(const sf::RenderWindow& render) : inputsfml(render.GetInput())
{

}

int SourieSfml::Position_x()
{
	return inputsfml.GetMouseX();
}

int SourieSfml::Position_y()
{
	return inputsfml.GetMouseY();
}

