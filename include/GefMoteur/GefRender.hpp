#ifndef GEFMOTEUR_GEFRENDER_HPP
#define GEFMOTEUR_GEFRENDER_HPP

#include <vector>

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
		const Dessinable& Donne_Dessinable();
		virtual void Definit_Image(void* image)=0;
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

	class Scene_directeur
	{
	protected:
		std::vector<const Dessinable*> dessinables;
		std::vector<Animable*> animables;
	public:
		Scene_directeur& operator << (const Dessinable&);
		Scene_directeur& operator << (const Sprite&);
		Scene_directeur& operator << (Animable&);

		Scene_directeur& operator >> (const Dessinable&);
		Scene_directeur& operator >> (const Sprite&);
		Scene_directeur& operator >> (Animable&);
		void Maj();
	};


}; // GefRender
}; // GefMoteur

#endif

