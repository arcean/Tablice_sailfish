#ifndef PROVINCEQUERY_H
#define PROVINCEQUERY_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include "abstractquery.h"

class ProvinceQuery : public AbstractQuery
{
    Q_OBJECT
public:
    explicit ProvinceQuery(QObject *parent = 0);
    QString getDataForId(int id);

signals:

public slots:

};

#endif // PROVINCEQUERY_H
