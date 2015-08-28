#include "abstractquery.h"

int AbstractQuery::getNumberOfEntries()
{
    QSqlQuery query;
    query.exec(QString("SELECT COUNT(id) FROM main"));
    query.next();

    return query.value(0).toInt();
}
