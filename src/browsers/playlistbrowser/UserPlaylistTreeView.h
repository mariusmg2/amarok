/****************************************************************************************
 * Copyright (c) 2008 Nikolaj Hald Nielsen <nhn@kde.org>                                *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 2 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

#ifndef USERPLAYLISTTREEVIEW_H
#define USERPLAYLISTTREEVIEW_H

#include "widgets/PrettyTreeView.h"

#include <QMutex>
#include <QTimer>

class PopupDropper;
class QAction;
class KAction;

namespace PlaylistBrowserNS {

class UserPlaylistTreeView : public Amarok::PrettyTreeView
{
    Q_OBJECT

public:
    explicit UserPlaylistTreeView( QAbstractItemModel *model, QWidget *parent = 0 );
    ~UserPlaylistTreeView();

    virtual void setModel( QAbstractItemModel *model );

    void setNewGroupAction( KAction * action );

protected:
    virtual void keyPressEvent( QKeyEvent *event );
    virtual void mousePressEvent( QMouseEvent *event );
    virtual void mouseReleaseEvent( QMouseEvent *event );
    virtual void mouseDoubleClickEvent( QMouseEvent *event );
    virtual void mouseMoveEvent( QMouseEvent *event );
    virtual void startDrag( Qt::DropActions supportedActions );

    virtual void contextMenuEvent( QContextMenuEvent* event );

private:
    QList<QAction *> actionsFor( QModelIndexList indexes );

    PopupDropper* m_pd;

    KAction *m_addGroupAction;

    bool m_ongoingDrag;
    QMutex m_dragMutex;
    bool m_expandToggledWhenPressed;
};

} // namespace PlaylistBrowserNS

#endif // USERPLAYLISTTREEVIEW_H
