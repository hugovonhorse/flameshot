// Copyright 2017 Alejandro Sirgo Rica
//
// This file is part of Flameshot.
//
//     Flameshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Flameshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Flameshot.  If not, see <http://www.gnu.org/licenses/>.

#ifndef FLAMESHOTDBUSADAPTER_H
#define FLAMESHOTDBUSADAPTER_H

#include <QtDBus/QDBusAbstractAdaptor>
#include "src/controller.h"

class FlameshotDBusAdapter : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.dharkael.Flameshot")

public:
    FlameshotDBusAdapter(Controller *parent = 0);
    virtual ~FlameshotDBusAdapter();
    inline Controller *parent() const;

public slots:
    Q_NOREPLY void openCapture();
    Q_NOREPLY void openCaptureWithPath(QString path);

    Q_NOREPLY void fullScreen(bool toClipboard);
    Q_NOREPLY void fullScreenWithPath(QString path, bool toClipboard);
};

#endif // FLAMESHOTDBUSADAPTER_H