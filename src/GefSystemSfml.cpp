#include <GefMoteur/GefSystemSfml.hpp>
using namespace GefMoteur;
using namespace GefMoteur::GefSystem;
using namespace GefMoteur::GefSystemSfml;

void HorlogeSfml::Zero()
{
	clock.Reset();
}

float HorlogeSfml::Temps()
{
	return clock.GetElapsedTime();
}
