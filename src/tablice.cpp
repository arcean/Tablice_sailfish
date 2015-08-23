#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QtGlobal>
#include <QtQml>
#include <QQmlExtensionPlugin>
#include <QQuickView>
#include <QGuiApplication>
#include <sailfishapp.h>
#include <QDebug>

#include "definedValues.h"
#include "platemodel.h"
#include "plate.h"
#include "datasource.h"

void prepareApplicationInfo(QGuiApplication *sailfishApplication)
{
    sailfishApplication->setApplicationVersion(APPLICATION_VERSION);
    sailfishApplication->setApplicationName(APPLICATION_NAME);
    sailfishApplication->setApplicationDisplayName(APPLICATION_NAME);
}

void prepareDomainInfo(QGuiApplication *sailfishApplication)
{
    sailfishApplication->setOrganizationName(ORGANIZATION_NAME);
    sailfishApplication->setOrganizationDomain(ORGANIZATION_DOMAIN);
}

void prepareSailfishApplication(QGuiApplication *sailfishApplication)
{
    prepareApplicationInfo(sailfishApplication);
    prepareDomainInfo(sailfishApplication);
}

QUrl prepareUrlToQmlResource(QString resourceName)
{
    return SailfishApp::pathTo(QString("qml/%1.qml").arg(resourceName));
}

void prepareView(QQuickView *quickView)
{
    quickView->setSource(prepareUrlToQmlResource(APPLICATION_PROJECT_NAME));
}

PlateModel* createPlateModel(DataSource *dataSource)
{
    PlateModel *plateModel = new PlateModel();
    Plate *plate;

    qDebug() << "Trying to obtain number of entries...";
    int numberOfEntries = dataSource->getNumberOfEntries();
    qDebug() << "Number of entries: " << numberOfEntries;

    for (int i = 0; i < numberOfEntries; i++) {
        const QString city = dataSource->getCityForId(i);
        const QString province = dataSource->getProvinceForId(i);
        const QString county = dataSource->getCountyForId(i);
        const QString plateCode = dataSource->getPlateCodeForId(i);
        // FIXME: is category still needed ? Last plateCode is treated as category
        plate = new Plate(plateCode, city, county, province, plateCode);
        plateModel->addPlate(*plate);
        qDebug() << "Loaded entry " <<  i << "/" << numberOfEntries;
    }
    qDebug() << "returning...";

    return plateModel;
}

int main(int argc, char *argv[])
{
    int result = 0;
    QGuiApplication *sailfishApplication = SailfishApp::application(argc, argv);
    QQuickView *applicationView = SailfishApp::createView();

    prepareSailfishApplication(sailfishApplication);
    prepareView(applicationView);
    QQmlContext *context = applicationView->rootContext();
//    context->setContextProperty("platesModel",
//    qmlRegisterType<Tablice>(ORGANIZATION_DOMAIN + ".tablice",1,0,"Tablice");
    DataSource dataSource;
    PlateModel *plateModel = createPlateModel(&dataSource);// = new DataSource();
    context->setContextProperty("plateModel", plateModel);

    applicationView->show();
    result = sailfishApplication->exec();

    delete applicationView;
    delete sailfishApplication;

    return result;
}

