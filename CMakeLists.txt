cmake_minimum_required(VERSION 3.16)
project(TestSokol VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим Qt6
find_package(REQUIRED COMPONENTS)

# Добавляем исполняемый файл
add_executable(${PROJECT_NAME}
    # Source/AOEcat.cpp
    # Source/APC_Cheb.cpp
    # Source/APC_Cheb.h
    # Source/APC_Const.h
    # Source/APC_DE.cpp
    # Source/APC_DE.h
    # Source/APC_IO.cpp
    # Source/APC_IO.h
    # Source/APC_Kepler.cpp
    # Source/APC_Kepler.h
    # Source/APC_Math.cpp
    # Source/APC_Math.h
    # Source/APC_Moon.cpp
    # Source/APC_Moon.h
    # Source/APC_Phys.cpp
    # Source/APC_Phys.h
    # Source/APC_Planets.cpp
    # Source/APC_Planets.h
    # Source/APC_PrecNut.cpp
    # Source/APC_PrecNut.h
    # Source/APC_Spheric.cpp
    # Source/APC_Spheric.h
    # Source/APC_Sun.cpp
    # Source/APC_Sun.h
    # Source/APC_Time.cpp
    # Source/APC_Time.h
    # Source/APC_VecMat3D.cpp
    # Source/APC_VecMat3D.h
    Source/Coco.cpp
    Source/Comet.cpp
    Source/Eclipse.cpp
    Source/EclTimer.cpp
    Source/Foto.cpp
    Source/Gauss.cpp
    Source/GNU_iomanip.h
    Source/Luna.cpp
    Source/Numint.cpp
    Source/Occult.cpp
    Source/Phases.cpp
    Source/Phys.cpp
    Source/Planpos.cpp
    Source/Planrise.cpp
    Source/PPMbin.cpp
    Source/PPMcat.cpp
    Source/Sunset.cpp
)

# Подключаем Qt и OpenGL
# target_link_libraries(${PROJECT_NAME}
#     Qt6::Widgets
#     Qt6::OpenGLWidgets
#     OpenGL::GL
#     # m
# )