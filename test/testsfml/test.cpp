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

	sf::Image image,image2;
	GefMoteur::GefRenderSfml::SpriteSfml monsp(App);
	GefMoteur::GefRenderSfml::AnimableSfml animation1(App);

	image2.LoadFromFile("test.bmp");
	image.LoadFromFile("mario.png");
	monsp.Definit_Image(&image2);
	animation1.Definit_Image_plus(&image,6,4,1.0);


	GefMoteur::GefSystemSfml::HorlogeSfml horloge;
	GefMoteur::GefRender::Scene_directeur scdir(horloge);
	GefMoteur::GefRender::Couche couche1;

	GefMoteur::GefSystemSfml::Entree::SourieSfml sourie(App);

	scdir << (couche1 << monsp << animation1);

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
		scdir.Maj();

		App.Display();
		App.Clear();
	}


	return 0;
}


