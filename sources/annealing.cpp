#include <annealing.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

using std::endl;
using std::cout;
using std::cin;

const double unomodal_function(const double& x) noexcept {
    return -0.5*cos(0.5*x) - 0.5;

}
const double multimodal_function(const double& x) noexcept {
    return std::sin(5*x) * (-0.5 * std::cos(0.5*x) - 0.5);
}

const std::vector<Measure> annealing(const double& minTemp,
        const double& maxTemp, const double(*func)(const double& x)) {
    std::srand(std::time(NULL));
    double temp = maxTemp;
    double xPrev = (static_cast<double>(std::rand()) /
        static_cast<double>(RAND_MAX/3)); // Previous point on the interval
    double valuePrev = func(xPrev);
    double x = 0;
    double value = 0;
    double delta = 0;
    size_t N = 1;
    std::vector<Measure> measures = {{1, temp, xPrev, valuePrev}};

    while (temp > minTemp) {
        x = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX/3);
        value = func(x);
        delta = value - valuePrev;
        if (delta <= 0) {
            xPrev = x;
            valuePrev = value;
        }else if (static_cast<double>(std::rand())/static_cast<double>(RAND_MAX)
                <= std::exp(-delta / temp)) {
            xPrev = x;
            valuePrev = value;
        }
        ++N;
        measures.emplace_back(N, temp, xPrev, valuePrev);
        temp *= 0.95;
    }
    return measures;
}

void print_measures(const std::vector<Measure> &measures) {
    cout << "|----------------------------------------------------------|\n";
    cout << "| " << std::setw(8) << "N";
    cout << " | " << std::setw(12) << "T";
    cout << " | " << std::setw(12) << "x";
    cout << " | " << std::setw(15) << "f(x)" << " |" << endl;;
    for (size_t i = 0; i < measures.size(); ++i) {
        cout << "|-" << std::setfill('-') << std::setw(8) << "-";
        cout << "-+-" << std::setw(12) << "-";
        cout << "-+-" << std::setw(12) << "-";
        cout << "-+-" << std::setw(15) << "-" << "-|" << endl;;

        cout << "| " << std::setfill(' ');
        cout << std::setw(8) << measures[i].number << " | ";
        cout << std::setw(12) << measures[i].temperature << " | ";
        cout << std::setw(12) << measures[i].x << " | ";
        cout << std::setw(15) << measures[i].value << " |" << endl;
    }
    cout << "|----------------------------------------------------------|\n";
    cout << "\tRESULT: Xmin = " << measures.back().x;
    cout << "\t\tFmin = " << measures.back().value << endl;
}
