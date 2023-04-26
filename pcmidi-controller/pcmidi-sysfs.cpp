/***************************************************************
 * Name:      pcmidi_sysfs.cpp
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

/* this define needed for strndup() */
//#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <sysfs/libsysfs.h>
#include "pcmidi-sysfs.h"

int pcmidi_found_sysfs = 0;

char pcmidi_sysfs_mount[SYSFS_PATH_MAX];


/* returns !0 if sysfs filesystem was found, 0 otherwise */
int pcmidi_init_sysfs(void)
{
    char sysfs_mount[SYSFS_PATH_MAX];
	struct stat statbuf;

	/* libsysfs will return success even if sysfs is not mounted,
	   so we have to double-check */
	if (sysfs_get_mnt_path(sysfs_mount, NAME_MAX) == 0
	 && stat(sysfs_mount, &statbuf) == 0
	 && statbuf.st_nlink > 2)
		pcmidi_found_sysfs = 1;

	return pcmidi_found_sysfs;
}

/* returns: 0 if successful, !0 otherwise */
static int pcmidi_read_one_sysfs_device(struct sysfs_device *dev)
{
	struct sysfs_attribute *attr;

	if (NULL == strstr(dev->name, "041E:2801"))
        return -1;
	if (!(attr = sysfs_get_device_attr(dev, "channel")))
		return -1;
	if (!(attr = sysfs_get_device_attr(dev, "octave")))
		return -1;
	if (!(attr = sysfs_get_device_attr(dev, "sustain")))
		return -1;

    strncpy(pcmidi_sysfs_mount, dev->path, SYSFS_PATH_MAX);

	return 0;
}

/* returns 0 if successful, !0 otherwise */
int pcmidi_read_sysfs_hid_bus(void)
{
	struct sysfs_bus *bus;
	struct dlist *devs;
	struct sysfs_device *dev;
	int ret = 0;

	if (!(bus = sysfs_open_bus("hid"))) {
		if (errno && errno != ENOENT)
			ret = -1;
		goto exit0;
	}

	if (!(devs = sysfs_get_bus_devices(bus))) {
		if (errno && errno != ENOENT)
			ret = -1;
		goto exit1;
	}

	dlist_for_each_data(devs, dev, struct sysfs_device)
		if (!(ret = pcmidi_read_one_sysfs_device(dev)))
			break;

exit1:
	/* this frees bus and devs */
	sysfs_close_bus(bus);

exit0:
	return ret;
}

int pcmidi_read_channel(void)
{
	struct sysfs_attribute* attr;
	char buf[SYSFS_PATH_MAX];
	int channel = 0;

    memset(buf, 0, SYSFS_PATH_MAX);
	sprintf( buf, "%s/channel", pcmidi_sysfs_mount);

    if (!(attr = sysfs_open_attribute( buf )))
        return channel;

    if (!sysfs_read_attribute(attr))
    {
        channel = atoi(attr->value);
    }
    sysfs_close_attribute(attr);

    return channel;
}

void pcmidi_write_channel(int channel)
{
	struct sysfs_attribute* attr;
	char buf[SYSFS_PATH_MAX];

    memset(buf, 0, SYSFS_PATH_MAX);
	sprintf( buf, "%s/channel", pcmidi_sysfs_mount);

    if (!(attr = sysfs_open_attribute( buf )))
        return;

    memset(buf, 0, SYSFS_PATH_MAX);
    sprintf( buf, "%d", channel );
    sysfs_write_attribute(attr, buf, strlen(buf));

    sysfs_close_attribute(attr);
}

int pcmidi_read_octave(void)
{
	struct sysfs_attribute* attr;
	char buf[SYSFS_PATH_MAX];
	int octave = 0;

    memset(buf, 0, SYSFS_PATH_MAX);
	sprintf( buf, "%s/octave", pcmidi_sysfs_mount);

    if (!(attr = sysfs_open_attribute( buf )))
        return octave;

    if (!sysfs_read_attribute(attr))
    {
        octave = atoi(attr->value);
    }
    sysfs_close_attribute(attr);

    return octave;
}

void pcmidi_write_octave(int octave)
{
	struct sysfs_attribute* attr;
	char buf[SYSFS_PATH_MAX];

    memset(buf, 0, SYSFS_PATH_MAX);
	sprintf( buf, "%s/octave", pcmidi_sysfs_mount);

    if (!(attr = sysfs_open_attribute( buf )))
        return;

    memset(buf, 0, SYSFS_PATH_MAX);
    sprintf( buf, "%d", octave );
    sysfs_write_attribute(attr, buf, strlen(buf));

    sysfs_close_attribute(attr);
}

int pcmidi_read_sustain(void)
{
	struct sysfs_attribute* attr;
	char buf[SYSFS_PATH_MAX];
	int sustain = 0;

    memset(buf, 0, SYSFS_PATH_MAX);
	sprintf( buf, "%s/sustain", pcmidi_sysfs_mount);

    if (!(attr = sysfs_open_attribute( buf )))
        return sustain;

    if (!sysfs_read_attribute(attr))
    {
        sustain = atoi(attr->value);
    }
    sysfs_close_attribute(attr);

    return sustain;
}

void pcmidi_write_sustain(int sustain)
{
	struct sysfs_attribute* attr;
	char buf[SYSFS_PATH_MAX];

    memset(buf, 0, SYSFS_PATH_MAX);
	sprintf( buf, "%s/sustain", pcmidi_sysfs_mount);

    if (!(attr = sysfs_open_attribute( buf )))
        return;

    memset(buf, 0, SYSFS_PATH_MAX);
    sprintf( buf, "%d", sustain );
    sysfs_write_attribute(attr, buf, strlen(buf));

    sysfs_close_attribute(attr);
}
