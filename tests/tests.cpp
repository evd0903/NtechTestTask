#include "tests.h"

using namespace std;

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestValidTransposing);
    RUN_TEST(tr, TestRaceCondition);

    return 0;
}
