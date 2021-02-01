#include "EasyBMP/EasyBMP.h"
#include <ostream>

#include "fractalmodel.hpp"
#include "julia.hpp"

using namespace std;

int main() {
    // Début du timer
    double t1 = omp_get_wtime();

    // On associe un nombre de thread == au nombre que le processeur possède
    omp_set_num_threads(omp_get_num_procs());

    // Création d'un modèle de Fractal
    FractalModel fractalModel;
    fractalModel.setFractal(new Julia);
    fractalModel.setMinMax(-1.5, 1.5, -1.5, 1.5);
    fractalModel.setSize(2000, 2000);

    // Calcul de la fractal
    fractalModel.calculate();

    // Export du fichier en BMP
    fractalModel.getImage()->WriteToFile("out.bmp");

    // Fin du timer et affichage du temps d'export
    double t2 = omp_get_wtime() - t1;
    cout << "Fichier exporté en " << t2 << " secondes" << endl;
    
    return 1;
}