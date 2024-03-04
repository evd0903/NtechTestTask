#include <iostream>

#include "Worker.h"

using namespace std;

int main() {
    auto worker = get_new_worker();
    
    Matrix case_1 = { {1, 2, 3, 4, 5, 6}, 3, 2};
    auto result_future_1 = worker->AsyncProcess(case_1);

    auto result = result_future_1.get();

    for (int i = 0; i < case_1.height; ++i) {
        for (int j = 0; j < case_1.width; ++j) {
            std::cout << case_1.data[i * result.width + j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < result.height; ++i) {
        for (int j = 0; j < result.width; ++j) {
            std::cout << result.data[i * result.width + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
