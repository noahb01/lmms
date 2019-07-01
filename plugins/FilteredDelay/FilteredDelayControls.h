/*
 * FilteredDelayControls.h
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

#ifndef FILTEREDDELAY_CONTROLS_H
#define FILTEREDDELAY_CONTROLS_H

#include "EffectControls.h"
#include "FilteredDelayControlDialog.h"
#include "Knob.h"


class FilteredDelayEffect;


class FilteredDelayControls : public EffectControls
{
	Q_OBJECT
public:
	FilteredDelayControls( FilteredDelayEffect* effect );
	virtual ~FilteredDelayControls()
	{
	}

	virtual void saveSettings( QDomDocument & _doc, QDomElement & _parent );
	virtual void loadSettings( const QDomElement & _this );
	inline virtual QString nodeName() const
	{
		return "FilteredDelayControls";
	}

	virtual int controlCount()
	{
		return 4; // I'll be honest, I'm not certain of what this is for.  You're probably supposed to put the number of knobs/faders/buttons/widgets/things here.
	}

	virtual EffectControlDialog* createView()
	{
		return new FilteredDelayControlDialog( this );
	}

private:
	FilteredDelayEffect* m_effect;

	FloatModel m_volumeModel;
	FloatModel m_feedbackModel;
	FloatModel m_delayModel;

	friend class FilteredDelayControlDialog;
	friend class FilteredDelayEffect;

} ;

#endif
