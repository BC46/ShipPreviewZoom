@echo off

SET name=ShipPreviewZoom

if exist %name%.dll del %name%.dll
if exist %name%.map del %name%.map
if exist %name%.obj del %name%.obj
if exist %name%.RES del %name%.RES
nmake