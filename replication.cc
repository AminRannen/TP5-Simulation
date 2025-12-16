#include <CLHEP/Random/Random.h>
#include <CLHEP/Random/JamesRandom.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace CLHEP;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " stateIndex\n";
        return 1;
    }

    int i = std::stoi(argv[1]);
    HepJamesRandom rng;
    std::string stateFile = "state" + std::to_string(i) + ".rnd";
    rng.restoreStatus(stateFile.c_str());

    double sum = 0.0;
    for (int j = 0; j < 100; j++) {
        sum += rng.flat();
    }

    std::ofstream out("result" + std::to_string(i) + ".txt");
    out << sum;
    out.close();

    std::cout << "Replication " << i << " done, sum = " << sum << std::endl;

    return 0; 
}