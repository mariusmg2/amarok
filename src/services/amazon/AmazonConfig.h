 /****************************************************************************************
 * Copyright (c) 2011 Sven Krohlas <sven@getamarok.com>                                 *
 * The Amazon store in based upon the Magnatune store in Amarok,                        *
 * Copyright (c) 2006,2007 Nikolaj Hald Nielsen <nhn@kde.org>                           *
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

#ifndef AMAZONCONFIG_H
#define AMAZONCONFIG_H

#include <QString>

class AmazonConfig
{
public:
    static AmazonConfig* instance();
    static void destroy();

    /**
    * Returns the domain for the store we want to interact with.
    * France: fr
    * Austria, Germany, Switzerland: de
    * Japan: co.jp
    * United Kingdom: co.uk
    * United States: com
    */
    QString country() const;

    /**
    * Sets the domain for the store we want to interact with.
    * @param country the domain to set.
    * France: fr
    * Austria, Germany, Switzerland: de
    * Japan: co.jp
    * United Kingdom: co.uk
    * United States: com
    */
    void setCountry( QString country );

    /**
    * Load current settings from disc.
    */
    void load();

    /**
    * Save current settings to disc.
    */
    void save();

private:
    AmazonConfig();
    ~AmazonConfig();

    QString m_country;
    static AmazonConfig* m_instance;
};

#endif // AMAZONCONFIG_H
