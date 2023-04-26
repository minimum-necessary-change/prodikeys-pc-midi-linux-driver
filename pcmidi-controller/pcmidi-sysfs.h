/***************************************************************
 * Name:      pcmidi_sysfs.h
 * Purpose:   Code for sysfs access
 * Author:    Don Prince (https://sourceforge.net/projects/pc-midi-linux/forums)
 * Created:   2009-10-07
 * Copyright: Don Prince (https://sourceforge.net/projects/pc-midi-linux/)
 * License:
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
***************************************************************/

#ifndef PCMIDI_LIB_SYSFS_H
#define PCMIDI_LIB_SYSFS_H

#define SYSFS_SUPPORT

#ifdef SYSFS_SUPPORT
extern int pcmidi_found_sysfs;

extern char pcmidi_sysfs_mount[];

extern int pcmidi_init_sysfs(void);

extern int pcmidi_read_sysfs_hid_bus(void);

extern int pcmidi_read_channel(void);

extern void pcmidi_write_channel(int channel);

extern int pcmidi_read_octave(void);

extern void pcmidi_write_octave(int octave);

extern int pcmidi_read_sustain(void);

extern void pcmidi_write_sustain(int sustain);
#else

#define pcmidi_found_sysfs 0
#define char pcmidi_sysfs_mount[] 0
#define pcmidi_init_sysfs() 0
#define pcmidi_read_sysfs_hid_bus() 0

#endif

#endif /* !PCMIDI_LIB_SYSFS_H */
