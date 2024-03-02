#pragma once

#include <future>
#include <vector>
#include <memory>

struct Matrix {
    std::vector<int> data;
    unsigned width, height;
};

class WorkerInterface {
public:
    WorkerInterface() = default;

    WorkerInterface(WorkerInterface &&) = delete;
    WorkerInterface(const WorkerInterface &) = delete;
    WorkerInterface & operator=(WorkerInterface &&) = delete;
    WorkerInterface & operator=(const WorkerInterface &) = delete;

    virtual ~WorkerInterface() = default;

    virtual std::future<Matrix> AsyncProcess(Matrix) = 0;
};

std::shared_ptr<WorkerInterface> get_new_worker();

class TransposeWorker : public WorkerInterface {
public:
    std::future<Matrix> AsyncProcess(Matrix input) override;

private:
    Matrix Transpose(Matrix input);

    std::mutex mutex_;
};