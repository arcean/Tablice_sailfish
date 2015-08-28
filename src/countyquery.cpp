#include "countyquery.h"

CountyQuery::CountyQuery(QObject *parent) :
    AbstractQuery()
{
    Q_UNUSED(parent);
}

QString CountyQuery::getDataForId(int id)
{
    QSqlQuery query;
    query.exec(QString("select powiat from details where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}
