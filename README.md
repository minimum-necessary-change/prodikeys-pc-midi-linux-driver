![pc-midi-linux-button-157x80](https://github.com/minimum-necessary-change/prodikeys-pc-midi-linux-driver/blob/master/res/pc-midi-linux-button-157x80.png)

# Linux driver for the Prodikeys® PC-MIDI USB keyboard.



## The Prodikeys® PC-MIDI is a combination Qwerty/Multimedia/Musical Keyboard.

![Prodikeys® PC-MIDI Keyboard](https://github.com/minimum-necessary-change/prodikeys-pc-midi-linux-driver/blob/master/res/prodikeys-pc-midi.png)

Web: http://blog.princefolk.co.uk/2023/04/16/prodikeys-pc-midi-linux-driver/

Web (OLD): http://prodikeys.princefolk.co.uk/

Sourceforge (OLD): https://sourceforge.net/projects/pc-midi-linux/

## Driver
This project contains a kernel driver for the Prodikeys® PC-MIDI Qwerty/Musical Keyboard.

### Driver features:

- Midi: output channel selectable
- Midi: notes controllable duration
- Midi: Octave shift up/down
- Midi: Driver features controlled via sysfs or pcmidi controller application
- Qwerty: Additional mutlimedia keys

Patches are supplied for Kernel versions 2.6.29 through 2.6.34.

The 2.6.29 patch may or may not work with previous kernels.

The 2.6.34 may or may not work with future kernels.

## UI Application
It also contains a simple WxWidgets UI Application to allow control of

![pcmidi-ui-app.jpg](https://github.com/minimum-necessary-change/prodikeys-pc-midi-linux-driver/blob/master/res/pcmidi-ui-app.jpg)

- Sustain Duration
- Ocatve Shift 
- Midi Output Channel

### UI Application patches

#### PATCH: Fix wxWidgets Unicode Builds
This patch addresses two issues.

1. An issue with building the UI Application against wxWidgets Unicode Builds. (e.g. Ubuntu)
2. An issue with a typo in the Makefile in which, although the application compiles correctly, it cannot be installed due to a malformed path.

Copy the patch to the "pcmidi-controller" directory you previously unpackaged and apply the patch with..

`$ patch -p1 < pcmidi-UI-App-Unicode.patch`

Follow the instructions in the "Kernel driver and UI application" packages to compile and install the UI application.


## Examples
### Qsynth log
![qsynth-log.jpg](https://github.com/minimum-necessary-change/prodikeys-pc-midi-linux-driver/blob/master/res/qsynth-log.jpg)

### Connected to FluidSynth
![pc-midi-connected-to-fluidsynth.jpg](https://github.com/minimum-necessary-change/prodikeys-pc-midi-linux-driver/blob/master/res/pc-midi-connected-to-fluidsynth.jpg)

### amidi Capture
![amidi-capture.jpg](https://github.com/minimum-necessary-change/prodikeys-pc-midi-linux-driver/blob/master/res/amidi-capture.jpg)

### Jack Audio Connection
![jack-audio-connection-kit.jpg](https://github.com/minimum-necessary-change/prodikeys-pc-midi-linux-driver/blob/master/res/jack-audio-connection-kit.jpg)
