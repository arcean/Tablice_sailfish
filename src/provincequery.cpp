#include "provincequery.h"

ProvinceQuery::ProvinceQuery(QObject *parent) :
    AbstractQuery()
{
    Q_UNUSED(parent);
}

QString ProvinceQuery::getDataForId(int id)
{
    QSqlQuery query;
    query.exec(QString("select wojewodztwo from details where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}
