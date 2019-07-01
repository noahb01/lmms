/*
 * FilteredDelay.cpp - [Put a very brief description of the effect here (not more than just a few words usually)]
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

#include "FilteredDelay.h"

#include "embed.h"
#include "plugin_export.h"

extern "C"
{

Plugin::Descriptor PLUGIN_EXPORT filtereddelay_plugin_descriptor =
{
	STRINGIFY( PLUGIN_NAME ),
	"FilteredDelay",
	QT_TRANSLATE_NOOP( "pluginBrowser", "[PUT YOUR PLUGIN DESCRIPTION HERE]" ),
	"[your name] [<youremail/at/gmailormaybenotgmail/dot/com>]",
	0x0100,
	Plugin::Effect,
	new PluginPixmapLoader("logo"),
	NULL,
	NULL
} ;

}



FilteredDelayEffect::FilteredDelayEffect( Model* parent, const Descriptor::SubPluginFeatures::Key* key ) :
	Effect( &filtereddelay_plugin_descriptor, parent, key ),
	m_filtereddelayControls( this )
{
}



FilteredDelayEffect::~FilteredDelayEffect()
{
}



bool FilteredDelayEffect::processAudioBuffer( sampleFrame* buf, const fpp_t frames )
{
	if( !isEnabled() || !isRunning () )
	{
		return( false );
	}

	double outSum = 0.0;
	const float d = dryLevel();
	const float w = wetLevel();
	
	checkGate( outSum / frames );

	return isRunning();
}





extern "C"
{

// necessary for getting instance out of shared lib
PLUGIN_EXPORT Plugin * lmms_plugin_main( Model* parent, void* data )
{
	return new FilteredDelayEffect( parent, static_cast<const Plugin::Descriptor::SubPluginFeatures::Key *>( data ) );
}

}

