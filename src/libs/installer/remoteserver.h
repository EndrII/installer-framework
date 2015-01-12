/**************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Installer Framework.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
**
** $QT_END_LICENSE$
**
**************************************************************************/

#ifndef REMOTESERVER_H
#define REMOTESERVER_H

#include "installer_global.h"
#include "protocol.h"

#include <QObject>

namespace QInstaller {

class RemoteServerPrivate;

class INSTALLER_EXPORT RemoteServer : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(RemoteServer)
    Q_DECLARE_PRIVATE(RemoteServer)

public:
    explicit RemoteServer(QObject *parent = 0);
    ~RemoteServer();

    void start();
    void init(quint16 port, const QString &authorizationKey, Protocol::Mode mode);

    quint16 port() const;
    QString authorizationKey() const;

private slots:
    void restartWatchdog();

private:
    QScopedPointer<RemoteServerPrivate> d_ptr;
};

} // namespace QInstaller

#endif // REMOTESERVER_H