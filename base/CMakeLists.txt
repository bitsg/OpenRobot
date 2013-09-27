include_directories(${OpenRobot_SOURCE_DIR})

add_subdirectory(PointData)
add_subdirectory(RW)

FILE(GLOB BASE_HEADERS *.h)

INSTALL(FILES ${BASE_HEADERS}
  DESTINATION ${INSTALL_DIR}/include/OpenRobot/base
)