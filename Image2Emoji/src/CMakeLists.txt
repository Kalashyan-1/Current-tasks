cmake_minimum_required(VERSION 3.0)
project(EmojiArt)

find_package(OpenCV REQUIRED)

set(SOURCES 
	main.cpp
	image2Emoji.cpp
	)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
