#include <GefMoteur/GefAppSfml.hpp>
using namespace GefMoteur;
using namespace GefMoteur::GefApp;
using namespace GefMoteur::GefAppSfml;

AppSfml::AppSfml(Moteur& moteur) : App(scdir_sfml,ressdir_sfml,moteur) , scdir_sfml(horloge) , ressdir_sfml(render_target)
{

}

void AppSfml::Boucle()
{
	bool Running = true;
	while (Running)
	{
		sf::Event Event;
		while (render_target.GetEvent(Event))
		{
			// Fenêtre fermée
			if (Event.Type == sf::Event::Closed)
				Running = false;

			// Touche 'echap' appuyée
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
				Running = false;
		}

		moteur.Dessine();
		moteur.Maj();

		render_target.Display();
		render_target.Clear();
	}
}
