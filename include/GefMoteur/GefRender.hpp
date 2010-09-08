#ifndef GEFMOTEUR_GEFRENDER_HPP
#define GEFMOTEUR_GEFRENDER_HPP

namespace GefMoteur
{
namespace GefRender
{
	class Dessinable;
	class RenderTarget;

	class Dessinable
	{
	protected:
		bool cache;
		virtual void En_Dessine()=0;
	public:
		Dessinable();
		void Cache(bool);
		void Dessine();
	};

	class Animable
	{
	protected:
		int current;
		Dessinable& dessinable;
		virtual void En_Maj()=0;
	public:
		Animable(Dessinable&);
		void Maj();
		const Dessinable& Donne_Dessinable();
	};

}; // GefRender
}; // GefMoteur

#endif

