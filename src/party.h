/***************************************************************************
 * copyright            : (C) 2005 Seb Ruiz <seb100@optusnet.com.au>       *
****************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

/***************************************************************************
 * Infiltrations of Party Mode                                             *
 *   Party mode is a complex playlist handling mechanism - acting          *
 *   basically on the concept of a 'rotating' playlist.  The playlist can  *
 *   be modelled as a queuing system, FIFO.  As a track is advanced,       *
 *   the first track in the playlist is removed, and another appended to   *
 *   the end.  The type of addition is selected by the user during         *
 *   configuration.                                                        *
 *                                                                         *
 *   Due to the nature of this type of handling, the status of party-mode  *
 *   must be determined, as many function require alternate handling.      *
 *      Examples include:                                                  *
 *          - Context Menus                                                *
 *          - Double clicking on an item -> requires moving the item to    *
 *            front of the queue                                           *
 *          - Undo/Redo states, to reinit history items                    *
 *   Please be aware of these when working with party mode.                *
 ***************************************************************************/

#ifndef AMAROK_PARTY_H
#define AMAROK_PARTY_H

#include <qbuttongroup.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qlistbox.h>
#include <qpushbutton.h>
#include <qvbox.h>    //baseclass

#include <knuminput.h>
#include <klistview.h>

class PartyDialogBase;

class Party : public QVBox
{
        Q_OBJECT

    public:
        Party( QWidget *parent, const char *name = 0 );

        enum    Mode  { RANDOM=0, SUGGESTION=1, CUSTOM=2 };

        bool    isChecked();
        int     previousCount();
        int     upcomingCount();
        int     appendCount();
        int     appendType();
        bool    cycleTracks();
        bool    markHistory();
        QString customList();

    private slots:
        void    addPlaylists();
        void    subPlaylists();
        void    setAppendMode( int id );
        void    startParty();

    private:
        PartyDialogBase *m_base;

        void createWidget();
        void insertPlaylists();

        void applySettings();

        QLabel *m_tooltip;

        KListView *m_playlists;
};

#endif //AMAROK_PARTY_H
