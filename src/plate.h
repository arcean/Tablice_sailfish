#ifndef PLATE_H
#define PLATE_H

#include <QObject>
#include <QHash>
#include <QVariant>


class Plate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString province READ province WRITE setProvince NOTIFY provinceChanged)
    Q_PROPERTY(QString county READ county WRITE setCounty NOTIFY countyChanged)
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)

public:
    explicit Plate(const QString &name, const QString &province, QObject *parent = 0);
    explicit Plate(const QString &plateCode, const QString &city, const QString &county, const QString &province, const QString &category, QObject *parent = 0);
    explicit Plate(const Plate& plate);
    inline QString id() const { return m_name; }
    inline QString name() const { return m_name; }
    inline QString province() const { return m_province; }
    inline QString county() const { return m_county; }
    inline QString city() const { return m_city; }
    inline QString category() const { return m_category; }

    void setCategory(QString category)
    {
        m_category = category;
        emit categoryChanged(m_category);
    }

    void setName(QString name)
    {
        m_name = name;
        emit nameChanged(name);
    }

    void setProvince(QString province)
    {
        m_province = province;
        emit provinceChanged(province);
    }

    void setCounty(QString county)
    {
        m_county = county;
        emit countyChanged(county);
    }

    void setCity(QString city)
    {
        m_city = city;
        emit cityChanged(city);
    }

signals:
    void dataChanged();
    void categoryChanged(QString);
    void nameChanged(QString);
    void provinceChanged(QString);
    void countyChanged(QString);
    void cityChanged(QString);

private:
    QString m_name;
    QString m_province;
    QString m_city;
    QString m_county;
    QString m_category;
};

#endif // PLATE_H
