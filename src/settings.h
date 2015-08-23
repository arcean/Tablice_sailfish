#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);

    // FIXME: rename functions
    // FIXME: change district to province, districtB to county
public slots:
    void setEnableSearchingByCity(bool enable);
    void setEnableSearchingByDistrict(bool enable);
    void setEnableSearchingByDistrictB(bool enable);
    void setEnableSearchingBySpecialPlates(bool enable);
    bool getEnableSearchingByCity();
    bool getEnableSearchingByDistrict();
    bool getEnableSearchingByDistrictB();
    bool getEnableSearchingBySpecialPlates();
    void setLiveSearch(bool enable);
    bool getLiveSearch();

};

#endif // SETTINGS_H
