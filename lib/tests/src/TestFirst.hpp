#pragma once

#include <QTest>

#include "TestRunner.hpp"

namespace KEditor::Tests{

class FirstTestTemplate: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void firstCheck();
};

ADD_TEST_CLASS(FirstTestTemplate);

} //namespace KEditor::Tests
