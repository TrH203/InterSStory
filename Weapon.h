#ifndef WEAPON_H
#define WEAPON_H

#include "Mover.h"
class Weapon:
	public Mover
{
	public:
		Weapon();
		Weapon(int _type); //FIX
		~Weapon();

		void update(Time& elapsed);

		//inline void setFull(int health = 15) { hp.setTot(health); hp.setFull(); } //FIX
		//inline void increaseHp(int _hp) { hp.add(_hp); hp.setTot((hp.getTot()) + _hp); }
		//inline void heal(int amount) { hp.add(amount); }
		//inline int getHp() { return hp.get(); }
		//inline int getTotHp() { return hp.getTot(); }
		inline void setCoolDown(float amount) { coolDown.setTot(amount); };
		inline float getCoolDown() { return coolDown.getTot(); };
		inline bool useDmg() { if (coolDown.isFull()) { coolDown.setEmpty(); return true; } return false; }
		inline void setDmg(int newDmg) { dmg = newDmg; }
		inline int getDmg() { return dmg; }

		int type; //FIX

	private:
		int dmg ;
		//Counter hp;
		Counter coolDown;
		int _type;
};

#endif