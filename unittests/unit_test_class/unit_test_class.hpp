#ifndef UNIT_TEST_CLASS_HPP
#define UNIT_TEST_CLASS_HPP

#include <functional>
#include <string>
#include <vector>

#define TITLE_FORMAT    "\e[1;34m"
#define SUCCESS_FORMAT  "\e[1;32m"
#define ERROR_FORMAT    "\e[1;31m"
#define RESET_FORMAT    "\e[0m"

namespace opmkUnitTest
{
    class UnitTest
    {
        private:
            std::function<bool(void)> _test_case;
            std::string _test_title;
    
        public:
            UnitTest(std::string test_title, std::function<bool(void)> test_case);
    
            bool run(void);
    };
    
    class Test 
    {
        private:
            unsigned int _success_count;
            unsigned int _error_count;
    
        public:
            Test();
    
            std::vector<UnitTest> vec_unit_tests;
    
            void run_tests(void);
    };
    
    extern int rec_signal;
    
    void sig_intercept(int signal);
    
    template<typename FSIG>
    std::string out_catch(std::function<FSIG> fn_that_prints);
}

#endif
