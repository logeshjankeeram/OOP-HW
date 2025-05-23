#include <iostream>
using namespace std;

class Character
{
protected:
    int health;

    void takeDamage(int damage)
    {
        health -= damage;
        if (health < 0)
            health = 0;
    }

public:
    Character(int health) : health(health) {}

    void receiveDamage(int damage)
    {
        takeDamage(damage);
    }

    void showHealth() const
    {
        cout << "Health: " << health << endl;
    }

    // Public getter for health
    int getHealth() const
    {
        return health;
    }

    // Public setter for health
    void setHealth(int newHealth)
    {
        health = newHealth;
        if (health < 0)
            health = 0;
    }

    friend void displayCharacterInfo(const Character &);
}; // pass the Character as a ref instead like this (Character, int) because in this case we are passing it as a value

class GameMaster
{
public:
    friend void boostCharacter(Character &, int);
    friend void weakenCharacter(Character &, int);
};

void boostCharacter(Character &character, int amount)
{
    character.setHealth(character.getHealth() + amount);
    cout << "Character health boosted by " << amount << ". New health: " << character.getHealth() << endl;
}

void weakenCharacter(Character &character, int amount)
{
    character.setHealth(character.getHealth() - amount);
    cout << "Character health weakened by " << amount << ". New health: " << character.getHealth() << endl;
}

void displayCharacterInfo(const Character &character)
{
    cout << "Character Info:" << endl;
    cout << "Health: " << character.getHealth() << endl;
}

class Warrior : virtual public Character
{
protected:
    int attackPower;

public:
    Warrior(int health, int attackPower) : Character(health), attackPower(attackPower) {}

    void attack(Character &target)
    {
        cout << "Warrior attacks!" << endl;
        target.receiveDamage(attackPower);
    }

    void showStats() const
    {
        cout << "Warrior Stats:" << endl;
        showHealth();
        cout << "Attack Power: " << attackPower << endl;
    }
};

class Magician : virtual public Character
{
protected:
    int mana;

public:
    Magician(int health, int mana) : Character(health), mana(mana) {}

    void castSpell(Character &target)
    {
        if (mana >= 10)
        {
            cout << "Magician casts a spell!" << endl;
            target.receiveDamage(20);
            mana -= 10;
        }
        else
        {
            cout << "Not enough mana to cast a spell!" << endl;
        }
    }

    void showStats() const
    {
        cout << "Magician Stats:" << endl;
        showHealth();
        cout << "Mana: " << mana << endl;
    }
};

class Magicknight : public Warrior, public Magician
{
public:
    Magicknight(int health, int attackPower, int mana)
        : Character(health), Warrior(health, attackPower), Magician(health, mana) {}

    void specialMove(Character &target)
    {
        cout << "Magicknight uses a special move!" << endl;
        Warrior::attack(target);
        Magician::castSpell(target);
    }

    void showStats() const
    {
        cout << "Magicknight Stats:" << endl;
        showHealth();
        cout << "Attack Power: " << attackPower << endl;
        cout << "Mana: " << mana << endl;
    }
};

int main()
{
    Warrior warrior(100, 15);
    Magician magician(80, 50);
    Magicknight magicknight(120, 20, 30);
    GameMaster gm;

    cout << "Initial Stats:" << endl;
    warrior.showStats();
    magician.showStats();
    magicknight.showStats();

    cout << "\nGameMaster Actions:" << endl;
    boostCharacter(warrior, 20);       // Boost warrior's health
    weakenCharacter(magician, 10);     // Weaken magician's health
    displayCharacterInfo(magicknight); // Display magicknight's info

    cout << "\nStats After GameMaster Actions:" << endl;
    warrior.showStats();
    magician.showStats();
    magicknight.showStats();

    return 0;
}