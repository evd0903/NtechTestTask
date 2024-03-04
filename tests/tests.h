#pragma once

#include "test_runner.h"
#include "../src/Worker.h"

inline void TestValidTransposing() {
    auto worker = get_new_worker();
    
    Matrix case_1 = { {1, 2, 3, 4, 5, 6}, 3, 2};
    Matrix expected_result_1 = {{1, 4, 2, 5, 3, 6}, 2, 3};

    Matrix case_2 = {{1, 2, 3, 4, 5, 6}, 2, 3};
    Matrix expected_result_2 = {{1, 3,5,2,4,6}, 3, 2};

    Matrix case_3 = { {1, 2, 3, 4}, 2, 2};
    Matrix expected_result_3 = {{1, 3, 2, 4}, 2, 2};

    Matrix case_4 = { {1, 0, 0, 2}, 2, 2};
    Matrix expected_result_4 = {{1, 0, 0, 2}, 2, 2};

    auto result_future_1 = worker->AsyncProcess(case_1);
    auto result_1 = result_future_1.get();

    auto result_future_2 = worker->AsyncProcess(case_2);
    auto result_2 = result_future_2.get();

    auto result_future_3 = worker->AsyncProcess(case_3);
    auto result_3 = result_future_3.get();

    auto result_future_4 = worker->AsyncProcess(case_4);
    auto result_4 = result_future_4.get();
    
    ASSERT_EQUAL(result_1.width, expected_result_1.width);
    ASSERT_EQUAL(result_1.height, expected_result_1.height);
    ASSERT_EQUAL(result_1, expected_result_1);

    ASSERT_EQUAL(result_2.width, expected_result_2.width);
    ASSERT_EQUAL(result_2.height, expected_result_2.height);
    ASSERT_EQUAL(result_2, expected_result_2);

    ASSERT_EQUAL(result_3.width, expected_result_3.width);
    ASSERT_EQUAL(result_3.height, expected_result_3.height);
    ASSERT_EQUAL(result_3, expected_result_3);

    ASSERT_EQUAL(result_4.width, expected_result_4.width);
    ASSERT_EQUAL(result_4.height, expected_result_4.height);
    ASSERT_EQUAL(result_4, expected_result_4);
}

inline void TestRaceCondition() {
    auto worker = get_new_worker();

    Matrix case_1 = { {1, 2, 3, 4}, 2, 2};
    Matrix expected_result_1 = {{1, 3, 2, 4}, 2, 2};

    auto result_future_1 = worker->AsyncProcess(case_1);
    auto result_future_2 = worker->AsyncProcess(case_1);
    auto result_future_3 = worker->AsyncProcess(case_1);

    auto result_1 = result_future_1.get();
    auto result_2 = result_future_2.get();
    auto result_3 = result_future_3.get();


    ASSERT_EQUAL(result_1.width, expected_result_1.width);
    ASSERT_EQUAL(result_1.height, expected_result_1.height);
    ASSERT_EQUAL(result_1, expected_result_1);

    ASSERT_EQUAL(result_2.width, expected_result_1.width);
    ASSERT_EQUAL(result_2.height, expected_result_1.height);
    ASSERT_EQUAL(result_2, expected_result_1);

    ASSERT_EQUAL(result_3.width, expected_result_1.width);
    ASSERT_EQUAL(result_3.height, expected_result_1.height);
    ASSERT_EQUAL(result_3, expected_result_1);
}
