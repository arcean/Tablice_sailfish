#include "platecodequery.h"

PlateCodeQuery::PlateCodeQuery(QObject *parent) :
    AbstractQuery()
{
    Q_UNUSED(parent);
}

QString PlateCodeQuery::getDataForId(int id)
{
    QSqlQuery query;
    query.exec(QString("select tableCode from main where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}
