{
  "targets": [
    {
      "target_name": "gearbox_objc",
      "type": "shared_library",
      "dependencies": [
        "./deps/djinni/support-lib/support_lib.gyp:djinni_objc",
        "./deps/sqlite3/sqlite3.gyp:sqlite3",
        "./deps/curl/libcurl.gyp:libcurl",
        "./deps/zf_log/liblog.gyp:liblog",
        "./deps/libuv/libuv.gyp:libuv",
      ],
      "sources": [
        "<!@(python deps/djinni/example/glob.py generated-src/objc  '*.cpp' '*.h' '*.mm' '*.m')",
        "<!@(python deps/djinni/example/glob.py generated-src/cpp   '*.cpp' '*.hpp' '*.h')",
        "<!@(python deps/djinni/example/glob.py src '*.cpp' '*.hpp' '*.h')",
      ],
      "include_dirs": [
        "generated-src/objc",
        "generated-src/cpp",
        "src",
        "interface",
      ]
    },
    {
      "target_name": "gearbox_jni",
      "type": "shared_library",
      "dependencies": [
        "./deps/djinni/support-lib/support_lib.gyp:djinni_jni",
        "./deps/sqlite3.gyp:sqlite3",
        "./deps/curl/libcurl.gyp:libcurl",
        "./deps/zf_log/liblog.gyp:liblog",
        "./deps/libuv/libuv.gyp:libuv",
      ],
      "ldflags" : [ "-llog", "-Wl,--build-id,--gc-sections,--exclude-libs,ALL" ],
      "sources": [
        "./deps/djinni/support-lib/jni/djinni_main.cpp",
        "<!@(python deps/djinni/example/glob.py generated-src/jni   '*.cpp')",
        "<!@(python deps/djinni/example/glob.py generated-src/cpp   '*.cpp')",
        "<!@(python deps/djinni/example/glob.py src '*.cpp')",
      ],
      "include_dirs": [
        "generated-src/jni",
        "generated-src/cpp",
        "src",
        "interface",
      ],
    },
  ],
}