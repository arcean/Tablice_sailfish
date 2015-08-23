#include <QVariant>
#include <QDebug>

#include "datasource.h"

DataSource::DataSource(QObject *parent) :
    QObject(parent) {
    openConncetion();
}

void DataSource::openConncetion()
{
    // FIXME: WTF db?!
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path(QDir::separator());
    path.append("usr");
    path.append(QDir::separator()).append("share");
    path.append(QDir::separator()).append("tablice");
    path.append(QDir::separator()).append("data");
    path.append(QDir::separator()).append("tablice.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);
    db.open();
}

void DataSource::closeConnection()
{
    if(db->isOpen())
        db->close();
}

void DataSource::setListModel(PlateModel *model)
{
    this->model = model;
}

void DataSource::createMainTable()
{
    // FIXME: ERM query, WTF?
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS main (id INT PRIMARY KEY, "
               "tableCode VARCHAR(20))");
}

void DataSource::createDetailsTable()
{
    // FIXME: ERM query, WTF?
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS details (id INT PRIMARY KEY, "
               "province VARCHAR(20), powiat VARCHAR(30), miasto VARCHAR(20))");
}

// FIXME: merge function below
void DataSource::insertValuesIntoMain(int id, QString tableCode)
{
    QSqlQuery query;

    if (id == -1) {
        /* It's time for auto increment function */
        query.exec(QString("INSERT INTO main VALUES(NULL,'%1')")
                   .arg(tableCode));
    }
    else {
        query.exec(QString("INSERT INTO main VALUES(%1,'%2')")
                   .arg(id).arg(tableCode));
    }
}

// FIXME: with this one
void DataSource::insertValuesIntoDetails(int id, QString province, QString county, QString city)
{
    QSqlQuery query;

    if (id == -1) {
        /* It's time for auto increment function */
        query.exec(QString("INSERT INTO details VALUES(NULL,'%1','%2','%3')")
                   .arg(province).arg(county).arg(city));
    }
    else {
        query.exec(QString("INSERT INTO details VALUES(%1,'%2','%3','%4')")
                   .arg(id).arg(province).arg(county).arg(city));
    }
}

// FIXME: ERM query, WTF?
int DataSource::getNumberOfEntries()
{
    QSqlQuery query;
    query.exec(QString("SELECT COUNT(id) FROM main"));
    query.next();

    return query.value(0).toInt();
}

// FIXME: ERM query, WTF?
QString DataSource::getPlateCodeForId(int id)
{
    QSqlQuery query;
    query.exec(QString("select tableCode from main where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}


/*
 * FIXME: ERM query, WTF?
 * Merge these 3 functions.
 */
QString DataSource::getProvinceForId(int id)
{
    QSqlQuery query;
    query.exec(QString("select wojewodztwo from details where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}

// FIXME: ERM query, WTF?
QString DataSource::getCountyForId(int id)
{
    QSqlQuery query;
    query.exec(QString("select powiat from details where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}

// FIXME: ERM query, WTF?
QString DataSource::getCityForId(int id)
{
    QSqlQuery query;

    query.exec(QString("select miasto from details where id = %1")
               .arg(id));
    query.next();

    return query.value(0).toString();
}

void DataSource::loadDataToModel()
{
    Plate *item;
    int numberOfEntries = getNumberOfEntries();

    for (int i = 0; i < numberOfEntries; i++) {
        QString name = getPlateCodeForId(i);
        item = new Plate(name, getProvinceForId(i));
        item->setCounty(getCountyForId(i));
        item->setCity(getCityForId(i));
        item->setProvince(getProvinceForId(i));
        // FIXME: WTF?!
        name.chop(name.length()-1);

        // Military plates
        if (name.compare("U") == 0)
            name = QStringLiteral(MILITARY_PLATES_TEXT);

        // National services plates.
        if (name.compare("H") == 0)
            name = QStringLiteral(NATIONAL_SERVICES_PLATES_TEXT);

        item->setCategory(name);
        model->addPlate(*item);
    }
}

void DataSource::createTemporaryPlates()
{
    Plate *item;
    QString provinceName[PROVINCES_NUM];
    QString provinceCategory[PROVINCES_NUM];
    provinceCategory[0] = "B";
    provinceCategory[1] = "C";
    provinceCategory[2] = "D";
    provinceCategory[3] = "E";
    provinceCategory[4] = "F";
    provinceCategory[5] = "G";
    provinceCategory[6] = "K";
    provinceCategory[7] = "L";
    provinceCategory[8] = "N";
    provinceCategory[9] = "O";
    provinceCategory[10] = "P";
    provinceCategory[11] = "R";
    provinceCategory[12] = "S";
    provinceCategory[13] = "T";
    provinceCategory[14] = "W";
    provinceCategory[15] = "Z";

    provinceName[0] = "podlaskie";
    provinceName[1] = "kujawsko-pomorskie";
    provinceName[2] = QString::fromUtf8("dolnośląskie");
    provinceName[3] = QString::fromUtf8("łódzkie");
    provinceName[4] = "lubuskie";
    provinceName[5] = "pomorskie";
    provinceName[6] = QString::fromUtf8("małopolskie");
    provinceName[7] = "lubelskie";
    provinceName[8] = QString::fromUtf8("warmińsko-mazurskie");
    provinceName[9] = "opolskie";
    provinceName[10] = "wielkopolskie";
    provinceName[11] = "podkarpackie";
    provinceName[12] = QString::fromUtf8("śląskie");
    provinceName[13] = QString::fromUtf8("świętokrzyskie");
    provinceName[14] = "mazowieckie";
    provinceName[15] = "zachodniopomorskie";

    for (int j = 0; j < PROVINCES_NUM; j++)
        for (int i = 0; i < 10; i++) {
            item = new Plate(provinceCategory[j] + QString::number(i), provinceName[j]);
            item->setCounty(QStringLiteral(TEMPORARY_PLATE_TEXT));
            item->setCity(QStringLiteral(TEMPORARY_PLATE_CITY_TEXT));
            item->setCategory(QStringLiteral(TEMPORARY_PLATE_CATEGORY_TEXT));
            model->addPlate(*item);
        }
}
