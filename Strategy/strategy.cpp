#include "stdafx.h"

using namespace std;

class WeaponBehavior {
public:
    WeaponBehavior(string name, string texture)
        :name(name),texture(texture)
    {
    }
    virtual void useWeapon()
    {
        std::cout << "using " << texture << " " << name << endl;
    }
protected:
    string name;
    string texture;
};

class KnifeBehavior : public WeaponBehavior
{
public:
    KnifeBehavior():WeaponBehavior("sword", "iron")
    {
    }
    virtual void useWeapon()
    {
        cout << "Equip Swiss Army Knife" << endl;
    }
};

class KatyushaRocketBehavior : public WeaponBehavior
{
public:
    KatyushaRocketBehavior():WeaponBehavior("wand", "wood")
    {
    }
    virtual void useWeapon()
    {
        cout << "Katyusha Rocket start... Boom" << endl;
    }
};
class AxeBehavior : public WeaponBehavior
{
public:
    AxeBehavior():WeaponBehavior("axe", "iron")
    {
    }

    virtual void useWeapon()
    {
        cout << "Equip AXE" << endl;
    }
};
//weapon depot
class Character {
public:
    Character(string name, string gender, WeaponBehavior *weaponBehavior)
        :name(name),gender(gender),weaponBehavior(weaponBehavior)
    {
    }
    string GetName()
    {
        return name;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetGender()
    {
        return gender;
    }
    void SetGender(string gender)
    {
        this->gender = gender;
    }
    void fight()
    {
        weaponBehavior->useWeapon();
    }
    void setWeapon(WeaponBehavior *wb)
    {
        this->weaponBehavior = wb;
    }
    void show()
    {
        cout << name << ":" << gender << endl;
    }
protected:
    string name;
    string gender;
    WeaponBehavior *weaponBehavior;
};

class King : public Character
{
public:
    King(WeaponBehavior *weaponBehavior):Character("King Arthur", "male", weaponBehavior)
    {
    }
};
class Queen : public Character
{
public:
    Queen(WeaponBehavior *weaponBehavior):Character("Queen Akasha", "female", weaponBehavior)
    {
    }
};

int SimUGame() 
{
    King king(new KnifeBehavior());
    Queen queen(new KatyushaRocketBehavior());
    king.show();
    king.fight();
    queen.show();
    queen.fight();
    king.setWeapon(new AxeBehavior());
    king.fight();

    return 0;
}