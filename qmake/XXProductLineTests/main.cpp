#include <QtTest>
#include <SharedAssets/tst_sharedassets.h>
#include <UniqueAsset1/tst_uniqueasset1.h>
#include <UniqueAsset2/tst_uniqueasset2.h>
#include <UniqueAsset3/tst_uniqueasset3.h>
#include <UniqueAsset4/tst_uniqueasset4.h>

int main(int argc, char** argv) {
    int status = 0;
    {
        Test_SharedAssets tcSharedAssets;
        status |= QTest::qExec(&tcSharedAssets, argc, argv);
    }
    {
        Test_UniqueAsset1 tc1;
        status |= QTest::qExec(&tc1, argc, argv);
    }
    {
        Test_UniqueAsset2 tc2;
        status |= QTest::qExec(&tc2, argc, argv);
    }
    {
        Test_UniqueAsset3 tc3;
        status |= QTest::qExec(&tc3, argc, argv);
    }
    {
        Test_UniqueAsset4 tc4;
        status |= QTest::qExec(&tc4, argc, argv);
    }
    return status;
}
