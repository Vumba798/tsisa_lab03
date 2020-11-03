#include <annealing.hpp>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    double tMin = 0;
    double tMax = 0;
    while(true) {
        cout << "Please, input minimal temperature: ";
        cin >> tMin;
        cout << "Plesae, input maximal temperature: ";
        cin >> tMax;
        if (tMax > tMin) {
            break;
        }
        cout << "tMin must be less than tMax!" << endl;
    }

    cout << "\n\n\t\tUnomodal function" << endl;
    print_measures(annealing(tMin, tMax, unomodal_function));
    cout << "\n\n\n\t\tMultimodal function" << endl;
    print_measures(annealing(tMin, tMax, multimodal_function));


    return 0;
}
