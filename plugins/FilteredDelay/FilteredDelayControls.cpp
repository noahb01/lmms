/*
 * FilteredDelayControls.cpp
 *
 * Copyright (c) [the year] [your name] [<youremail/at/gmailormaybenotgmail/dot/com>]
 *
 * This file is part of LMMS - https://lmms.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#include <QDomElement>

#include "FilteredDelayControls.h"
#include "FilteredDelay.h"
#include "Engine.h"
#include "Song.h"


FilteredDelayControls::FilteredDelayControls( FilteredDelayEffect* effect ) :
	EffectControls( effect ),
	m_effect( effect ),
	m_volumeModel( 100.0f, 0.0f, 200.0f, 0.1f, this, tr( "Volume" ) ),
	m_feedbackModel( 100.0f, 0.0f, 100.0f, 0.1f, this, tr( "Feedback" ) ),
	m_delayModel( 1.0f, 0.0f, 10.0f, 0.05f, this, tr( "Delay" ) )
{
}



void FilteredDelayControls::loadSettings( const QDomElement& _this )
{
	m_volumeModel.loadSettings( _this, "volume" );
	m_feedbackModel.loadSettings( _this, "feedback" );
	m_delayModel.loadSettings( _this, "delay" );
}




void FilteredDelayControls::saveSettings( QDomDocument& doc, QDomElement& _this )
{
	m_volumeModel.saveSettings( doc, _this, "volume" ); 
	m_feedbackModel.saveSettings( doc, _this, "feedback" );
	m_delayModel.saveSettings( doc, _this, "delay" );
}





