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

}; // GefRender
}; // GefMoteur

#endif

