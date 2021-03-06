/****************************************************************************
**
** Definition of QWaitCondition class
**
** Created : 931107
**
** Copyright (C) 1992-2008 Trolltech ASA.  All rights reserved.
**
** This file is part of the tools module of the Qt GUI Toolkit.
**
** This file may be used under the terms of the GNU General
** Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the files LICENSE.GPL2
** and LICENSE.GPL3 included in the packaging of this file.
** Alternatively you may (at your option) use any later version
** of the GNU General Public License if such license has been
** publicly approved by Trolltech ASA (or its successors, if any)
** and the KDE Free Qt Foundation.
**
** Please review the following information to ensure GNU General
** Public Licensing requirements will be met:
** http://trolltech.com/products/qt/licenses/licensing/opensource/.
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
** or contact the sales department at sales@trolltech.com.
**
** This file may be used under the terms of the Q Public License as
** defined by Trolltech ASA and appearing in the file LICENSE.QPL
** included in the packaging of this file.  Licensees holding valid Qt
** Commercial licenses may use this file in accordance with the Qt
** Commercial License Agreement provided with the Software.
**
** This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
** INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE. Trolltech reserves all rights not granted
** herein.
**
**********************************************************************/

#ifndef QWAITCONDITION_H
#define QWAITCONDITION_H

#ifndef QT_H
#include "qglobal.h"
#endif // QT_H

#if defined(QT_THREAD_SUPPORT)

#include <limits.h>

class QWaitConditionPrivate;
class QMutex;

class Q_EXPORT QWaitCondition
{
public:
    QWaitCondition();
    virtual ~QWaitCondition();

    // default argument causes thread to block indefinately
    bool wait( unsigned long time = ULONG_MAX );
    bool wait( QMutex *mutex, unsigned long time = ULONG_MAX );

    void wakeOne();
    void wakeAll();

private:
    QWaitConditionPrivate * d;

#if defined(Q_DISABLE_COPY)
    QWaitCondition( const QWaitCondition & );
    QWaitCondition &operator=( const QWaitCondition & );
#endif
};

#endif

#endif
