#include "../tests/tests.h"

using namespace std;

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestValidTransposing);

    return 0;
}
