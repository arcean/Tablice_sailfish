#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QDir>

#include "plate.h"
#include "platemodel.h"

#define PROVINCES_NUM 16
#define TEMPORARY_PLATE_TEXT "Tablica tymczasowa"
#define TEMPORARY_PLATE_CITY_TEXT "<t_tymcz>"
#define TEMPORARY_PLATE_CATEGORY_TEXT "Tymczasowe"
#define MILITARY_PLATES_TEXT "Wojsko"
#define NATIONAL_SERVICES_PLATES_TEXT "Instytucje"

class DataSource : public QObject {
    Q_OBJECT

public:
    explicit DataSource(QObject *parent = 0);

public slots:
    void insertValuesIntoMain(int id, QString tableCode);
    void insertValuesIntoDetails(int id, QString province, QString county, QString city);
    void createMainTable();
    void createDetailsTable();
    void openConncetion();
    void closeConnection();
    int getNumberOfEntries();
    void setListModel(PlateModel *model);
    void getFilteredModel(QString filter);
    void loadDataToModel();
    void createTemporaryPlates();

private:
    QSqlDatabase *db;
    PlateModel *model;
    PlateModel *filteredModel;
};

#endif // DATASOURCE_H
