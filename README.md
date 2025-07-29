# Ship Preview Zoom
Plugin for the game Freelancer (2003) that allows players to zoom in the ship preview window by scrolling with the mouse wheel.

## Installation instructions
Download the latest `ShipPreviewZoom.dll` from [Releases](https://github.com/BC46/ShipPreviewZoom/releases). Extract the `dll` to the `EXE` folder of your Freelancer installation.
Next, open the `dacom.ini` file add `ShipPreviewZoom.dll` to the `[Libraries]` section.

Optionally, in the EXE folder you can create a new file called `ShipPreviewZoom.ini` with the following content:
```ini
[Options]
scrolling_speed = 3
min_distance = 0
max_distance = 100
inverse = false
```

These values can be adjusted to your liking.

## Build instructions
Build the project using the `NMAKE` tool from Microsoft Visual C++ 6.0 (VC6 or Visual Studio 98) with the included makefile.
This will output the `ShipPreviewZoom.dll` file in the root project folder.
Building the project using other compilers may require the code to be modified.

