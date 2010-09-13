#include <GefMoteur/GefAppSfml.hpp>
using namespace GefMoteur;
using namespace GefMoteur::GefApp;
using namespace GefMoteur::GefAppSfml;

AppSfml::AppSfml(Moteur& moteur) : App(scdir_sfml,ressdir_sfml,moteur) , scdir_sfml(horloge) , ressdir_sfml(render_target)
{

}

