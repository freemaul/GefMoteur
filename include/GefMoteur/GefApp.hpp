#ifndef GEFMOTEUR_GEFAPP_HPP
#define GEFMOTEUR_GEFAPP_HPP

#include <GefMoteur/GefRender.hpp>

namespace GefMoteur
{
	namespace GefApp
	{
		class App
		{
		protected:
			GefRender::Scene_directeur &scdir;
		public:
			App(GefRender::Scene_directeur&);
		};
	};
};

#endif // GEFMOTEUR__GEFAPP_HPP

