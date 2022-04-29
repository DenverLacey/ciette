workspace "ciette"
    configurations { "Debug", "Release" }

project "ciette"
    kind 'ConsoleApp'
    language "C++"
    cppdialect "C++17"

    files {
        "lib/*.h",
        "lib/*.cpp",
        "src/*.h",
        "src/*.cpp",
    }

    includedirs { "src", "lib" }

    filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
