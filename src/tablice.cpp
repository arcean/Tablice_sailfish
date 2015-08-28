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
#include "provincequery.h"
#include "countyquery.h"
#include "cityquery.h"
#include "platecodequery.h"
#include "platemodelfactory.h"

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

int main(int argc, char *argv[])
{
    int result = 0;
    QGuiApplication *sailfishApplication = SailfishApp::application(argc, argv);
    QQuickView *applicationView = SailfishApp::createView();

    prepareSailfishApplication(sailfishApplication);
    prepareView(applicationView);
    QQmlContext *context = applicationView->rootContext();
    DataSource dataSource;
    PlateModel *plateModel = PlateModelFactory::createPlateModel(&dataSource);
    PlateModel *filteredModel = plateModel;
    context->setContextProperty("plateModel", plateModel);
    context->setContextProperty("filteredModel", filteredModel);


    applicationView->show();
    result = sailfishApplication->exec();

    delete applicationView;
    delete sailfishApplication;

    return result;
}

