set(LGVL_COMPONENT_DIRS  ${LVGL_COMPONENT_DIRS}
                $ENV{HOME}/esp32-externals/lvgl-gui/components
                $ENV{HOME}/esp32-externals/lvgl-gui/components/lvgl)

set(EXTRA_COMPONENT_DIRS "${EXTRA_COMPONENT_DIRS} ${LVGL_COMPONENT_DIRS}")

#message(STATUS "??????? EXTRA COMPONENT DIRECTORIES = ${EXTRA_COMPONENT_DIRS}")

