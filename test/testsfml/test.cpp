#include <GefMoteur/GefMoteur.hpp>
#include <GefMoteur/GefRenderSfml.hpp>
#include <GefMoteur/GefSystemSfml.hpp>
#include <cstdlib>
#include <iostream>

#include <SFML/Window.hpp>

int main(int argc,char *argv[])
{
	std::cout << "Helloworld" << std::endl;
	std::cout << "Version " << GefMoteur::Version << std::endl;

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Window");

	sf::Image image;
	GefMoteur::GefRenderSfml::SpriteSfml monsp(App);

	image.LoadFromFile("test.bmp");
	monsp.Definit_Image(&image);

	GefMoteur::GefSystemSfml::HorlogeSfml horloge;
	GefMoteur::GefRender::Scene_directeur scdir(horloge);

	GefMoteur::GefSystemSfml::Entree::SourieSfml sourie(App);

	scdir << monsp;

	bool Running = true;
	while (Running)
	{
		sf::Event Event;
		while (App.GetEvent(Event))
		{
			// Fenêtre fermée
			if (Event.Type == sf::Event::Closed)
				Running = false;

			// Touche 'echap' appuyée
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
				Running = false;
		}

//		scdir.Dessine();
		monsp.Donne_Dessinable().Dessine();
		monsp.Change_Position(sourie.Position_x(),sourie.Position_y());
		std::cout << sourie.Position_x() << std::endl;

		App.Display();
	}


	return 0;
}


