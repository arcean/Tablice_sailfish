#include <QHash>
#include "plate.h"

Plate::Plate(const QString &name, const QString &province, QObject *parent) :
    QObject(parent), m_name(name), m_province(province)
{
}

Plate::Plate(const QString &plateCode, const QString &city, const QString &county, const QString &province, const QString &category, QObject *parent):
    QObject(parent), m_name(plateCode), m_city(city), m_county(county), m_province(province), m_category(category)
{
}

Plate::Plate(const Plate& plate)
{
    this->m_category = plate.category();
    this->m_city = plate.city();
    this->m_county = plate.county();
    this->m_name = plate.name();
    this->m_province = plate.province();
}
