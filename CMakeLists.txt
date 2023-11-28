cmake_minimum_required(VERSION 3.15)

project(efi-boilerplate)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(gnu-efi/inc)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".efi")

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Zc:wchar_t- /GS- /EHs- /Gm- /EHsc- /EHa- /GR- /DWIN32- /D_WINDOWS-")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:wchar_t- /GS- /EHs- /Gm- /EHsc- /EHa- /GR- /DWIN32- /D_WINDOWS-")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /nodefaultlib /entry:EfiMain /subsystem:efi_application /nxcompat:no /manifestuac:no /manifest:no /dynamicbase:no")
else()
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fuse-ld=lld-link -target x86_64-unknown-windows -mno-red-zone -short-wchar -fno-stack-protector -fno-exceptions -fno-rtti -DWIN32 -D_WINDOWS")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=lld-link -target x86_64-unknown-windows -mno-red-zone -fshort-wchar -fno-stack-protector -fno-exceptions -fno-rtti -DWIN32 -D_WINDOWS")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld-link -nostdlib -Wl,-subsystem:efi_application -Wl,-entry:EfiMain")
endif()