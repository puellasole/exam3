cmake_minimum_required(VERSION 3.22) # Проверка версии CMake.
									 # Если версия установленой программы									 # старее указанной, произойдёт аварийный выход.

set(PROJECT_NAME exam3)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 20)			 # устанавливаем 20 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("include/")	# добавляем директории
include_directories("src/")
link_directories("lib/")


add_executable("${PROJECT_NAME}" src/main.cpp
		src/game_logic.h
		src/game_logic.cpp)

target_link_libraries("${PROJECT_NAME}" 
					    debug sfml-graphics-s-d
						debug sfml-window-s-d
						debug sfml-system-s-d
						debug sfml-audio-s-d
						debug sfml-network-s-d)
						
target_link_libraries("${PROJECT_NAME}" 
						optimized sfml-graphics-s 
						optimized sfml-window-s 
						optimized sfml-system-s 
						optimized sfml-audio-s 
						optimized sfml-network-s)

target_link_libraries("${PROJECT_NAME}" opengl32 freetype winmm gdi32 openal32 flac vorbisenc vorbisfile vorbis ogg)
