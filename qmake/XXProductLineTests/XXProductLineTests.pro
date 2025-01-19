QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp

include(UniqueAsset1/UniqueAsset1Test.pri)
include(UniqueAsset2/UniqueAsset2Test.pri)
include(UniqueAsset3/UniqueAsset3Test.pri)
include(UniqueAsset4/UniqueAsset4Test.pri)
include(SharedAssets/SharedAssetsTest.pri)


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SharedAssets/release/ -lSharedAssets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SharedAssets/debug/ -lSharedAssets
else:unix: LIBS += -L$$OUT_PWD/../SharedAssets/ -lSharedAssets

INCLUDEPATH += $$PWD/../SharedAssets
DEPENDPATH += $$PWD/../SharedAssets

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../SharedAssets/release/libSharedAssets.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../SharedAssets/debug/libSharedAssets.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../SharedAssets/release/SharedAssets.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../SharedAssets/debug/SharedAssets.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../SharedAssets/libSharedAssets.a

#---------------------------------------------

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset1/release/ -lUniqueAsset1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset1/debug/ -lUniqueAsset1
else:unix: LIBS += -L$$OUT_PWD/../UniqueAsset1/ -lUniqueAsset1

INCLUDEPATH += $$PWD/../UniqueAsset1
DEPENDPATH += $$PWD/../UniqueAsset1

#---------------------------------------------

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset2/release/ -lUniqueAsset2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset2/debug/ -lUniqueAsset2
else:unix: LIBS += -L$$OUT_PWD/../UniqueAsset2/ -lUniqueAsset2

INCLUDEPATH += $$PWD/../UniqueAsset2
DEPENDPATH += $$PWD/../UniqueAsset2

#---------------------------------------------

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset3/release/ -lUniqueAsset3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset3/debug/ -lUniqueAsset3
else:unix: LIBS += -L$$OUT_PWD/../UniqueAsset3/ -lUniqueAsset3

INCLUDEPATH += $$PWD/../UniqueAsset3
DEPENDPATH += $$PWD/../UniqueAsset3

#---------------------------------------------

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset4/release/ -lUniqueAsset4
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UniqueAsset4/debug/ -lUniqueAsset4
else:unix: LIBS += -L$$OUT_PWD/../UniqueAsset4/ -lUniqueAsset4

INCLUDEPATH += $$PWD/../UniqueAsset4
DEPENDPATH += $$PWD/../UniqueAsset4
