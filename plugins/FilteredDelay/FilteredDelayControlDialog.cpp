/*
 * FilteredDelayControlDialog.cpp
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

#include <QLayout>

#include "FilteredDelayControlDialog.h"
#include "FilteredDelayControls.h"
#include "embed.h"



FilteredDelayControlDialog::FilteredDelayControlDialog( FilteredDelayControls* controls ) :
	EffectControlDialog( controls )
{
	setAutoFillBackground( true );
	QPalette pal;
	pal.setBrush( backgroundRole(), PLUGIN_NAME::getIconPixmap( "artwork" ) );
	setPalette( pal );
	setFixedSize( 300, 300 );

	Knob * volumeKnob = new Knob( knobBright_26, this);
	volumeKnob -> move( 16, 10 );
	volumeKnob -> setVolumeKnob( true );
	volumeKnob->setModel( &controls->m_volumeModel );
	volumeKnob->setLabel( tr( "VOL" ) );
	volumeKnob->setHintText( tr( "Volume:" ) , "%" );
	
	Knob * feedbackKnob = new Knob( knobBright_26, this);
	feedbackKnob -> move( 50, 10 );
	feedbackKnob -> setVolumeKnob( false );
	feedbackKnob->setModel( &controls->m_feedbackModel );
	feedbackKnob->setLabel( tr( "FDBK" ) );
	feedbackKnob->setHintText( tr( "Feedback:" ) , "%" );
	
	Knob * delayKnob = new Knob( knobBright_26, this);
	delayKnob -> move( 100, 10 );
	delayKnob -> setVolumeKnob( false );
	delayKnob->setModel( &controls->m_delayModel );
	delayKnob->setLabel( tr( "DLY" ) );
	delayKnob->setHintText( tr( "Delay:" ) , "s" );
}
