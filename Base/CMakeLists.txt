include_directories(${OpenRobot_ROOT_DIR})

add_subdirectory(PointData)
add_subdirectory(ReadWrite)

FILE(GLOB BASE_HEADERS *.h)

INSTALL(FILES ${BASE_HEADERS}
  DESTINATION ${INSTALL_DIR}/include/OpenRobot/Base
)