cmake_minimum_required(VERSION 3.5)
project(TestSokol LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Заголовочные файлы
set(HEADER_FILES
    Source/APC_VecMat3D.h
    Source/APC_Cheb.h
    Source/APC_Const.h
    Source/APC_DE.h
    Source/APC_IO.h
    Source/APC_Kepler.h
    Source/APC_Math.h
    Source/APC_Moon.h
    Source/APC_Phys.h
    Source/APC_Planets.h
    Source/APC_PrecNut.h
    Source/APC_Spheric.h
    Source/APC_Sun.h
    Source/APC_Time.h
    Source/GNU_iomanip.h
)

# Исходные файлы
set(SOURCE_FILES  
    Source/APC_VecMat3D.cpp
    Source/APC_Cheb.cpp
    Source/APC_DE.cpp
    Source/APC_IO.cpp
    Source/APC_Kepler.cpp
    Source/APC_Math.cpp
    Source/APC_Moon.cpp
    Source/APC_Phys.cpp
    Source/APC_Planets.cpp
    Source/APC_PrecNut.cpp
    Source/APC_Spheric.cpp
    Source/APC_Sun.cpp
    Source/APC_Time.cpp
    # Source/Coco.cpp
    # Source/Comet.cpp
    # Source/Eclipse.cpp
    # Source/EclTimer.cpp
    # Source/Foto.cpp
    # Source/Gauss.cpp
    # Source/Luna.cpp
    # Source/Numint.cpp
    # Source/Occult.cpp
    # Source/Phases.cpp
    # Source/Phys.cpp

    # Source/Planpos.cpp
    Source/AZ.cpp
    
    # Source/Planrise.cpp
    # Source/PPMbin.cpp
    # Source/PPMcat.cpp
    # Source/Sunset.cpp
    # Source/AOEcat.cpp
)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} )

# Устанавливаем выходной каталог (опционально)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# install(TARGETS ${PROJECT_NAME} DESTINATION bin)
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})