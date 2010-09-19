/*
license à ajouter


*/

#ifndef GEFMOTEURH_HPP
#define GEFMOTEURH_HPP

#include <GefMoteur/GefMoteur.hpp>

namespace GefMoteur
{
	class MoteurH;

	namespace MoteurHClasses
	{
		class Menu
		{
		private:
			bool affiche;
			void* image_fond;
			GefRender::Sprite* sprite_fond;
		public:
			Menu(MoteurH&);
			~Menu();
		};

	};

	class MoteurH : public GefMoteur::Moteur
	{
	protected:
		int etat;
		GefRender::Couche couche_menu;
		MoteurHClasses::Menu *mon_menu;
		friend class MoteurHClasses::Menu;
	public:
		MoteurH();
		virtual ~MoteurH();
		virtual void Lance();
	};
};
#endif

