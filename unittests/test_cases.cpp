#include "unit_test_class.hpp"

#include <cstring>
#include <iostream>

extern "C"
{
#include "open_maker.h"
}


using namespace std;
using namespace opmkUnitTest;

static Test test_opmk_dbg;

void initialize_tests(void)
{
    SimpleUnitTest test1(
            "Test if memory_init initializes memory without failure",
            []() -> bool {
                memory_init();

                if (rec_signal != 0)
                {
                    rec_signal = 0;
                    return false;
                }
                return true;
            });
    test_libiso8583_demo.vec_unit_tests.push_back(test1);
}

int main(void)
{
    initialize_tests();
    test_libiso8583_demo.run_tests();
}
