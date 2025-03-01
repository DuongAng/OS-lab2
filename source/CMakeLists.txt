cmake_minimum_required(VERSION 3.30)
project(os-lab1)
get_filename_component(MONOLITH_INCLUDE_PATH "." ABSOLUTE)
get_filename_component(MONOLITH_SOURCE_PATH "./${PROJECT_NAME}" ABSOLUTE)

file(GLOB_RECURSE MONOLITH_SOURCES CONFIGURE_DEPENDS *.hpp *.cpp)

set(MONOLITH_LIB_SOURCES ${MONOLITH_SOURCES}
        bench/search-name/FileFinder.cpp
        bench/search-name/FileFinder.h
        bench/search-name/main.cpp
        bench/dedup/main.cpp
        bench/dedup/ArrayDedup.cpp
        bench/dedup/ArrayDedup.h
        monolith/shell/utils/Path.cpp
        monolith/shell/utils/Path.h
        monolith/shell/commands/ChangeDir.cpp
        monolith/shell/commands/ChangeDir.h
        monolith/shell/Command.cpp
        monolith/shell/Command.h
        monolith/shell/Shell.cpp
        monolith/shell/Shell.h
        monolith/shell/commands/Exit.cpp
        monolith/shell/commands/Exit.h
        monolith/shell/commands/Help.cpp
        monolith/shell/commands/Help.h
        monolith/shell/commands/History.h
        monolith/shell/commands/History.cpp
        monolith/shell/commands/ListFiles.h
        monolith/shell/commands/ListFiles.cpp
        monolith/shell/commands/PathToWorkingDir.h
        monolith/shell/commands/PathToWorkingDir.cpp
        monolith/shell/commands/Run.cpp
        monolith/shell/commands/Run.h
        monolith/shell/factory/CommandFactory.cpp
        monolith/shell/factory/CommandFactory.h
        bench/sort/Sort.h
        bench/sort/Sort.cpp
        bench/sort/main.cpp
        bench/measure-throughput/ThroughputTester.h
        bench/measure-throughput/ThroughputTester.cpp
        bench/measure-throughput/main.cpp
        include/lab2.h
        include/cache.h
        src/lab2.cpp
        src/cache.cpp
        src/main.cpp
        test/test_lab2.cpp
)

set(MONOLITH_APP_SOURCES monolith/app/Main.cpp)

# Đảm bảo `include/` được thêm vào `include directories`
include_directories(include)

# Tạo thư viện lab2 từ source
add_library(lab2 SHARED src/lab2.cpp src/cache.cpp)
target_include_directories(lab2 PUBLIC include)

# 🔥 Đổi tên file thực thi từ "test" thành "main"
add_executable(lab2_run src/main.cpp)
target_link_libraries(lab2_run lab2)

# Tạo file kiểm thử (test_lab2.cpp)
add_executable(test_lab2 test/test_lab2.cpp)
target_link_libraries(test_lab2 lab2)
add_executable(search-name
        bench/search-name/main.cpp
        bench/search-name/FileFinder.cpp
)

add_executable(dedup
        bench/dedup/main.cpp
        bench/dedup/ArrayDedup.cpp
)

add_executable(sort
        bench/sort/main.cpp
        bench/sort/Sort.cpp
)

add_executable(throughput_test
        bench/measure-throughput/main.cpp
        bench/measure-throughput/ThroughputTester.cpp
)

target_compile_options(search-name PRIVATE -O3 -march=native -ffast-math -funroll-loops)

target_compile_options(dedup PRIVATE -O3 -march=native -ffast-math -funroll-loops)

set(MONOLITH_APP_SOURCES monolith/app/Main.cpp)

add_library(${PROJECT_NAME} STATIC ${MONOLITH_LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${MONOLITH_INCLUDE_PATH})

add_executable(${PROJECT_NAME}-app ${MONOLITH_APP_SOURCES})
set_property(TARGET ${PROJECT_NAME}-app PROPERTY OUTPUT_NAME ${PROJECT_NAME})
target_link_libraries(
    ${PROJECT_NAME}-app PRIVATE
    ${PROJECT_NAME}
)

