#include "cityquery.h"

CityQuery::CityQuery(QObject *parent) :
    AbstractQuery()
{
    Q_UNUSED(parent);
}

QString CityQuery::getDataForId(int id)
{
    QSqlQuery query;
    query.exec(QString("select miasto from details where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}
