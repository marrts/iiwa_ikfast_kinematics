cmake_minimum_required(VERSION 3.5.0)
project(iiwa_ikfast_kinematics)

find_package(catkin REQUIRED)
find_package(tesseract_kinematics REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(console_bridge REQUIRED)
find_package(LAPACK REQUIRED) # Requried for ikfast

catkin_package(
  INCLUDE_DIRS
    include
    ${EIGEN3_INCLUDE_DIRS}
  LIBRARIES
    ${PROJECT_NAME}
    ${PROJECT_NAME}_free7
  DEPENDS
    EIGEN3
    tesseract_kinematics
    console_bridge
    LAPACK
)

###########
## Build ##
###########

add_library(${PROJECT_NAME} src/tesseract_ikfast_iiwa7.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC tesseract::tesseract_kinematics_ikfast console_bridge ${LAPACK_LIBRARIES} ${catkin_LIBRARIES})
target_compile_definitions(${PROJECT_NAME} PUBLIC -DIKFAST_NO_MAIN -DIKFAST_CLIBRARY -DIKFAST_HAS_LIBRARY)
target_compile_options(${PROJECT_NAME} PUBLIC -std=c++14 -Wall -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
    ${catkin_INCLUDE_DIRS}
    ${LAPACK_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS})

add_library(${PROJECT_NAME}_free7 src/tesseract_ikfast_iiwa7_free7.cpp)
target_link_libraries(${PROJECT_NAME}_free7 PUBLIC tesseract::tesseract_kinematics_ikfast console_bridge ${LAPACK_LIBRARIES} ${catkin_LIBRARIES})
target_compile_definitions(${PROJECT_NAME}_free7 PUBLIC -DIKFAST_NO_MAIN -DIKFAST_CLIBRARY -DIKFAST_HAS_LIBRARY)
target_compile_options(${PROJECT_NAME}_free7 PUBLIC -std=c++14 -Wall -Wextra)
target_include_directories(${PROJECT_NAME}_free7 PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME}_free7 SYSTEM PUBLIC
    ${catkin_INCLUDE_DIRS}
    ${LAPACK_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS})

#############
## Install ##
#############

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_free7
 ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
 LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
 RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h*"
  PATTERN ".svn" EXCLUDE
)
