#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

double processArray(double input[20], double output[20]) {
    srand(time(0));

    double min_val = -20.0;
    double max_val = 70.0;
    double range = max_val - min_val;

    double max_abs = 0.0;

    for (int i = 0; i < 20; i++) {
        input[i] = min_val + (range * rand() / RAND_MAX);
        double abs_val = fabs(input[i]);
        if (abs_val > max_abs) {
            max_abs = abs_val;
        }
    }

    for (int i = 0; i < 20; i++) {
        if (max_abs != 0) {
            output[i] = input[i] / max_abs;
        }
        else {
            output[i] = 0.0;
        }
    }

    return max_abs;
}

int main() {
    setlocale(LC_ALL, ".1251");

    double input[20];
    double output[20];

    double max_abs = processArray(input, output);

    std::cout << "Vhod:\n";
    for (int i = 0; i < 20; i++) {
        std::cout << std::fixed << std::setprecision(2) << input[i] << " ";
    }
    std::cout << "\n";

    std::cout << "max Item = " << std::fixed << std::setprecision(2) << max_abs << "\n";

    std::cout << "Vyhod:\n";
    for (int i = 0; i < 20; i++) {
        std::cout << std::fixed << std::setprecision(6) << output[i] << " ";
    }
    std::cout << "\n";

    return 0;
}