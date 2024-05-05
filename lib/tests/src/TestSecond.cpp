#include "TestSecond.hpp"

namespace KEditor::Tests{

void KEditor::Tests::SecondTestTemplate::initTestCase()
{
    QCOMPARE("init", "init");
}

void KEditor::Tests::SecondTestTemplate::checkCondition()
{
    QCOMPARE("second", "second");
}

} //namespace KEditor::Tests
