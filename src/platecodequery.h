#ifndef PLATECODEQUERY_H
#define PLATECODEQUERY_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include "abstractquery.h"

class PlateCodeQuery : public AbstractQuery
{
    Q_OBJECT
public:
    explicit PlateCodeQuery(QObject *parent = 0);
    QString getDataForId(int id);

signals:

public slots:

};

#endif // PLATECODEQUERY_H
