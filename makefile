# VC6 makefile

PLUGIN_NAME = ShipPreviewZoom

C_FLAGS = /c /O2 /nologo /W4 /WX /LD /MD
LD_FLAGS = /DLL /FILEALIGN:512 /NOLOGO /RELEASE

$(PLUGIN_NAME).dll: $(PLUGIN_NAME).obj Common.obj $(PLUGIN_NAME).res makefile
    link $(PLUGIN_NAME).obj Common.obj $(PLUGIN_NAME).res $(LD_FLAGS) /OUT:$(PLUGIN_NAME).dll

$(PLUGIN_NAME).obj: $(PLUGIN_NAME).c Freelancer.h Utils.h makefile
    cl $(C_FLAGS) $(PLUGIN_NAME).c

Common.obj: Common.c Common.h Freelancer.h Utils.h makefile
    cl $(C_FLAGS) Common.c

$(PLUGIN_NAME).res: $(PLUGIN_NAME).rc makefile
    rc /fo $(PLUGIN_NAME).res $(PLUGIN_NAME).rc

clean:
    del *.dll *.obj *.RES *.lib
