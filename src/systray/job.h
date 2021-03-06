/****************************************************************************
**
** Copyright (C) 2007-2015 Charles du Jeu - Abstrium SAS <team (at) pyd.io>
** This file is part of Pydio.
**
** Pydio is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Pydio is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Pydio.  If not, see <http://www.gnu.org/licenses/>.
**
**  The latest code can be found at <http://pyd.io/>.
**
****************************************************************************/
#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QUrl>
#include <QDateTime>

class Job : public QObject
{
    Q_OBJECT
public:
    explicit Job(QObject *parent = 0);
    Job(QString, QString, bool, bool, double, QString, QString, QString);
    void update(QString, bool, bool, double, QString);
    QString getJobDescription();
    QString getId();
    bool getStatus();
    QString getName();
    QUrl getLocal();
    QUrl getRemote();
    bool isSyncing();

signals:
    void updated(QString id);

private:
    QString name;
    bool hasWork;
    bool status;
    double remainingTime;
    QString id;
    QString lastEventMessage;
    QUrl local;
    QUrl remote;

    QString remainingTimeToString();

};

#endif // JOB_H
