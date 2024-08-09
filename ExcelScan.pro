QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analysisjson.cpp \
    createrule.cpp \
    main.cpp \
    mainwindow.cpp \
    makerule.cpp \
    rule.cpp \
    ruletemplate.cpp \
    templatedescription.cpp

HEADERS += \
    analysisjson.h \
    createrule.h \
    mainwindow.h \
    makerule.h \
    rule.h \
    ruletemplate.h \
    templatedescription.h

FORMS += \
    createrule.ui \
    mainwindow.ui \
    makerule.ui \
    templatedescription.ui
msvc
{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#QXlsx
INCLUDEPATH += $$PWD/thirdparty/include
debug
{
    LIBS += -L$$PWD/thirdparty/lib/debug -lQXlsx
}
release
{
    LIBS += -L$$PWD/thirdparty/lib/release -lQXlsx
}
