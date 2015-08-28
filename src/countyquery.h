#ifndef COUNTYQUERY_H
#define COUNTYQUERY_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include "abstractquery.h"

class CountyQuery : public AbstractQuery
{
    Q_OBJECT
public:
    explicit CountyQuery(QObject *parent = 0);
    QString getDataForId(int id);

signals:

public slots:

};

#endif // COUNTYQUERY_H
