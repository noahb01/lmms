INCLUDE(BuildPlugin)

BUILD_PLUGIN(filtereddelay FilteredDelay.cpp FilteredDelayControls.cpp FilteredDelayControlDialog.cpp MOCFILES FilteredDelayControls.h FilteredDelayControlDialog.h EMBEDDED_RESOURCES artwork.png logo.png)
