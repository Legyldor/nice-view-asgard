if(CONFIG_ZMK_DISPLAY AND CONFIG_NICE_VIEW_WIDGET_STATUS)
  zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)

  zephyr_library_sources(
    ./src/main.c
    ./src/images/bluetooth_logo_outlined.c
    ./src/images/bluetooth_logo.c
    ./src/images/bluetooth_searching.c
    ./src/images/usb_logo.c
    ./src/utils/draw_battery.c
    ./src/utils/draw_bluetooth_logo_outlined.c
    ./src/utils/draw_bluetooth_logo.c
    ./src/utils/draw_bluetooth_searching.c
    ./src/utils/draw_usb_logo.c
  )

  if(NOT CONFIG_ZMK_SPLIT OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    zephyr_library_sources(
      ./src/central/initialize_listeners.c
      ./src/central/render.c
      # These are not included on the peripheral since they are only used for
      # displaying the layer name.
      ./src/fonts/press_start_2p_8.c
      ./src/fonts/press_start_2p_16.c
      ./src/fonts/press_start_2p_24.c
    )
  else()
    zephyr_library_sources(
#      ./src/images/fire_0.c
#      ./src/images/fire_1.c
#      ./src/images/fire_2.c
#      ./src/images/fire_3.c
#      ./src/images/fire_4.c
#      ./src/images/fire_5.c
#      ./src/images/fire_6.c
#      ./src/images/fire_7.c
#      ./src/images/fire_8.c
#      ./src/images/fire_9.c
      ./src/peripheral/initialize_listeners.c
      ./src/peripheral/render.c
      ./src/utils/draw_fire.c
    )
  endif()
endif()
