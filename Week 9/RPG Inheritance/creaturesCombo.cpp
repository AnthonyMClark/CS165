#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

class Creature 
{
	private:
		int strength;
		int hitpoints;
	public:
		int getDamage ();
		Creature ();
		Creature (int newStrength, int newHit);
};
Creature::Creature() 
{
		strength = 10;
		hitpoints = 10;
}
Creature::Creature(int newStrength, int newHit) 
{
		strength = newStrength;
		hitpoints = newHit;
}
int Creature::getDamage() 
{
	int damage;
	damage = (rand() % strength) + 1;
	return damage;
}

class Human: public Creature 
{
	public:
		Human ();
		Human(int newStrength, int newHit);
};
Human::Human():Creature() 
{/*Left Blank*/}
Human::Human(int newStrength, int newHit):Creature (newStrength, newHit) 
{/*intentionall left blank*/}

class Elf: public Creature 
{
	public:
		Elf();
		Elf(int newStrength, int newHit);
		int getDamage ();
};
Elf::Elf():Creature() 
{/*Left Even Blanker! GASP!*/}
Elf::Elf(int newStrength, int newHit):Creature (newStrength, newHit) 
{/*You thought I forgot stuff here? Nope, still intentional*/}
int Elf::getDamage() 
{
	int magic, damage;
	damage = Creature::getDamage();
	magic = (rand() % 100);
	if (magic < 10)
	{
		cout << "Additional Elf Damage awarded! (" << damage << " x 2 multiplier)\n";
		damage *= 2;
	}
	return damage;
}
class Demon: public Creature 
{
	protected:
		int getDamage ();
	public:
		Demon();
		Demon(int newStrength, int newHit);
};
Demon::Demon():Creature() 
{/*Intentionally blank*/}
Demon::Demon(int newStrength, int newHit):Creature (newStrength, newHit) 
{/*Intentionally blank*/}
int Demon::getDamage() 
{
	int damage;
	damage = Creature::getDamage();
	return damage;
}

class CyberDemon : public Demon 
{
	public:
		CyberDemon();
		CyberDemon(int newStrength, int newHit);
		int getDamage ();
};
CyberDemon::CyberDemon():Demon() 
{/*Intentionally blank*/}
CyberDemon::CyberDemon(int newStrength, int newHit):Demon (newStrength, newHit) 
{/*intentionally blank*/}
int CyberDemon::getDamage() 
{
	int damage;
	damage = Demon::getDamage();
	int temp = (rand() % 100);
        if (temp < 5)
        {
                cout << "Additional Cyber Demon Denomic Damage awarded! (" << damage << " + 50)\n";
                damage += 50;
                cout << "damage is " << damage << endl;
        }

	return damage;
}

class Balrog: public Demon 
{
	public:
		Balrog();
		Balrog(int newStrength, int newHit);
		int getDamage ();
};
Balrog::Balrog():Demon() 
{/*Intentionally blank*/}
Balrog::Balrog(int newStrength, int newHit):Demon (newStrength, newHit) 
{/*Intentionally blank*/}
int Balrog::getDamage() 
{
	int damage1, damage2, damage;
	damage1 = Demon::getDamage();
//	cout << damage1 << endl;
	damage2 = Demon::getDamage();
//	cout << damage2 << endl;
	damage = damage1 + damage2;
        int temp = (rand() % 100);
        if (temp < 5)
        {
                cout << "Additional Balrog Denomic Damage awarded! (" << damage << " + 50)\n";
                damage += 50;
                cout << "damage is " << damage << endl;
        }
	return damage;
}
int main()
{
	srand(time(NULL));

	int humanDamage, elfDamage, demonDamage, balrogDamage, totalDamage;
	Human hObj;
	Elf eObj(5, 10);
	CyberDemon cObj(15, 20);
	Balrog bObj(25, 30);

	humanDamage = hObj.getDamage();
	elfDamage = eObj.getDamage();
	demonDamage = cObj.getDamage();
	balrogDamage = bObj.getDamage();
	totalDamage = humanDamage + elfDamage + demonDamage + balrogDamage;

	cout << "Human Damage = " << humanDamage << "." << endl;
	cout << "Elf Damage = " << elfDamage << "." << endl;
	cout << "Cyber Demon Damage = " << demonDamage << "." << endl;
	cout << "Balrog Damage = " << balrogDamage << "." << endl;
	cout << "Total Damage = " << totalDamage << "." << endl;
	return 0;
}

