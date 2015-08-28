#ifndef CITYQUERY_H
#define CITYQUERY_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include "abstractquery.h"

class CityQuery : public AbstractQuery
{
    Q_OBJECT
public:
    explicit CityQuery(QObject *parent = 0);
    QString getDataForId(int id);

signals:

public slots:

};

#endif // CITYQUERY_H
