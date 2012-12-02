#include <QtCore/QString>
#include <QtTest/QtTest>


class DailyorganiserTest : public QObject
{
    Q_OBJECT
    
public:
    DailyorganiserTest();
    
private Q_SLOTS:
    void testCase1();
};

DailyorganiserTest::DailyorganiserTest()
{
}

void DailyorganiserTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(DailyorganiserTest)

#include "tst_dailyorganisertest.moc"
