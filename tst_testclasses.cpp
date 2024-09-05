#include <QCoreApplication>
#include <QTest>

// add necessary includes here

#include "../RMP_LosRios/database.h"
#include "../RMP_LosRios/networkmanager.h"

class TestClasses : public QObject
{
    Q_OBJECT

public:
    TestClasses();
    ~TestClasses();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_register();
    void test_login_user();
    void test_logout();
    void test_change_username();
    void test_get_teacher();
    void test_get_course();
    void test_get_reviews();
    void test_profanity();
private:
    Database* databaseTest;
    NetWorkManager* networkTest;
};

TestClasses::TestClasses() {}

TestClasses::~TestClasses()
{
    delete databaseTest;
    delete networkTest;
}

void TestClasses::initTestCase()
{
    databaseTest = new Database(nullptr);
    networkTest = new NetWorkManager(nullptr);
}

void TestClasses::cleanupTestCase() {}

void TestClasses::test_login_user()
{
    databaseTest->loginUser("TestLogin");
    QCOMPARE(QString("TestLogin"), databaseTest->username());
    QVERIFY(databaseTest->loggedIn());
}

void TestClasses::test_logout()
{
    databaseTest->logout();
    QCOMPARE(QString("Guest"), databaseTest->username());
    QVERIFY(!databaseTest->loggedIn());
}

void TestClasses::test_register()
{
    databaseTest->registerUser("ok", "pass", "salt");
    QSqlQuery query;
    query.prepare("SELECT username, password FROM users WHERE username = 'ok'");
    QVERIFY(query.exec());

    QCOMPARE(true, databaseTest->validateLogin("ok", "pass"));

    QSqlQuery query_delete;
    query_delete.prepare("DELETE FROM Users WHERE username = 'ok' AND password = 'pass'");
    QVERIFY(query_delete.exec());
}

void TestClasses::test_change_username()
{
    databaseTest->registerUser("UnitTestUser", "pass", "salt");
    databaseTest->changeUsername("new_username");
    QCOMPARE(databaseTest->username(), "new_username");
    databaseTest->deleteUser();

}

void TestClasses::test_get_teacher()
{
    QCOMPARE(databaseTest->getTeacher(1), "Valerie A. Rohret");
}

void TestClasses::test_get_course()
{
    QCOMPARE(databaseTest->getCourse(1), "Into to programming");
}

void TestClasses::test_get_reviews()
{
    //TODO
}

void TestClasses::test_profanity()
{
    QVERIFY(networkTest->hasProfanity("This is a fucking message."));
    QCOMPARE(false, networkTest->hasProfanity("This is a message"));
}


QTEST_MAIN(TestClasses)

#include "tst_testclasses.moc"
