#include "Worker.h"

std::shared_ptr<WorkerInterface> get_new_worker() {
    return std::make_shared<TransposeWorker>();
}

std::future<Matrix> TransposeWorker::AsyncProcess(Matrix input) {
        std::lock_guard<std::mutex> lock(mutex_);
        return std::async(std::launch::async, &TransposeWorker::Transpose, this, std::move(input));
}

Matrix TransposeWorker::Transpose(Matrix input) {
    Matrix result;
    result.width = input.height;
    result.height = input.width;

    for (int j = 0; j < input.width; ++j) {
        for (int i = 0; i < input.height; ++i) {
            result.data.push_back(input.data[i * input.width + j]);
        }
    }

    return result;
}
