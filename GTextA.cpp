#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cctype>

using namespace std;

// Globale variabler
int health = 100;
int maxHealth = 100;
int power = 10;
int maxPower = 200;
string criminalName;    
string valg1;
string valg2;
bool bevæbnet = false;

// Vis stats funktion
void printStats() {
    cout << criminalName << " har " << health << " Health og " << power << " power." << endl;
}

// Skrivemaskine effekt funktion
void skrivLangsomt(string tekst, int hastighed = 50) {
    for (char c : tekst) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    cout << endl;
}

// Dramatisk skrivemaskine effekt funktion
void skrivLangsommere(string tekst, int hastighed = 120) {
    for (char c : tekst) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    cout << endl;
}

int main() {
// Titel
skrivLangsommere("G");
skrivLangsommere("Text");
skrivLangsommere("A");
// Introduktion
skrivLangsomt("Velkommen til Florida. Staten hvor ingen, og vi mener INGEN, indskydelse er for vanvittig til at handle på. Hvem er du? (indtast navn) ");
while (true) {
    getline(cin, criminalName); // Indtastning af navn
    if (criminalName.empty()) {
        cout << "Navnet kan ikke være tomt. Prøv igen: "; // Ved tom indtastning
    } else if (criminalName.length() > 50) {
        cout << "Navnet er for langt. Indtast et kortere navn (maks 50 tegn): "; // Ved for langt navn   
    } else {
        break;
    }
}
// Første sekvens
skrivLangsomt(criminalName + " træder ud af sit rottebefængte hotel og kaster blikket ned på sin rustne Mañana. Dybt suk.");
skrivLangsomt("Til alt held triller en funklende Infernus op til trafiklyset lige foran. En nar med klistret svenskergarn sidder bag ruden, foran rettet.");
skrivLangsomt(criminalName + " tænker det er tid til at opgradere. Hvad skal der gøres?");
printStats();  // Vis stats


// Valg1 muligheder
cout << "Flå døren op - tast 'flå'" << endl;
cout << "Kast en granat ind - tast 'granat'" << endl;
cout << "Træk shotgun - tast 'shotgun'" << endl;

// while loop for valg1
// Brugeren skal vælge en af de tre muligheder
// Hvis brugeren vælger en ugyldig mulighed, skal de blive bedt om at prøve igen
while (true)
{   
    cin >> valg1;
    if (valg1.length() > 20) {
        cout << "Valget er for langt. Indtast et kortere valg (maks 20 tegn): ";
        continue;
    }

    // Gør alt lowercase
transform(valg1.begin(), valg1.end(), valg1.begin(), ::tolower);

// Valg1 flå
if(valg1 == "flå") {
    skrivLangsomt(criminalName + " tager fat i døren. Svenskergarnet går med det samme i panik og jokker sømmet i bund."); 
    skrivLangsomt("Den fine røde bil bliver nu endnu rødere, imens den pløjer et par turister ned." + criminalName + " bliver trukket næsten 100 meter, før " + criminalName + " bliver sendt flyvende op på fortovet.");
    skrivLangsommere("Av for helvede."); 
    health = 50;
    printStats();
    skrivLangsomt(criminalName + " kigger op og ser at Svenskergarnet er steget ud af bilen. Svenskergarnet har en pistol i hånden og peger den mod " + criminalName + ".");
    skrivLangsommere("Hvad gør du nu");
    break;

// Valg1 granat
} else if(valg1 == "granat") {
    skrivLangsomt(criminalName + " kaster en granat mod bilen. Granaten rammer ruden på bilen med et godt dunk. Granaten eksploderer. Både bilen og " + criminalName + " bliver sprunget i luften.");
    skrivLangsommere("WASTED");
    skrivLangsommere("Game over");
    return 0; // Game over betingelse

// Valg1 shotgun
} else if(valg1 == "shotgun") {
    skrivLangsomt("Du trækker din shotgun fra indersiden af Hawaiiskjorten. Du mærker dens tyngde i hænderne og smiler ondskabsfuldt. Svenskergarnet går med det samme i panik og jokker sømmet i bund."); 
    skrivLangsomt("Den tomme plads som Infernus'en efterlader afslører nu, at der holder en politilbil lige bag ved. Betjentene springer ud af bilen og trækker deres pistoler.");
    health = 100;
    power = 80;
    bevæbnet = true;
    printStats();
    skrivLangsomt(criminalName + " kigger op og ser at Svenskergarnet er steget ud af bilen. Svenskergarnet har en pistol i hånden og peger den mod " + criminalName + ".");
    skrivLangsommere("Hvad gør du nu?");
    break;

// Valg1 ugyldigt
} else {
    cout << "Ugyldigt valg. Prøv igen. C'mon, ægte gangstere kan godt stave" << endl;
}
}

// Valg2 muligheder
// Bygger videre på valg1 tager udgangspunkt i hvad der er valgt i valg1
cout << "Fuck the police! Skyd løs - tast 'skyd'" << endl;
cout << "Flygt! Løb til den nærliggende gyde - tast 'flygt'" << endl;

while (true)
{   
    cin >> valg2;
    if (valg2.length() > 20) {
        cout << "Valget er for langt. Indtast et kortere valg (maks 20 tegn): ";
        continue;
    }

    // Gør alt lowercase
transform(valg2.begin(), valg2.end(), valg2.begin(), ::tolower);

if(valg2 == "skyd") {
    if(bevæbnet){
        skrivLangsomt(criminalName + " begynder at skyde vildt omkring sig efter alt der kunne ligne en uniform. Betjente søger desperat dækning bag politibilen - stykker af metal og glas flyver om ørene på dem." );
        break;
    } else {skrivLangsomt(criminalName + " hæver armen og bevæger instinktivt sin trigger finger. Du har dog intet våben i hånden. Svenskergarnet spilder ingen tid med at pløkke dig ned.");
        skrivLangsommere("WASTED");
        skrivLangsommere("Game Over");
        return 0; // Game over betingelse
    }
} else if (valg2 == "flygt") {
    if(bevæbnet){ // Spilleren er bevæbnet
        skrivLangsomt(criminalName + " løber langsomt, det svært med en tung shotgun i hænderne."); 
        break;
    } else if(!bevæbnet) { // Spilleren er ikke bevæbnet
        skrivLangsomt(criminalName + " løber som én i fanden ind i gyden. Det er en blindgyde. Misandten om der ikke ligger noget og skinner, lige ved siden af affaldskontaineren. Det er en bazooka! " + criminalName + " ryster på hovedet og mumler 'kun i Vice City.'");
        break;
    } 
    
    } else {
        cout << "Ugyldigt valg. Prøv igen. C'mon, ægte gangstere kan godt stave" << endl;
        skrivLangsommere("Hvad gør du nu?");
        cout << "Fuck the police! Skyd løs - tast 'skyd'" << endl;
        cout << "Flygt! Løb til den nærliggende gyde - tast 'flygt'" << endl;
    }
    

}
}
