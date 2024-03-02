#include "Worker.h"

#include <iostream>
#include <memory>

int main() {
    // Пример использования
    auto worker = get_new_worker();

    Matrix input = { {1, 2, 3, 4, 5, 6}, 3, 2};
    Matrix input1 = { {1, 2, 3, 4, 5, 6}, 2, 3};
    
    // Асинхронно запускаем транспонирование матрицы
    auto result_future = worker->AsyncProcess(std::move(input));
    auto result_future1 = worker->AsyncProcess(std::move(input1));

    // Получаем результат (возможно, не завершившийся)
    auto result = result_future.get();
    auto result1 = result_future1.get();

    // Выводим результат
    std::cout << "Transposed matrix:" << std::endl;
    for (unsigned i = 0; i < result.height; ++i) {
        for (unsigned j = 0; j < result.width; ++j) {
            std::cout << result.data[i * result.width + j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Transposed matrix1:" << std::endl;
    for (unsigned i = 0; i < result1.height; ++i) {
        for (unsigned j = 0; j < result1.width; ++j) {
            std::cout << result1.data[i * result1.width + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
