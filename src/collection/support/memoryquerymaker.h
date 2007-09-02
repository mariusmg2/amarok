/*
   Copyright (C) 2007 Maximilian Kossick <maximilian.kossick@googlemail.com>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*/

#ifndef MEMORYQUERYMAKER_H
#define MEMORYQUERYMAKER_H

#include "memorycollection.h"
#include "QueryMaker.h"

namespace ThreadWeaver
{
    class Job;
}

class MemoryQueryMaker : public QueryMaker
{
    Q_OBJECT
    public:
        MemoryQueryMaker( MemoryCollection *mc, const QString &collectionId );
        virtual ~MemoryQueryMaker();

        virtual QueryMaker* reset();
        virtual void run();
        virtual void abortQuery();

        virtual QueryMaker* startTrackQuery();
        virtual QueryMaker* startArtistQuery();
        virtual QueryMaker* startAlbumQuery();
        virtual QueryMaker* startComposerQuery();
        virtual QueryMaker* startGenreQuery();
        virtual QueryMaker* startYearQuery();
        virtual QueryMaker* startCustomQuery();

        virtual QueryMaker* returnResultAsDataPtrs( bool resultAsDataPtrs );

        virtual QueryMaker* addReturnValue( qint64 value );
        virtual QueryMaker* orderBy( qint64 value, bool descending = false );

        virtual QueryMaker* includeCollection( const QString &collectionId );
        virtual QueryMaker* excludeCollection( const QString &collectionId );

        virtual QueryMaker* addMatch( const Meta::TrackPtr &track );
        virtual QueryMaker* addMatch( const Meta::ArtistPtr &artist );
        virtual QueryMaker* addMatch( const Meta::AlbumPtr &album );
        virtual QueryMaker* addMatch( const Meta::ComposerPtr &composer );
        virtual QueryMaker* addMatch( const Meta::GenrePtr &genre );
        virtual QueryMaker* addMatch( const Meta::YearPtr &year );
        virtual QueryMaker* addMatch( const Meta::DataPtr &data );

        virtual QueryMaker* addFilter( qint64 value, const QString &filter, bool matchBegin, bool matchEnd );
        virtual QueryMaker* excludeFilter( qint64 value, const QString &filter, bool matchBegin, bool matchEnd );

        virtual QueryMaker* limitMaxResultSize( int size );

        virtual QueryMaker* beginAnd();
        virtual QueryMaker* beginOr();
        virtual QueryMaker* endAndOr();

        //MemoryQueryMaker specific methods
        void runQuery();
        void handleResult();
        void handleResult( const Meta::TrackList &tracks );

    private slots:
        void done( ThreadWeaver::Job * job );

    protected:
        MemoryCollection *m_memCollection;
        QString m_collectionId;
        class Private;
        Private * const d;
};

class Matcher {
    public:
        Matcher();
        virtual ~Matcher();
        virtual Meta::TrackList match( MemoryCollection *memColl) = 0;
        virtual Meta::TrackList match( const Meta::TrackList &tracks ) = 0;

        bool isLast() const;
        void setNext( Matcher *next );
        Matcher* next() const;

    private:
        Matcher *m_next;
};

#endif
