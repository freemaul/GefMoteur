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
		virtual void En_Dessine() const =0;
	public:
		Dessinable();
		void Cache(bool);
		void Dessine() const;
	};

	class Sprite
	{
	protected:
		Dessinable& dessinable;
	public:
		Sprite(Dessinable&);
		virtual void Donne_Image(void* image)=0;
	};

	class Animable
	{
	protected:
		int current;
		Sprite& sprite;
		virtual void En_Maj()=0;
	public:
		Animable(Sprite&);
		void Maj();
		const Sprite& Donne_Sprite();
	};

}; // GefRender
}; // GefMoteur

#endif

