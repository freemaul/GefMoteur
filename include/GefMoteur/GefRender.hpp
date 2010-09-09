#ifndef GEFMOTEUR_GEFRENDER_HPP
#define GEFMOTEUR_GEFRENDER_HPP

#include <vector>
#include <GefMoteur/GefSystem.hpp>

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
		int posx,posy;
		virtual void En_Change_Position(int,int)=0;
	public:
		Sprite(Dessinable&);

		const Dessinable& Donne_Dessinable() const;
		void Change_Position(int,int);
		void Deplace(int,int);

		virtual void Definit_Rectangle(int px1,int py1,int px2,int py2)=0;
		virtual void Definit_Image(void* image)=0;
	};

	class Animable
	{
	protected:
		float temp_total;
		int current;
		Sprite& sprite;
		void Maj_Image();
	public:
		float duree;
		int image_max;

		Animable(Sprite&);
		void Maj(float);
		const Sprite& Donne_Sprite() const;
	};

	class Scene_directeur
	{
	protected:
		std::vector<const Dessinable*> dessinables;
		std::vector<Animable*> animables;
		GefSystem::Horloge& horloge;
	public:
		Scene_directeur(GefSystem::Horloge&);

		Scene_directeur& operator << (const Dessinable&);
		Scene_directeur& operator << (const Sprite&);
		Scene_directeur& operator << (Animable&);

		Scene_directeur& operator >> (const Dessinable&);
		Scene_directeur& operator >> (const Sprite&);
		Scene_directeur& operator >> (Animable&);

		void Maj();
		void Dessine();
	};


}; // GefRender
}; // GefMoteur

#endif

