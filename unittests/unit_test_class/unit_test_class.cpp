#include "unit_test_class.hpp"

#include <csignal>
#include <iostream>

namespace opmkUnitTest
{
    SimpleUnitTest::SimpleUnitTest(
            std::string test_title,
            std::function<bool(void)> test_case)
    {
        _test_title = test_title;
        _test_case = test_case;
    }
    
    bool SimpleUnitTest::run(void)
    {
        std::cout << TITLE_FORMAT << _test_title << ": ";
    
        if (_test_case() == true)
        {
            std::cout << SUCCESS_FORMAT << "OK!" << RESET_FORMAT << std::endl;
            return true;
        }
    
        std::cout << ERROR_FORMAT << "FAIL." << RESET_FORMAT << std::endl;
    
        return false;
    }
    
    SimpleTest::SimpleTest()
    {
        _success_count = 0;
        _error_count = 0;
    }
    
    void SimpleTest::run_tests(void)
    {
        std::cout << RESET_FORMAT << "Number of tests: " << vec_unit_tests.size() << std::endl;
        
        for (unsigned int test_n = 0; test_n < vec_unit_tests.size(); ++test_n)
        {
            if (vec_unit_tests[test_n].run() == true)
                _success_count += 1;
            else
                _error_count += 1;
        }
    
        std::cout << RESET_FORMAT << "Finished, success count: " << _success_count << ", failures: " << _error_count << std::endl;
    }
    
    int rec_signal = 0;
    
    void sig_intercept(int signal)
    {
        std::cout << ERROR_FORMAT << "Signal: ";
    
        switch(signal)
        {
        case SIGABRT:
            std::cout << "SIGABRT" << RESET_FORMAT << std::endl;
            break;
        case SIGFPE:
            std::cout << "SIGFPE" << RESET_FORMAT << std::endl;
            break;
        case SIGILL:
            std::cout << "SIGILL" << RESET_FORMAT << std::endl;
            break;
        case SIGINT:
            std::cout << "SIGINT" << RESET_FORMAT << std::endl;
            break;
        case SIGSEGV:
            std::cout << "SIGSEGV" << RESET_FORMAT << std::endl;
            break;
        case SIGTERM:
            std::cout << "SIGTERM" << RESET_FORMAT << std::endl;
            break;
        }
    
        rec_signal = signal;
    }
    
    void init_sig_intercept(void)
    {
        std::signal(SIGABRT, sig_intercept);
        std::signal(SIGFPE, sig_intercept);
        std::signal(SIGILL, sig_intercept);
        std::signal(SIGINT, sig_intercept);
        std::signal(SIGSEGV, sig_intercept);
        std::signal(SIGTERM, sig_intercept);
    }
}
