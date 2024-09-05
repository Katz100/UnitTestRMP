#include <QCoreApplication>
#include <QtTest>

// add necessary includes here

class Test : public QObject
{
    Q_OBJECT

public:
    Test();
    ~Test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

Test::Test() {}

Test::~Test() {}



void Test::cleanupTestCase() {}

void Test::test_case1() {}

QTEST_MAIN(Test)

#include "tst_test.moc"
