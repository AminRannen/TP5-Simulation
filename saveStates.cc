#include <CLHEP/Random/JamesRandom.h>
#include <fstream>
#include <iostream>

using namespace CLHEP;

int main() {
    HepJamesRandom rng;

    rng.setSeed(12345);

    for (int i = 0; i < 30; i++) {

        std::string filename = "state" + std::to_string(i) + ".rnd";

        rng.saveStatus(filename.c_str());
        std::cout << "Saved state " << i << " in file " << filename << std::endl;

        for (int k = 0; k < 100000; k++) {
            rng.flat();
        }
    }

    return 0;
}
