cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME SFMLproject)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TextInputBox/MultiText.cpp TextInputBox/MultiText.h TextInputBox/Letter.cpp TextInputBox/Letter.h Font.cpp Font.h States/States.cpp States/States.h States/StatesEnum.h Interface/Application.cpp Interface/Application.h Interface/GUIComponent.cpp Interface/GUIComponent.h SnapShot/SnapShotInterface.cpp SnapShot/SnapShotInterface.h SnapShot/Snapshot.cpp SnapShot/Snapshot.h Helper/KeyboardShortcut.cpp Helper/KeyboardShortcut.h Helper/MouseEvents.cpp Helper/MouseEvents.h History/History.cpp History/History.h History/HistoryNode.h Helper/Positioning.cpp Helper/Positioning.h "TextInputBox/Cursor.cpp" "TextInputBox/Cursor.h" DropDownMenu/Item.h DropDownMenu/Item.cpp DropDownMenu/ItemList.h DropDownMenu/ItemList.cpp TextInputBox/InputBox.h TextInputBox/InputBox.cpp DropDownMenu/DropDownMenu.h DropDownMenu/DropDownMenu.cpp "Menu Bar/MenuBar.h" "Menu Bar/MenuBar.cpp" "Menu Bar/Menu.h" "Menu Bar/Menu.cpp" FileTree/FileItem.cpp FileTree/FileItem.h FileTree/FileNode.cpp FileTree/FileNode.h FileTree/FileTree.cpp FileTree/FileTree.h Helper/Image.cpp Helper/Image.h Player/AnimatedSprite.h Player/AnimatedSprite.cpp Player/Player.cpp Player/Player.h Player/NameTag.cpp Player/NameTag.h Interface/ScreenType.h MainMenu/MainMenu.h MainMenu/MainMenu.cpp PausingScreen/PausingScreen.h PausingScreen/PausingScreen.cpp Button.h Button.cpp Testing/radpidcsv.h Testing/pugiconfig.hpp Testing/pugixml.hpp Testing/pugixml.cpp Testing/ParsingXML.cpp Testing/ParsingXML.h Testing/SinglePlayer.cpp Testing/SinglePlayer.h Testing/Layer.h Online/Multiplayer.cpp Online/Multiplayer.h Online/Server.cpp Online/Server.h Online/Client.cpp Online/Client.h Option/OptionScreen.cpp Option/OptionScreen.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system network)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} )
endif ()