{
  "targets": [
    {
      "target_name": "gearsbox_objc",
      "type": "shared_library",
      "dependencies": [
        "./deps/djinni/support-lib/support_lib.gyp:djinni_objc",
        "./deps/sqlite3/sqlite3.gyp:sqlite3",
        "./deps/curl/libcurl.gyp:libcurl",
        "./deps/libuv/uv.gyp:libuv",
      ],
      "sources": [
        "<!@(python ./deps/djinni/example/glob.py ./generated-src/objc  '*.cpp' '*.h' '*.mm' '*.m')",
        "<!@(python ./deps/djinni/example/glob.py ./generated-src/cpp   '*.cpp' '*.hpp' '*.h')",
        "<!@(python ./deps/djinni/example/glob.py ./src '*.cpp' '*.hpp' '*.c' '*.h')",
        "<!@(python ./deps/djinni/example/glob.py ./interface '*.hpp' '*.h')",
      ],
      "include_dirs": [
        "./generated-src/objc",
        "./generated-src/cpp",
        "./src",
        "./interface",
      ],
      'all_dependent_settings': {
        'include_dirs': [
          './generated-src/objc',
          "./interface",
        ]
      },
      "defines": [
        'ZF_LOG_USE_NSLOG',
      ],
    },
    {
      "target_name": "gearsbox_jni",
      "type": "static_library",
      "dependencies": [
        "./deps/djinni/support-lib/support_lib.gyp:djinni_jni",
        "./deps/sqlite3/sqlite3.gyp:sqlite3",
        "./deps/curl/libcurl.gyp:libcurl",
        "./deps/libuv/uv.gyp:libuv",
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
        "./interface",
      ],
      "defines": [
        'ZF_LOG_USE_ANDROID_LOG',
      ],
      'all_dependent_settings': {
        'include_dirs': [
          "./interface",
        ]
      },
    },
  ],
}