#include <iostream>
#include "CLHEP/Random/MTwistEngine.h"
int main(){
    CLHEP::MTwistEngine mt;
    std::cout <<"Premiers Tirages sans sauvegarde" <<std::endl;
    for(int i=0;i<10;i++){
        std::cout << mt.flat() <<" ";
    }
    std::cout<<std::endl;
       std::cout <<"Second tirages sans sauvegarde" <<std::endl;
    for(int i=0;i<10;i++){
        std::cout << mt.flat() <<" ";
    }
    std::cout<<std::endl;
        /*maintenant on sauvegarde */

    mt.saveStatus("statusMT.txt");
       std::cout << "Statut sauvegardé dans statusMT.txt" << std::endl;
    std::cout << "Tirages après sauvegarde:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << mt.flat() << " ";
    }
    std::cout << std::endl;

 mt.restoreStatus("statusMT.txt");
    std::cout << "Statut restauré" << std::endl;

    std::cout << "Tirages après restauration:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << mt.flat() << " ";
    }
    std::cout << std::endl;

    return 0;
}