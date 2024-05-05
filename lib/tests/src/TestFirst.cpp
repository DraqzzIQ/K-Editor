#include "TestFirst.hpp"

namespace KEditor::Tests{

void FirstTestTemplate::initTestCase(){
    QCOMPARE("textToCompare", "textToCompare");
}

void FirstTestTemplate::firstCheck()
{
    QCOMPARE("Compare", "Compare");
}
} //namespace KEditor::Tests
