#include <CLHEP/Random/JamesRandom.h>
#include <iostream>
#include <fstream>
#include <omp.h>

using namespace CLHEP;

int main() {
    const int Nrep = 30;

    #pragma omp parallel for
    for (int i = 0; i < Nrep; ++i) {
        HepJamesRandom rng;
        std::string stateFile = "state" + std::to_string(i) + ".rnd";
        rng.restoreStatus(stateFile.c_str());

        double sum = 0.0;
        for (int j = 0; j < 100; ++j) sum += rng.flat();

        std::ofstream out("result" + std::to_string(i) + ".txt");
        out << sum;
        out.close();

        #pragma omp critical
        std::cout << "Replication " << i << " done, sum = " << sum << std::endl;
    }

    return 0;
}
