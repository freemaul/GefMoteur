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
	GefMoteur::GefRenderSfml::AnimableSfml animation1(App);

	image.LoadFromFile("mario.png");
	monsp.Definit_Image(&image);
	animation1.Definit_Image(&image);
	animation1.nb_image_x = 6;
	animation1.nb_image_y = 4;
	animation1.ta_image_x = image.GetWidth();
	animation1.ta_image_y = image.GetHeight();
	animation1.duree = 1;


	GefMoteur::GefSystemSfml::HorlogeSfml horloge;
	GefMoteur::GefRender::Scene_directeur scdir(horloge);

	GefMoteur::GefSystemSfml::Entree::SourieSfml sourie(App);

//	scdir << monsp;
	scdir << animation1;

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

		scdir.Dessine();
		monsp.Change_Position(sourie.Position_x(),sourie.Position_y());

		App.Display();
		App.Clear();
	}


	return 0;
}


