# Linux driver for the Prodikeys PC-MIDI USB keyboard.

## The PC-MIDI is a combination Qwerty/Multimedia/Musical Keyboard.

Web: http://blog.princefolk.co.uk/2023/04/16/prodikeys-pc-midi-linux-driver/

Sourceforge: https://sourceforge.net/projects/pc-midi-linux/

### Driver features:

- Midi: output channel selectable
- Midi: notes controllable duration
- Midi: Octave shift up/down
- Midi: Driver features controlled via sysfs or pcmidi controller application
- Qwerty: Additional mutlimedia keys

This project contains a kernel driver for the Prodikeys PC-MIDI Qwerty/Musical Keyboard.

It also contains a simple WxWidgets UI Application to allow control of

- Sustain Duration
- Ocatve Shift 
- Midi Output Channel

Patches are supplied for Kernel versions 2.6.29 through 2.6.34.

The 2.6.29 patch may or may not work with previous kernels.

The 2.6.34 may or may not work with future kernels.


