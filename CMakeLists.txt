cmake_minimum_required(VERSION 3.21)
project(AGD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
if(WIN32)
    set(CMAKE_PREFIX_PATH "D:/Qt/6.2.4/mingw_64")
endif()

if(UNIX)
    set(CMAKE_PREFIX_PATH "/home/null/Qt/6.2.4/gcc_64")
endif()




find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(INC_MOC Inc/main.h Inc/game_base.h)
set(CPP_MOC Src/main.cpp Src/game_base.cpp)
qt_wrap_cpp(INC_MOC)
qt_wrap_cpp(CPP_MOC)

set(INC_UI)
qt_wrap_ui(INC_UI)

add_executable(AGD ${CPP_MOC} ${INC_MOC} ${INC_UI})

target_link_libraries(AGD
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if(WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif()
    endif()
    if(EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif()
    foreach(QT_LIB Core )
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach(QT_LIB)
endif()
