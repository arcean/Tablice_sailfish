#include "settings.h"

Settings::Settings(QObject *parent) :
    QObject(parent)
{
}

void Settings::setEnableSearchingByCity(bool enable)
{
    QSettings settings;

    settings.setValue("searching/city", enable);
}

void Settings::setEnableSearchingByDistrict(bool enable)
{
    QSettings settings;

    settings.setValue("searching/district", enable);
}

void Settings::setEnableSearchingByDistrictB(bool enable)
{
    QSettings settings;

    settings.setValue("searching/districtB", enable);
}

void Settings::setEnableSearchingBySpecialPlates(bool enable)
{
    QSettings settings;

    settings.setValue("searching/special_plates", enable);
}

bool Settings::getEnableSearchingByCity()
{
    QSettings settings;
    bool value =  settings.value("searching/city", true).toBool();

    return value;
}

bool Settings::getEnableSearchingByDistrict()
{
    QSettings settings;
    bool value =  settings.value("searching/district", true).toBool();

    return value;
}

bool Settings::getEnableSearchingByDistrictB()
{
    QSettings settings;
    bool value =  settings.value("searching/districtB", false).toBool();

    return value;
}

bool Settings::getEnableSearchingBySpecialPlates()
{
    QSettings settings;
    bool value =  settings.value("searching/special_plates", true).toBool();

    return value;
}

void Settings::setLiveSearch(bool enable)
{
    QSettings settings;

    settings.setValue("searching/livesearch", enable);
}

bool Settings::getLiveSearch()
{
    QSettings settings;
    bool value =  settings.value("searching/livesearch", false).toBool();

    return value;
}
