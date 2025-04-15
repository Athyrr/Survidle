# all src .cpp 
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)

# exe
#add_executable(${PROJECT_NAME} main.cpp) # ${PROJECT_NAME} = Survidle
add_executable(${PROJECT_NAME} ${SOURCES}) # ${PROJECT_NAME} = Survidle

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
target_link_libraries(${PROJECT_NAME} 
    PRIVATE
    SFML::System
    SFML::Window
    SFML::Graphics 
)
