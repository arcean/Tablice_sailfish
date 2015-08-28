#ifndef ABSTRACTQUERY_H
#define ABSTRACTQUERY_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QVariant>

class AbstractQuery : public QObject
{
    Q_OBJECT
public:
    virtual QString getDataForId(int id) = 0;
    int getNumberOfEntries();

signals:

public slots:

};

#endif // ABSTRACTQUERY_H
