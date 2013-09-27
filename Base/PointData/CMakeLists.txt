include_directories(${OpenRobot_ROOT_DIR})

FILE(GLOB SOURCE_POINTDATA *.cpp *.h)

add_library(OR_PointData SHARED ${SOURCE_POINTDATA})

#installing the library files
INSTALL(TARGETS OR_PointData
  RUNTIME DESTINATION ${INSTALL_DIR}/bin
  LIBRARY DESTINATION ${INSTALL_DIR}/lib
  ARCHIVE DESTINATION ${INSTALL_DIR}/lib
)

FILE(GLOB POINTDATA_HEADERS *.h)

#installing the header files
INSTALL(FILES ${POINTDATA_HEADERS}
  DESTINATION ${INSTALL_DIR}/include/OpenRobot/Base/PointData
)