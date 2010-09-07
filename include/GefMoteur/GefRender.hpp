#ifndef GEFMOTEUR_GEFRENDER_HPP
#define GEFMOTEUR_GEFRENDER_HPP

namespace GefMoteur
{
namespace GefRender
{
	class Dessinable;
	class RenderTarget;


	class RenderTarget
	{
	public:
		virtual void Dessine(Dessinable&)=0;
	};

	class Dessinable
	{
	protected:
		bool cache;
	public:
		Dessinable();
		virtual void Dessine(RenderTarget&)=0;
		void Cache(bool);
	};

}; // GefRender
}; // GefMoteur

#endif

