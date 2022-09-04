CFLAGS = /nologo /WX /Gf /O2 /MD

ShipPreviewZoom.dll: ShipPreviewZoom.obj ShipPreviewZoom.res
	cl $(CFLAGS) /LD /Fm $**
