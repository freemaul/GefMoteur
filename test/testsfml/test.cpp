#include <GefMoteur/GefMoteurH.hpp>
#include <GefMoteur/GefAppSfml.hpp>
#include <cstdlib>
#include <iostream>

int main(int argc,char *argv[])
{
	std::cout << "Helloworld" << std::endl;
	std::cout << "Version " << GefMoteur::Version << std::endl;

	GefMoteur::MoteurH MonMoteur;
	GefMoteur::GefAppSfml::AppSfml MonApp(MonMoteur);

//	MonMoteur.Lance();
	MonApp.Configure();
	MonApp.Boucle();

	return 0;
}


