

CXX=g++
CPPFLAGS= -Wall -O2
LDFLAGS= -shared



# FOLDERS

INCLUDE= include

SRC= src
UTILITIES=$(SRC)/utilities
GTKMM=$(SRC)/gtkmm
UI=$(SRC)/UI
ENCODINGS=$(SRC)/encodings

OUTPUT=build
OBJECTS=$(OUTPUT)/obj
OBJECTS_GTKMM=$(OUTPUT)/objgtkmm




ifeq ($(PREFIX),)
    PREFIX := /usr
endif



#VERSION
VERSION= 3
VERSION_GTKMM_3=3.0
VERSION_GTKMM_2=2.4


ifneq ("$(wildcard $(OUTPUT)/version)","")
$(eval VERSION=$(shell cat $(OUTPUT)/version));
endif


ifeq ($(VERSION),3)
VERSION_GTKMM=$(VERSION_GTKMM_3)
TARGET=$(OUTPUT)/libgtkqrmm3.so
PKG_CONFIG_FILE=gtkqrmm-3.0.pc
TARGET_LIB=lgtkqrmm3
else ifeq ($(VERSION),2)
VERSION_GTKMM=$(VERSION_GTKMM_2)
TARGET=$(OUTPUT)/libgtkqrmm2.so
PKG_CONFIG_FILE=gtkqrmm-2.0.pc
TARGET_LIB=lgtkqrmm2
else	
$(error ERROR: Invalid version,only VERSION=2 or VERSION=3)
endif


PKG_CONFIG_INCLUDE=`pkg-config gtkmm-$(VERSION_GTKMM) --cflags`
PKG_CONFIG_LIBS=`pkg-config gtkmm-$(VERSION_GTKMM) --libs`
TARGET_NON_GUI=$(OUTPUT)/libqrmmutils.so
TARGET_NON_GUI_LIB=lqrmmutils
PKG_CONFIG_FILE_NO_UI=qrmmutils.pc


SRCS    := $(wildcard $(UTILITIES)/*.cpp)
OBJS    := $(patsubst $(UTILITIES)/%.cpp,$(OBJECTS)/%.o,$(SRCS))
SRCS    := $(wildcard $(UI)/*.cpp)
OBJS2    := $(patsubst $(UI)/%.cpp,$(OBJECTS)/%.o,$(SRCS))
SRCS    := $(wildcard $(ENCODINGS)/*.cpp)
OBJS3    := $(patsubst $(ENCODINGS)/%.cpp,$(OBJECTS)/%.o,$(SRCS))


#FUNCTIONS
define create_folder
	@if [ ! -d $(1) ]; then mkdir $(1); fi
	@if [ ! -d $(2) ]; then mkdir $(2); fi
	@if [ ! -d $(3) ]; then mkdir $(3); fi
endef


define create_pkg_file	
	@echo "prefix=" $(2)  >> $(1);
	@echo "exec_prefix=${2}" >> $(1);
        @echo "libdir=${2}/lib" >> $(1);
	@echo "includedir=${2}/include/gtkQRmm\n" >> $(1);
	@echo "Name: gtkqrmm" >> $(1);
	@echo "Description: QR widget for gtkmm" >> $(1);
	@echo "Version: 1.0.0\n" >> $(1);
	@echo "Requires:" >> $(1);
        @echo "Libs: -L${2}/lib -$(3) -$(4)" >> $(1);
        @echo "Cflags: -I${2}/include/gtkQRmm" >> $(1);

endef

define create_pkg_file_non_gui 	
	@echo "prefix=" $(2)  >> $(1);
	@echo "exec_prefix=${2}" >> $(1);
        @echo "libdir=${2}/lib" >> $(1);
	@echo "includedir=${2}/include/gtkQRmm\n" >> $(1);
	@echo "Name: gtkqrmm" >> $(1);
	@echo "Description: QR without widget" >> $(1);
	@echo "Version: 1.0.0\n" >> $(1);
	@echo "Requires:" >> $(1);
        @echo "Libs: -L${2}/lib -$(3)" >> $(1);
        @echo "Cflags: -I${2}/include/gtkQRmm" >> $(1);

endef


all: $(TARGET)
	
$(TARGET): $(TARGET_NON_GUI) $(OBJECTS_GTKMM)/drawData.o $(OBJECTS_GTKMM)/gtkQRmm.o
	$(CXX) $(LDFLAGS) $(OBJECTS_GTKMM)/drawData.o $(OBJECTS_GTKMM)/gtkQRmm.o -L$(OUTPUT) -$(TARGET_NON_GUI_LIB)  -o $@
	@if [ ! -f $(OUTPUT)/version ]; then echo $(VERSION)  >> $(OUTPUT)/version; fi  
	
$(OBJECTS_GTKMM)/%.o:$(wildcard $(GTKMM)/*.cpp)
	$(call create_folder,$(OUTPUT),$(OBJECTS),$(OBJECTS_GTKMM))
	$(CXX) $(CPPFLAGS) -fPIC -I$(INCLUDE) $(PKG_CONFIG_INCLUDE) -c $(patsubst $(OBJECTS_GTKMM)/%.o,$(GTKMM)/%.cpp,$@) -o $@	
	
	
$(TARGET_NON_GUI): $(OBJS) $(OBJS2) $(OBJS3)	
	$(CXX) $(LDFLAGS) $(PKG_CONFIG_LIBS) $(wildcard $(OBJECTS)/*.o)  -o $@
	

$(OBJS):$(wildcard $(UTILITIES)/*.cpp)
	$(call create_folder,$(OUTPUT),$(OBJECTS),$(OBJECTS_GTKMM))
	$(CXX) $(CPPFLAGS) -fPIC -I$(INCLUDE)  -c $(patsubst $(OBJECTS)/%.o,$(UTILITIES)/%.cpp,$@) -o $@ 
	
$(OBJS2):$(wildcard $(UI)/*.cpp) 
	$(call create_folder,$(OUTPUT),$(OBJECTS),$(OBJECTS_GTKMM))
	$(CXX) $(CPPFLAGS) -fPIC  -I$(INCLUDE)  -c $(patsubst $(OBJECTS)/%.o,$(UI)/%.cpp,$@) -o $@ 

$(OBJS3):$(wildcard $(ENCODINGS)/*.cpp)
	$(call create_folder,$(OUTPUT),$(OBJECTS),$(OBJECTS_GTKMM))
	$(CXX) $(CPPFLAGS) -fPIC -I$(INCLUDE)  -c $(patsubst $(OBJECTS)/%.o,$(ENCODINGS)/%.cpp,$@) -o $@ 

	
.PHONY: doxygen

doxygen:
	@echo Generate Doxygen documentation
	@if [ ! -d DOC ]; then mkdir DOC; fi
	doxygen Doxyfile	
	@echo '<meta http-equiv="REFRESH" content="0;URL=DOC/html/index.html">'  >> Documentation.html;


	
	
.PHONY: clean

clean :
	@rm -r $(OBJECTS)/*.o
	@rm -r $(OBJECTS_GTKMM)/*.o
	@if [ -f $(OUTPUT)/version ]; then rm  $(OUTPUT)/version; fi
	

	
.PHONY: install	
	
install: $(TARGET) $(TARGET_NON_GUI)
	
	@if [ -f $(PKG_CONFIG_FILE) ]; then rm  $(PKG_CONFIG_FILE); fi
	@if [ -f $(PKG_CONFIG_FILE_NO_UI) ]; then rm  $(PKG_CONFIG_FILE_NO_UI); fi
	install -d $(DESTDIR)$(PREFIX)/lib/              
	install -m 644 $(TARGET) $(DESTDIR)$(PREFIX)/lib/
	install -m 644 $(TARGET_NON_GUI) $(DESTDIR)$(PREFIX)/lib/
	install -d $(DESTDIR)$(PREFIX)/include/gtkQRmm
	install -m 644 $(INCLUDE)/QrUtils.hpp $(DESTDIR)$(PREFIX)/include/gtkQRmm
	install -m 644 $(INCLUDE)/QrDefinitions.hpp $(DESTDIR)$(PREFIX)/include/gtkQRmm
	install -m 644 $(INCLUDE)/gtkQRmm.hpp $(DESTDIR)$(PREFIX)/include/gtkQRmm
	$(call create_pkg_file,$(PKG_CONFIG_FILE),$(DESTDIR)$(PREFIX),$(TARGET_NON_GUI_LIB),$(TARGET_LIB))    
	$(call create_pkg_file_non_gui,$(PKG_CONFIG_FILE_NO_UI),$(DESTDIR)$(PREFIX),$(TARGET_NON_GUI_LIB))
	$(eval IN=$(shell pkg-config --variable pc_path pkg-config))
	$(eval IN=$(word 1, $(subst :, ,${IN})))
	install -d ${IN} 
	install -m 644 $(PKG_CONFIG_FILE) ${IN}
	install -m 644 $(PKG_CONFIG_FILE_NO_UI) ${IN}
	@if [ -f $(PKG_CONFIG_FILE) ]; then rm  $(PKG_CONFIG_FILE); fi
	@if [ -f $(PKG_CONFIG_FILE_NO_UI) ]; then rm  $(PKG_CONFIG_FILE_NO_UI); fi
	@echo "\n\n"
	@echo "*********************************************************"
	@echo "*                                                       *"
	@echo "*  finished process, use:                               *"
	@echo "*  pkg-config gtkqrmm-$(VERSION).0 --cflags  --libs              *"
	@echo "*  in non UI, use:                                      *"
	@echo "*  pkg-config qrmmutils --cflags  --libs                *"
	@echo "*                                                       *"
	@echo "*********************************************************"
	
