#ifndef CHARACTER_H
#define CHARACTER_H

#include "Mover.h"
#include "Hp.h"
#include "Weapon.h"
class Character :
	public Mover
{
	public:
		Character();
		Character(Weapon _weapon);
		Character(int _type); //FIX
		~Character();

		void update(Time& elapsed);

		inline void setFull(int health = 15) { hp.setTot(health); hp.setFull(); } //FIX
		inline void increaseHp(int _hp) { hp.add(_hp); hp.setTot((hp.getTot()) + _hp); }
		inline void damage(int dmg) { hp.add(-dmg); }
		inline void heal(int amount) { hp.add(amount); if (hp.get() > hp.getTot()) hp.setFull();}
		inline int getHp() { return hp.get(); }
		inline int getTotHp() { return hp.getTot(); }
		inline float getPerHp() { return hp.get() / hp.getTot();}
		inline bool isDead() { return hp.isEmpty(); }
		inline void setCoolDown(float amount) { coolDown.setTot(amount); };
		inline float getCoolDown() { return coolDown.getTot(); };
		inline bool useDmg() { if (coolDown.isFull()) { coolDown.setEmpty(); return true; } return false; }
		inline void setDmg(int newDmg) { dmg = newDmg; }
		inline int getDmg() { return dmg; }

		inline int getWeaponDmg() { return weapon.getDmg(); };
		inline int getCriticalDmg() { return weapon.getDmg()*3; };


		inline void setDir(int _dir) { direction = _dir; }
		inline int getDir() { return direction; }
		RectangleShape getHpRect() {return myHp.get();};
		RectangleShape getOriginHpRect() {return originHp.get();};
		inline int getType() {return type;};
		inline void chooseWeapon(Weapon _weapon) { weapon = _weapon; }
		int type; //FIX
		Weapon weapon;

	private:
		int dmg;
		int direction;
		Counter hp;
		Counter coolDown;
		Hp myHp;
		Hp originHp;
};

#endif