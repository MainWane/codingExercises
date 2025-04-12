// Criminal Class Header File
#pragma once
#include <string>

// ANSI-escape codes for farver
#define RESET "\033[0m"       // Nulstil farver
#define RED "\033[31m"        // Rød tekst
#define GREEN "\033[32m"      // Grøn tekst
#define YELLOW "\033[33m"     // Gul tekst
#define BOLD "\033[1m"        // Fed tekst

class Criminal {    // Class definition for Criminal
private:    // Private member variables
    std::string name; // Name of the criminal
    int health; // Current health of the criminal
    int maxHealth = 100;    // Maximum health of the criminal
    int power;  // Power of the criminal
    int maxPower = 200; // Maximum power of the criminal
    bool bevæbnet; // Indicates if the criminal is armed

public:
    // Constructor
    Criminal(std::string name, int health, int power, bool bevæbnet)
        : name(name), health(health), power(power), bevæbnet(bevæbnet) {}

    // Getters
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getPower() const { return power; }
    int getMaxPower() const { return maxPower; }
    bool isArmed() const { return bevæbnet; }

    // Setters
    void setHealth(int newHealth) { health = newHealth; }   // Set health
    void setPower(int newPower) { power = newPower; } // Set power
    
    // Member functions
    void takeDamage(int damage) { // Function to take damage
        health -= damage;
        if (health < 0) health = 0; // Ensure health doesn't go below 0
    }
    void heal(int amount) { // Function to heal
        health += amount;
        if (health > maxHealth) health = maxHealth; // Ensure health doesn't exceed maxHealth
    }
    void arm() { bevæbnet = true; } // Function to arm the criminal
    void disarm() { bevæbnet = false; } // Function to disarm the criminal
    
    // Nyttefunktioner
    void printStats() const {
        std::cout << name <<  " har " << GREEN << health << " Health " << RESET << "og " << RED << power << " Power." << RESET << std::endl;
    }
    bool erDød() const { return health <= 0; } // Function to check if the criminal is dead
     
};
