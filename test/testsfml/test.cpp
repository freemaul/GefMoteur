#include <GefMoteur/GefMoteurH.hpp>
#include <GefMoteur/GefAppSfml.hpp>
#include <GefMoteur/GefDebug.hpp>
#include <cstdlib>
#include <iostream>

int main(int argc,char *argv[])
{

#ifdef DEBUG
	std::cout << "Helloworld" << std::endl;
	std::cout << "Version " << GefMoteur::Version << std::endl;
#endif //DEBUG

	GefMoteur::MoteurH* MonMoteur = new GefMoteur::MoteurH();
	GefMoteur::GefAppSfml::AppSfml* MonApp = new GefMoteur::GefAppSfml::AppSfml(*MonMoteur);

//	MonMoteur.Lance();
	MonApp->Configure();
	MonApp->Boucle();

    delete MonApp;
    delete MonMoteur;

#ifdef DEBUG
    std::cout << "Nb alloc : " << nb_new << std::endl;
#endif //DEBUG

	return 0;
}


