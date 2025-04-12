// GTextA ver. 0.55

#include <iostream> // For at bruge std::cout
#include <string> // For at bruge std::string
#include <chrono> // For tidsforsinkelse
#include <thread> // For std::this_thread::sleep_for
#include <algorithm>    // For std::transform
#include <cctype> // For at konvertere til lowercase
#include "include/Criminal.h" // Include the Criminal class header file

// ANSI-escape codes for farver
#define RESET "\033[0m"       // Nulstil farver
#define RED "\033[31m"        // Rød tekst
#define GREEN "\033[32m"      // Grøn tekst
#define YELLOW "\033[33m"     // Gul tekst
#define BOLD "\033[1m"        // Fed tekst

using namespace std; 

// Skrivemaskine effekt funktion
void skrivLangsomt(string tekst, int hastighed = 50) {
    for (char c : tekst) {
        std::cout << c << std::flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    std::cout << std::endl;
}

// Dramatisk skrivemaskine effekt funktion
void skrivLangsommere(string tekst, int hastighed = 100) {
    for (char c : tekst) {
        std::cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    std::cout << endl;
}

// Ugyldigt valg funktion
void ugyldigtValg() {
    std::cout << "Ugyldigt valg. Prøv igen. C'mon, ægte gangstere kan godt stave" << endl;
}

void WASTED() {
    std::cout << endl;
    skrivLangsommere(std::string(BOLD) + RED + "WASTED" + RESET);
    std::cout << endl;
    skrivLangsommere(std::string(BOLD) + YELLOW + "Game Over" + RESET);
}

// Main funktion
// Her starter programmet
int main() {
// Variabler
string valg1;
string valg2;
string valg3;
string navn;


// Titel
std::cout << endl;
std::cout << endl;
skrivLangsommere(std::string(BOLD) + YELLOW + "G" + RESET);
skrivLangsommere(std::string(BOLD) + YELLOW + "Text" + RESET);
skrivLangsommere(std::string(BOLD) + YELLOW + "A" + RESET);
std::cout << endl;
std::cout << endl;


// Introduktion
skrivLangsomt("Velkommen til Florida. Staten hvor ingen");
skrivLangsommere("(og vi mener INGEN)");
skrivLangsomt("indskydelse er for vanvittig til at handle på.");
std::cout << endl; 

skrivLangsomt("Hvem er du? (indtast navn)");
while (true) {
    getline(cin, navn); // Indtastning af navn
    if (navn.empty()) {
        std::cout << "Navnet kan ikke være tomt. Prøv igen: "; // Ved tom indtastning
    } else if (navn.length() > 50) {
        std::cout << "Navnet er for langt. Indtast et kortere navn (maks 50 tegn): "; // Ved for langt navn   
    } else {
        break;
    }
}
Criminal protag(navn, 100, 10, false);

// Første sekvens
skrivLangsomt(protag.getName() + " træder ud af sit rottebefængte hotel og kaster blikket ned på sin rustne Mañana. Dybt suk.");
skrivLangsomt("Til alt held triller en funklende rød Infernus op til trafiklyset lige foran."); 
skrivLangsomt("En nar med klistret svenskergarn sidder bag ruden, foran rettet.");
skrivLangsomt(protag.getName() + " tænker det er tid til at opgradere bil..."); 
skrivLangsomt("Hvad skal der gøres?");
std::cout << endl;
protag.printStats();  // Vis stats
std::cout << endl;

// Valg1 muligheder
std::cout << "Flå døren op - tast 'flå'" << endl;
std::cout << "Kast en granat ind - tast 'granat'" << endl;
std::cout << "Træk shotgun - tast 'shotgun'" << endl;

// while loop for valg1
// Brugeren skal vælge en af de tre muligheder
// Hvis brugeren vælger en ugyldig mulighed, skal de blive bedt om at prøve igen
while (true)
{   
    std::cin >> valg1;

    // Gør alt lowercase
transform(valg1.begin(), valg1.end(), valg1.begin(), ::tolower);

// Valg1 flå
if(valg1 == "flå") {
    skrivLangsomt(protag.getName() + " tager fat i døren. Svenskergarnet går med det samme i panik og jokker sømmet i bund."); 
    skrivLangsomt("Den fine røde bil bliver nu endnu rødere, mens den pløjer et par turister ned.");  
    skrivLangsomt(protag.getName() + " bliver trukket næsten hundrede meter før " + protag.getName() + " bliver sendt flyvende op på fortovet.");
    skrivLangsommere("Av for helvede."); 
    protag.takeDamage(50); // Spilleren tager skade
    protag.printStats();
    skrivLangsomt(protag.getName() + " kigger op og ser at Svenskergarnet er steget ud af bilen. Svenskergarnet har en pistol i hånden og peger den mod " + protag.getName() + ".");
    skrivLangsommere("Hvad gør du nu");
    break;

// Valg1 granat
} else if(valg1 == "granat") {
    skrivLangsomt(protag.getName() + " kaster en granat mod bilen."); 
    skrivLangsommere("Granaten rammer ruden på bilen med et godt dunk. Granaten eksploderer. Både bilen og " + protag.getName() + " bliver sprunget i luften.");
    WASTED(); // Kald funktionen for WASTED
    return 0; // Game over betingelse

// Valg1 shotgun
} else if(valg1 == "shotgun") {
    skrivLangsomt(protag.getName() + " trækker en shotgun fra indersiden af sin hawaiiskjorte."); 
    protag.setPower(80); // Spilleren får power
    protag.arm(); // Spilleren bliver bevæbnet
    std::cout << endl;
    protag.printStats();
    std::cout << endl;
    skrivLangsomt(protag.getName() + " mærker dens tyngde i hænderne og smiler ondskabsfuldt. Svenskergarnet går med det samme i panik og jokker sømmet i bund."); 
    skrivLangsomt("Den tomme plads som Infernus'en efterlader afslører nu, at der holder en politilbil lige bag ved. Klassisk..."); 
    skrivLangsomt("Betjentene springer ud af bilen og trækker deres pistoler.");
    std::cout << endl;
    skrivLangsommere("Hvad gør du nu?");
    
    break;

// Valg1 ugyldigt
} else {
    ugyldigtValg(); // Kald funktionen for ugyldigt valg
}
}

// Valg2 muligheder
// Bygger videre på valg1 tager udgangspunkt i hvad der er valgt i valg1
std::cout << "Skyd løs! Fuck the police! - tast 'skyd'" << endl;
std::cout << "Flygt! Løb til den nærliggende gyde - tast 'flygt'" << endl;

while (true)
{   
    std::cin >> valg2;

    // Gør alt lowercase
transform(valg2.begin(), valg2.end(), valg2.begin(), ::tolower);

if(valg2 == "skyd") {
    if(protag.isArmed()){
        skrivLangsomt(protag.getName() + " begynder at skyde vildt omkring sig efter alt der kunne ligne en uniform. Betjente søger desperat dækning bag politibilen - stykker af metal og glas flyver om ørene på dem." );
        break;
    } else {skrivLangsomt(protag.getName() + " hæver armen og bevæger instinktivt sin trigger finger. Du har dog intet våben i hånden. Svenskergarnet spilder ingen tid på at pløkke dig ned.");
        WASTED(); // Kald funktionen for WASTED
        return 0; // Game over betingelse
    }
} else if (valg2 == "flygt") {
    if(protag.isArmed()){ // Spilleren er bevæbnet
        skrivLangsomt(protag.getName() + " løber langsomt, det svært med en tung shotgun i hænderne. Betjentene skyder efter " + protag.getName() + " og rammer " + protag.getName() + " i skulderen");
        protag.takeDamage(60); // Spilleren tager skade
        protag.printStats();
        skrivLangsomt("Det går op for dig at du stadig har en granat i lommen.");
        skrivLangsommere("Hvad gør du nu?");
        std::cout << "Kast granaten - tast 'granat'" << endl;
        std::cout << "Løb videre - tast 'løb'" << endl; 
        std::cin >> valg3;
        break;
    } else if(!protag.isArmed()) { // Spilleren er ikke bevæbnet
        skrivLangsomt(protag.getName() + " løber som én i fanden ind i gyden. Det er en blindgyde. Misandten om der ikke ligger noget og skinner, lige ved siden af affaldskontaineren. Det er en Rocket Launcher!");
        skrivLangsomt(protag.getName() + " ryster på hovedet og mumler 'kun i Vice City.'");
        break;
    } 
    
    } else {
        ugyldigtValg(); // Kald funktionen for ugyldigt valg
        skrivLangsommere("Hvad gør du nu?");
        std::cout << "Fuck the police! Skyd løs - tast 'skyd'" << endl;
        std::cout << "Flygt! Løb til den nærliggende gyde - tast 'flygt'" << endl;
    }
    

}
}
