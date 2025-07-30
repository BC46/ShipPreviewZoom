# Ship Preview Zoom
Plugin for the game Freelancer (2003) that allows players to zoom in the ship preview window by scrolling with the mouse wheel.

## Motivation
In the game Freelancer there is a ship dealer menu where you can preview and purchase ships. In this preview menu, you can view the ship from different angles by dragging the mouse while holding Mouse 1. Intuitively, I expected that you could also zoom in/out by scrolling the mouse wheel such that you could see the ship from up close of further away. Sadly, this was never implemented by the original developers.

All the way back in 2022 I really wanted to go about implementing the "missing" ship preview zooming feature myself. However, this required knowledge of reverse engineering games and low-level programming, which I didn't have any of. Eventually in September that year, I set up some boilerplate code for a Freelancer plugin with the little knowledge I had at the time. For some reason I decided to implement it in C, presumably because I thought that was cool. There had been older discussions on The Starport about ship dealer preview window patches, which gave me some insights regarding where the zoom level could be edited. With some struggling I was able to get a basic plugin working that just applied a simple in-memory patch that set the initial ship preview zoom level to a hard-coded value. It was great knowing that I had finally created my first ever Freelancer plugin, but I was still far from reaching my goal.

To make the plugin complete, I had to actually be able to dynamically adjust the zoom level while scrolling with the mouse wheel. I assumed I would have had to somehow hook the user's key inputs and then scan the memory to figure out where the zoom level is stored. Back in 2022 implementing something like this with virtually no reverse engineering knowledge sounded almost impossible. I thought to myself, maybe in the future I'll learn more about reverse engineering and I can get some more insights into how I can finally implement this. With this in mind, I put the project on hold.

Fast-forward to April 2024 at which point I had gained a lot more reverse engineering and general programming experience. I had really learned a lot in those two years because I had experimented with finding patches for Freelancer and developing more plugins. It did not quite cross my mind to get back to Ship Preview Zoom because the amount of work I thought I had to do to get everything working did not sound like it would be worth the effort. That whole idea changed however when I looked at the source code of several plugins that adoxa made, one of which was [Wheel Scroll](http://adoxa.altervista.org/freelancer/plugins.html#wheelscroll). This plugin allows players to scroll through the Freelancer menus with the mouse wheel. Looking at the source code it appeared that adoxa found a missing piece to my puzzle; every single window in Freelancer seems to have a virtual function table with a scroll function. Every time the user would scroll with the mouse wheel while hovering over that window, this vftable function would be called and as a parameter it tells you in which direction the user scrolled.

I thought to myself: "Surely, the ship preview window doesn't have an accessible function like the windows that adoxa looked at, right?". I immediately fired up my debugger and looked at the vftable of the ship preview window in-memory. After finding it, I calculated the offset of the scroll function and put a hardware breakpoint on it. Sure enough, when I moved my scroll wheel just one tick while hovering over the preview window, my breakpoint immediately hit. From there it was not complicated at all to finish the Ship Preview Zoom plugin. All I had to do was hook this function, locate the offset of the zoom level and just modify the value. After about an hour, I had found that exact offset and was able to implement the entire feature. I added it to [flplusplus](https://github.com/TheStarport/flplusplus), a client-side plugin made by Callum which I had already contributed to. The reason why I did not implement it separately was because I wanted the zoom settings to be configurable (zoom speed and inverting the direction) and flplusplus already had a whole config file with code for reading it. I was very thrilled that I finally got the feature working.

With the zooming feature implemented in flplusplus, there was still the Ship Preview Zoom project that was starting to collect dust in my GitHub account. I am someone who prefers to always finish projects after I've started them. That meant I also had to finish the Ship Preview Zoom project. I had already written the code before in flplusplus, so in principle I could have just copied it over. One small issue was that I had implemented the zooming feature in flplusplus in C++, whereas I originally started the Ship Preview Zoom project in C. Converting this C++ code to C was not feasible because the original code used C++-specific concepts like __thiscall hooks and calling Common.dll's INI_Reader __thiscall functions which were exported without extern "C". Normally you cannot call __thiscall functions like this in C. Since I did not really want to switch programming languages, I decided to just carry on in C while finding workarounds for the aforementioned issues. In July 2025, I did exactly that; I created shims to convert the calling convention from __thiscall to __stdcall and vice versa. This allowed me to hook __thiscall functions and also call Freelancer's __thiscall functions, all from my C code. Moreover, I worked around the __thiscall export symbols by just grabbing the INI_Reader function addresses from Freelancer.exe's import table. Thanks to these creative workarounds, I finally completed Ship Preview Zoom, exactly the way I originally intended.

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

