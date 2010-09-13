#ifndef GEFMOTEUR_GEFRENDER_HPP
#define GEFMOTEUR_GEFRENDER_HPP

#include <vector>
#include <GefMoteur/GefSystem.hpp>
#include <string>

namespace GefMoteur
{
namespace GefRender
{
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
		float 	temp_total;
		int 	current;
		Sprite& sprite;
		void* 	image;
		float 	duree;
		int 	nb_image_x,nb_image_y;
		int 	ta_image_x,ta_image_y;

		void Maj_Image();
	public:
		Animable(Sprite&);

		virtual void Definit_Image(void *image)=0;
		virtual void Definit_Image(const std::string& fichier_image)=0;
		void Definit_Image_plus(void *image,int nb_image_x,int nb_image_y,float duree);
		void Charge_Animation(const std::string& fichier_animation);

		void Maj(float);
		const Sprite& Donne_Sprite() const;
	};

	class Couche
	{
	protected:
		std::vector<const Dessinable*> dessinables;
		std::vector<Animable*> animables;
	public:
		Couche();

		Couche& operator << (const Dessinable&);
		Couche& operator << (const Sprite&);
		Couche& operator << (Animable&);

		Couche& operator >> (const Dessinable&);
		Couche& operator >> (const Sprite&);
		Couche& operator >> (Animable&);

		void Maj(float);
		void Dessine();
	};

	class Scene_directeur
	{
	protected:
		std::vector<Couche*> couches;
		GefSystem::Horloge& horloge;
	public:
		Scene_directeur(GefSystem::Horloge&);

		Scene_directeur& operator << (Couche&);

		Scene_directeur& operator >> (Couche&);

		void Maj();
		void Dessine();
	};

	class Ressources_directeur
	{
	public:
		virtual void* Charge_image(const char*)=0;
		virtual Sprite& Donne_sprite()=0;
		virtual Animable& Donne_animable()=0;

		virtual void Suppr_image(void*)=0;
		virtual void Suppr_sprite(Sprite&)=0;
		virtual void Suppr_animable(Animable&)=0;
	};

}; // GefRender
}; // GefMoteur

#endif

