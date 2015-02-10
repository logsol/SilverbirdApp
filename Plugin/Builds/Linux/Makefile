# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../../../SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -fPIC -O0
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../../../SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../JUCE/modules
  TARGET := Silverbird.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../../../SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -fPIC -Os
  CXXFLAGS += $(CFLAGS)
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -fvisibility=hidden -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../../../SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../../../JUCE/modules
  TARGET := Silverbird.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/BinaryData_51699c3.o \
  $(OBJDIR)/BinaryData2_9ddcb499.o \
  $(OBJDIR)/BinaryData3_9deacc1a.o \
  $(OBJDIR)/BinaryData4_9df8e39b.o \
  $(OBJDIR)/ADSR_dcf23e1c.o \
  $(OBJDIR)/BipolarStepper_2da735b4.o \
  $(OBJDIR)/Clock_e81959e.o \
  $(OBJDIR)/ClockListener_4fef3b72.o \
  $(OBJDIR)/Controller_eb240b56.o \
  $(OBJDIR)/Drums_60f3a79d.o \
  $(OBJDIR)/Gui_fc62a70b.o \
  $(OBJDIR)/Knob_ca2ce0f0.o \
  $(OBJDIR)/Mixer_816ed019.o \
  $(OBJDIR)/Mods_bcffb6ab.o \
  $(OBJDIR)/Sampler_f4f261d8.o \
  $(OBJDIR)/Sequencer_97c7bb61.o \
  $(OBJDIR)/Sound_da341a1f.o \
  $(OBJDIR)/Source_412202d5.o \
  $(OBJDIR)/Stepper_47db3c21.o \
  $(OBJDIR)/TrackParameters_3164f5e5.o \
  $(OBJDIR)/Voice_97f68c2.o \
  $(OBJDIR)/PluginController_90d98238.o \
  $(OBJDIR)/PluginProcessor_a059e380.o \
  $(OBJDIR)/PluginEditor_94d4fb09.o \
  $(OBJDIR)/juce_audio_basics_b230a8bc.o \
  $(OBJDIR)/juce_audio_devices_6e54be7a.o \
  $(OBJDIR)/juce_audio_formats_9cd6081a.o \
  $(OBJDIR)/juce_audio_processors_563f0674.o \
  $(OBJDIR)/juce_core_28ba299e.o \
  $(OBJDIR)/juce_cryptography_b3b5abf8.o \
  $(OBJDIR)/juce_data_structures_2a02f2da.o \
  $(OBJDIR)/juce_events_a3c29712.o \
  $(OBJDIR)/juce_graphics_13419d76.o \
  $(OBJDIR)/juce_gui_basics_332d59f2.o \
  $(OBJDIR)/juce_gui_extra_6ca15ffa.o \
  $(OBJDIR)/juce_opengl_640abf3e.o \
  $(OBJDIR)/juce_PluginUtilities_2dc8cd86.o \
  $(OBJDIR)/juce_video_6ebc1d1a.o \
  $(OBJDIR)/juce_VST_Wrapper_dcd38e8f.o \
  $(OBJDIR)/juce_VST3_Wrapper_ffc4600d.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking Silverbird
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning Silverbird
	@$(CLEANCMD)

strip:
	@echo Stripping Silverbird
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/BinaryData_51699c3.o: ../../../JuceLibraryCode/BinaryData.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData2_9ddcb499.o: ../../../JuceLibraryCode/BinaryData2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData2.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData3_9deacc1a.o: ../../../JuceLibraryCode/BinaryData3.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData3.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData4_9df8e39b.o: ../../../JuceLibraryCode/BinaryData4.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData4.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ADSR_dcf23e1c.o: ../../../Source/ADSR.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ADSR.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BipolarStepper_2da735b4.o: ../../../Source/BipolarStepper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BipolarStepper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Clock_e81959e.o: ../../../Source/Clock.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Clock.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ClockListener_4fef3b72.o: ../../../Source/ClockListener.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ClockListener.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Controller_eb240b56.o: ../../../Source/Controller.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Controller.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Drums_60f3a79d.o: ../../../Source/Drums.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Drums.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Gui_fc62a70b.o: ../../../Source/Gui.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Gui.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Knob_ca2ce0f0.o: ../../../Source/Knob.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Knob.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Mixer_816ed019.o: ../../../Source/Mixer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Mixer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Mods_bcffb6ab.o: ../../../Source/Mods.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Mods.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Sampler_f4f261d8.o: ../../../Source/Sampler.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Sampler.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Sequencer_97c7bb61.o: ../../../Source/Sequencer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Sequencer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Sound_da341a1f.o: ../../../Source/Sound.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Sound.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Source_412202d5.o: ../../../Source/Source.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Source.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Stepper_47db3c21.o: ../../../Source/Stepper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Stepper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TrackParameters_3164f5e5.o: ../../../Source/TrackParameters.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TrackParameters.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Voice_97f68c2.o: ../../../Source/Voice.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Voice.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginController_90d98238.o: ../../Source/PluginController.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginController.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_b230a8bc.o: ../../../../JUCE/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_6e54be7a.o: ../../../../JUCE/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_9cd6081a.o: ../../../../JUCE/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_563f0674.o: ../../../../JUCE/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_28ba299e.o: ../../../../JUCE/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_cryptography_b3b5abf8.o: ../../../../JUCE/modules/juce_cryptography/juce_cryptography.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_2a02f2da.o: ../../../../JUCE/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_a3c29712.o: ../../../../JUCE/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_13419d76.o: ../../../../JUCE/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_332d59f2.o: ../../../../JUCE/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_6ca15ffa.o: ../../../../JUCE/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_opengl_640abf3e.o: ../../../../JUCE/modules/juce_opengl/juce_opengl.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_PluginUtilities_2dc8cd86.o: ../../../../JUCE/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_PluginUtilities.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_video_6ebc1d1a.o: ../../../../JUCE/modules/juce_video/juce_video.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_video.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST_Wrapper_dcd38e8f.o: ../../../../JUCE/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST3_Wrapper_ffc4600d.o: ../../../../JUCE/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST3_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
