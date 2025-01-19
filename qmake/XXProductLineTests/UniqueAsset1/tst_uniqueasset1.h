
#include <QObject>

class Test_UniqueAsset1 : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();    // Runs before any test function is executed
    void cleanupTestCase(); // Runs after all test functions are executed
    void testInitialization(); // Test object initialization
    void testFunctionality();  // Test specific functionality
    void testEdgeCases();      // Test edge cases and error handling
};


