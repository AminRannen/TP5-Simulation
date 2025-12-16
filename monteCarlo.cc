#include <iostream>
#include <vector>
#include <cmath>
#include "CLHEP/Random/MTwistEngine.h"

int main() {
    const int Npoints = 1000000;  
    const int Nrep = 30;          
    std::vector<double> results(Nrep);

    CLHEP::MTwistEngine rng; 

    for(int rep=0; rep<Nrep; ++rep){
        int inside = 0;
        for(int i=0; i<Npoints; ++i){
            double x = rng.flat() * 2.0 - 1.0; 
            double y = rng.flat() * 2.0 - 1.0;
            double z = rng.flat() * 2.0 - 1.0;
            if(x*x + y*y + z*z <= 1.0) inside++;
        }
        results[rep] = 8.0 * inside / Npoints;
        std::cout << "Rep " << rep+1 << ": Volume = " << results[rep] << std::endl;
    }

    return 0;
}
