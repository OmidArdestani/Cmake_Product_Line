QT -= gui

TEMPLATE = lib
DEFINES += UNIQUEASSET3_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    uniqueasset3.cpp

HEADERS += \
    UniqueAsset3_global.h \
    uniqueasset3.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

#---------------------------------------------

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

