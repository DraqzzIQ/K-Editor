#pragma once

#include <QTest>

#include "TestRunner.hpp"

namespace KEditor::Tests{

class SecondTestTemplate: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void checkCondition();
};

ADD_TEST_CLASS(SecondTestTemplate);

} //namespace KEditor::Tests
