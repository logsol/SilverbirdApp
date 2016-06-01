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

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=0.1.0" -D "JUCE_APP_VERSION_HEX=0x100" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 

  TARGET := SilverbirdApp
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

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=0.1.0" -D "JUCE_APP_VERSION_HEX=0x100" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../../JUCE/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -Os
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -fvisibility=hidden -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 

  TARGET := SilverbirdApp
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/Main_90ebc5c2.o \
  $(OBJDIR)/FxBus_d47be4af.o \
  $(OBJDIR)/Parameter_73564c8a.o \
  $(OBJDIR)/Controller_2961cb25.o \
  $(OBJDIR)/Processor_85e48f3.o \
  $(OBJDIR)/ADSR_8d33c52b.o \
  $(OBJDIR)/Voice_616ec393.o \
  $(OBJDIR)/Mixer_d95e2aea.o \
  $(OBJDIR)/Sampler_e764c69.o \
  $(OBJDIR)/Source_e71e0224.o \
  $(OBJDIR)/Sound_322374f0.o \
  $(OBJDIR)/ModulationSequencer_248b5296.o \
  $(OBJDIR)/MidiSequencer_f941fa11.o \
  $(OBJDIR)/Sequencer_5ffb45b2.o \
  $(OBJDIR)/ClockListener_63c33543.o \
  $(OBJDIR)/Clock_6670f06f.o \
  $(OBJDIR)/VPNavigate_2aee4634.o \
  $(OBJDIR)/VPSetup_d106e2e4.o \
  $(OBJDIR)/VPSequencer_236c7638.o \
  $(OBJDIR)/VPMixer_af588e70.o \
  $(OBJDIR)/Portrait_7455b0a4.o \
  $(OBJDIR)/SizeTest_b89d993c.o \
  $(OBJDIR)/SlideView_36605657.o \
  $(OBJDIR)/DelayComponent_eaeca543.o \
  $(OBJDIR)/ReverbComponent_e2d4862c.o \
  $(OBJDIR)/MixerComponent_e3e89c7d.o \
  $(OBJDIR)/MixerStrip_442d5a98.o \
  $(OBJDIR)/Mods_6d413dba.o \
  $(OBJDIR)/Drums_b8e3026e.o \
  $(OBJDIR)/TargetStepper_98987761.o \
  $(OBJDIR)/Stepper_615f26b2.o \
  $(OBJDIR)/BipolarStepper_94527603.o \
  $(OBJDIR)/SbButton_890e0c6a.o \
  $(OBJDIR)/Knob_7a6e67ff.o \
  $(OBJDIR)/BpmSlider_53f58501.o \
  $(OBJDIR)/BaseComponent_c1793a8d.o \
  $(OBJDIR)/Transport_32ccd00a.o \
  $(OBJDIR)/TrackParameters_a021bf76.o \
  $(OBJDIR)/HistoryComponent_4b30d8d2.o \
  $(OBJDIR)/CustomLook_94c1e339.o \
  $(OBJDIR)/Ui_5a974e1d.o \
  $(OBJDIR)/Gui_2b5c821c.o \
  $(OBJDIR)/Gui2_4053d760.o \
  $(OBJDIR)/BinaryData_ce4232d4.o \
  $(OBJDIR)/BinaryData2_fa243da8.o \
  $(OBJDIR)/BinaryData3_fa325529.o \
  $(OBJDIR)/BinaryData4_fa406caa.o \
  $(OBJDIR)/BinaryData5_fa4e842b.o \
  $(OBJDIR)/BinaryData6_fa5c9bac.o \
  $(OBJDIR)/juce_audio_basics_181b4cb.o \
  $(OBJDIR)/juce_audio_devices_2d9302c9.o \
  $(OBJDIR)/juce_audio_formats_5c144c69.o \
  $(OBJDIR)/juce_audio_processors_a9c69383.o \
  $(OBJDIR)/juce_audio_utils_f6fe6709.o \
  $(OBJDIR)/juce_core_9d6b33ad.o \
  $(OBJDIR)/juce_data_structures_dcd877a9.o \
  $(OBJDIR)/juce_events_e5b201a1.o \
  $(OBJDIR)/juce_graphics_a34b2885.o \
  $(OBJDIR)/juce_gui_basics_3e4cc581.o \
  $(OBJDIR)/juce_gui_extra_20746349.o \
  $(OBJDIR)/juce_opengl_a5fa29cd.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(RESOURCES)
	@echo Linking SilverbirdApp
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning SilverbirdApp
	@$(CLEANCMD)

strip:
	@echo Stripping SilverbirdApp
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/FxBus_d47be4af.o: ../../Source/FxBus.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling FxBus.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Parameter_73564c8a.o: ../../Source/Parameter.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Parameter.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Controller_2961cb25.o: ../../Source/Controller.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Controller.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Processor_85e48f3.o: ../../Source/Processor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Processor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ADSR_8d33c52b.o: ../../Source/ADSR.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ADSR.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Voice_616ec393.o: ../../Source/Voice.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Voice.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Mixer_d95e2aea.o: ../../Source/Mixer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Mixer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Sampler_e764c69.o: ../../Source/Sampler.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Sampler.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Source_e71e0224.o: ../../Source/Source.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Source.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Sound_322374f0.o: ../../Source/Sound.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Sound.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ModulationSequencer_248b5296.o: ../../Source/ModulationSequencer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ModulationSequencer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiSequencer_f941fa11.o: ../../Source/MidiSequencer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiSequencer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Sequencer_5ffb45b2.o: ../../Source/Sequencer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Sequencer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ClockListener_63c33543.o: ../../Source/ClockListener.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ClockListener.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Clock_6670f06f.o: ../../Source/Clock.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Clock.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/VPNavigate_2aee4634.o: ../../Source/VPNavigate.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling VPNavigate.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/VPSetup_d106e2e4.o: ../../Source/VPSetup.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling VPSetup.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/VPSequencer_236c7638.o: ../../Source/VPSequencer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling VPSequencer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/VPMixer_af588e70.o: ../../Source/VPMixer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling VPMixer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Portrait_7455b0a4.o: ../../Source/Portrait.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Portrait.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SizeTest_b89d993c.o: ../../Source/SizeTest.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SizeTest.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SlideView_36605657.o: ../../Source/SlideView.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SlideView.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/DelayComponent_eaeca543.o: ../../Source/DelayComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling DelayComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ReverbComponent_e2d4862c.o: ../../Source/ReverbComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ReverbComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MixerComponent_e3e89c7d.o: ../../Source/MixerComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MixerComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MixerStrip_442d5a98.o: ../../Source/MixerStrip.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MixerStrip.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Mods_6d413dba.o: ../../Source/Mods.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Mods.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Drums_b8e3026e.o: ../../Source/Drums.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Drums.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TargetStepper_98987761.o: ../../Source/TargetStepper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TargetStepper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Stepper_615f26b2.o: ../../Source/Stepper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Stepper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BipolarStepper_94527603.o: ../../Source/BipolarStepper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BipolarStepper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SbButton_890e0c6a.o: ../../Source/SbButton.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SbButton.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Knob_7a6e67ff.o: ../../Source/Knob.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Knob.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BpmSlider_53f58501.o: ../../Source/BpmSlider.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BpmSlider.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BaseComponent_c1793a8d.o: ../../Source/BaseComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BaseComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Transport_32ccd00a.o: ../../Source/Transport.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Transport.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TrackParameters_a021bf76.o: ../../Source/TrackParameters.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TrackParameters.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/HistoryComponent_4b30d8d2.o: ../../Source/HistoryComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling HistoryComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/CustomLook_94c1e339.o: ../../Source/CustomLook.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CustomLook.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Ui_5a974e1d.o: ../../Source/Ui.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Ui.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Gui_2b5c821c.o: ../../Source/Gui.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Gui.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Gui2_4053d760.o: ../../Source/Gui2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Gui2.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData_ce4232d4.o: ../../JuceLibraryCode/BinaryData.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData2_fa243da8.o: ../../JuceLibraryCode/BinaryData2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData2.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData3_fa325529.o: ../../JuceLibraryCode/BinaryData3.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData3.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData4_fa406caa.o: ../../JuceLibraryCode/BinaryData4.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData4.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData5_fa4e842b.o: ../../JuceLibraryCode/BinaryData5.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData5.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData6_fa5c9bac.o: ../../JuceLibraryCode/BinaryData6.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData6.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_181b4cb.o: ../../../JUCE/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_2d9302c9.o: ../../../JUCE/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_5c144c69.o: ../../../JUCE/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_a9c69383.o: ../../../JUCE/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_utils_f6fe6709.o: ../../../JUCE/modules/juce_audio_utils/juce_audio_utils.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_utils.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_9d6b33ad.o: ../../../JUCE/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_dcd877a9.o: ../../../JUCE/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_e5b201a1.o: ../../../JUCE/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_a34b2885.o: ../../../JUCE/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_3e4cc581.o: ../../../JUCE/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_20746349.o: ../../../JUCE/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_opengl_a5fa29cd.o: ../../../JUCE/modules/juce_opengl/juce_opengl.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
