/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  OCPN Draw Event Handler Support
 * Author:   Jon Gough
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 **************************************************************************/

#ifndef WINDVANEEVENTHANDLER_H
#define WINDVANEEVENTHANDLER_H

#include <wx/event.h>
#include <wx/timer.h>
#include "windvane_pi.h"

// Forward declarations

#define TIMER_WV_1 999

class WVEventHandler : public wxEvtHandler
{
    public:
        WVEventHandler(windvane_pi *parent);
        ~WVEventHandler();
        void StartSendTimer(int interval);
        void RestartSendtimer(int interval);
        void OnWVTimer1(wxTimerEvent& event);
        void OnWVTimer2(wxTimerEvent& event);
        void OnEventScrollThumbrelease(wxScrollEvent& event);
        
    protected:
    private:
        windvane_pi    *m_parent;
        wxTimer         WVTimer1;
        wxTimer         WVTimer2;
        bool            m_bWVTimer2Started;
        
        DECLARE_EVENT_TABLE();
};

#endif // WINDVANEEVENTHANDLER_H
