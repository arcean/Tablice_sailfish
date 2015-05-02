/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QtGlobal>
#include <QtQml>
#include <QQmlExtensionPlugin>
#include <QQuickView>
#include <QGuiApplication>
#include <sailfishapp.h>

#include "definedValues.h"

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
//    qmlRegisterType<Tablice>(ORGANIZATION_DOMAIN + ".tablice",1,0,"Tablice");
    applicationView->show();
    result = sailfishApplication->exec();

    delete applicationView;
    delete sailfishApplication;

    return result;
}

