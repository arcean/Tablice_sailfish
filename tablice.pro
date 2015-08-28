# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = tablice

CONFIG += sailfishapp

QT += sql

SOURCES += src/tablice.cpp \
    src/datasource.cpp \
    src/plate.cpp \
    src/settings.cpp \
    src/platemodel.cpp \
    src/abstractquery.cpp \
    src/provincequery.cpp \
    src/countyquery.cpp \
    src/cityquery.cpp \
    src/platecodequery.cpp

OTHER_FILES += qml/tablice.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/tablice.changes.in \
    rpm/tablice.spec \
    rpm/tablice.yaml \
    translations/*.ts \
    tablice.desktop \
    qml/pages/MainPage.qml \
    qml/pages/AboutPage.qml \
    qml/pages/LicensePage.qml \
    qml/pages/license.js

data.files = data/tablice.db.sqlite
data.path = /usr/share/$${TARGET}/data

INSTALLS += data

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/tablice-de.ts

RESOURCES +=

HEADERS += \
    src/definedValues.h \
    src/datasource.h \
    src/plate.h \
    src/settings.h \
    src/platemodel.h \
    src/abstractquery.h \
    src/provincequery.h \
    src/countyquery.h \
    src/cityquery.h \
    src/platecodequery.h

