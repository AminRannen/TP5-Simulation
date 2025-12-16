#include <CLHEP/Random/JamesRandom.h>
#include <CLHEP/Random/Random.h>
#include <iostream>

using namespace CLHEP;

int main() {
    HepJamesRandom rng;

    // Restaurer le générateur à l'état 5
    rng.restoreStatus("state5.rnd");

    // Générer quelques nombres pour tester
    for(int i=0; i<5; i++) {
        std::cout << rng.flat() << std::endl;
    }

    return 0;
}
