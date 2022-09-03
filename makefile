CFLAGS = /nologo /W2 /Gf /Ox /MD

ShipPreviewZoom.dll: ShipPreviewZoom.obj ShipPreviewZoom.res
	cl $(CFLAGS) /LD /Fm $**
