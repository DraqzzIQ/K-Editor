#pragma once

#include <QObject>
#include <algorithm>
#include <vector>

namespace KEditor::Util {

class TestRunner
{
public:
    static TestRunner &instance();

    template<class T>
    T &addTest()
    {
        static T test;
        auto it = std::find(cbegin(tests_), cend(tests_), &test);
        if (it == cend(tests_)) {
            tests_.emplace_back(&test);
        }
        return test;
    }
    int execTests(int argc = 0, char **argv = nullptr);

private:
    TestRunner() {}
    std::vector<QObject *> tests_;
};
} //namespace KEditor::Util

#define ADD_TEST_CLASS(Class) \
    static Class &test_##Class = KEditor::Util::TestRunner::instance().addTest<Class>()

#define RUN_TESTS_MAIN \
    int main(int argc, char **argv) \
    { \
        return KEditor::Util::TestRunner::instance().execTests(argc, argv); \
    }
