#include <QtTest>
#include "component.h"

class testComponent : public QObject{
    
    Q_OBJECT

public:
    testComponent();
    ~testComponent();

private slots:
    void TestCase1();
    void TestCase2();
};

testComponent::testComponent(){}

testComponent::~testComponent(){}

void testComponent::TestCase1(){
    int expectedResult  = 2;
    int calculatedResult = 1 + 1;
    QCOMPARE(expectedResult,calculatedResult); // This will pass the test
}

void testComponent::TestCase2(){
    int expectedResult  = 1;
    int calculatedResult = 1 + 1;
    QCOMPARE(expectedResult,calculatedResult); // This will fail the test
}

QTEST_APPLESS_MAIN(testComponent)

#include "tst_component.moc"
