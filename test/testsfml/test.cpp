#include <GefMoteur/GefMoteur.hpp>
#include <GefMoteur/GefAppSfml.hpp>
#include <cstdlib>
#include <iostream>

int main(int argc,char *argv[])
{
	std::cout << "Helloworld" << std::endl;
	std::cout << "Version " << GefMoteur::Version << std::endl;

	GefMoteur::Moteur MonMoteur;
	GefMoteur::GefAppSfml::AppSfml MonApp(MonMoteur);

	MonApp.Configure();
	MonApp.Boucle();

	return 0;
}


