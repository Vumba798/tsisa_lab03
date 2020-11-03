#ifndef ANNEALING
#define ANNEALING
#include <vector>

struct Measure {
    size_t number = 0;
    double temperature = 0;
    double x = 0;
    double value = 0;

    inline Measure(const size_t& n,
        const double& temp,
        const double& point,
        const double& val) :
        number(n),
        temperature(temp),
        x(point),
        value(val) {}
};

const double unomodal_function(const double& x) noexcept;
const double multimodal_function(const double& x) noexcept;
const std::vector<Measure> annealing(const double& minTemp,
        const double& maxTemp, const double (*func)(const double& x));
void print_measures(const std::vector<Measure> &measures);

#endif //ANNEALING
