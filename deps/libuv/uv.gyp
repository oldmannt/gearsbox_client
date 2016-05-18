{
  'target_defaults': {
    'conditions': [
      ['OS != "win"', {
        'defines': [
          '_LARGEFILE_SOURCE',
          '_FILE_OFFSET_BITS=64',
        ],
        'conditions': [
          ['OS=="solaris"', {
            'cflags': [ '-pthreads' ],
          }],
          ['OS not in "solaris android"', {
            'cflags': [ '-pthread' ],
          }],
        ],
      }],
    ],
    'xcode_settings': {
      'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES',  # -fvisibility=hidden
      'WARNING_CFLAGS': [ '-Wall', '-Wextra', '-Wno-unused-parameter' ],
      'OTHER_CFLAGS': [ '-g', '--std=gnu89', '-pedantic' ],
    }
  },

  'targets': [
    {
      'target_name': 'libuv',
      'type': 'static_library',
      'include_dirs': [
        'include',
        'src/',
      ],
      'direct_dependent_settings': {
        'include_dirs': [ 'include' ],
        'conditions': [
          ['OS != "win"', {
            'defines': [
              '_LARGEFILE_SOURCE',
              '_FILE_OFFSET_BITS=64',
            ],
          }],
          ['OS in "mac ios"', {
            'defines': [ '_DARWIN_USE_64_BIT_INODE=1' ],
          }],
          ['OS == "linux"', {
            'defines': [ '_POSIX_C_SOURCE=200112' ],
          }],
        ],
      },
      'sources': [
        'common.gypi',
        'include/uv.h',
        'include/tree.h',
        'include/uv-errno.h',
        'include/uv-threadpool.h',
        'include/uv-version.h',
        'src/fs-poll.c',
        'src/heap-inl.h',
        'src/inet.c',
        'src/queue.h',
        'src/threadpool.c',
        'src/uv-common.c',
        'src/uv-common.h',
        'src/version.c'
      ],
      'conditions': [
        [ 'OS=="win"', {
          'defines': [
            '_WIN32_WINNT=0x0600',
            '_GNU_SOURCE',
          ],
          'sources': [
            'include/uv-win.h',
            'src/win/async.c',
            'src/win/atomicops-inl.h',
            'src/win/core.c',
            'src/win/dl.c',
            'src/win/error.c',
            'src/win/fs.c',
            'src/win/fs-event.c',
            'src/win/getaddrinfo.c',
            'src/win/getnameinfo.c',
            'src/win/handle.c',
            'src/win/handle-inl.h',
            'src/win/internal.h',
            'src/win/loop-watcher.c',
            'src/win/pipe.c',
            'src/win/thread.c',
            'src/win/poll.c',
            'src/win/process.c',
            'src/win/process-stdio.c',
            'src/win/req.c',
            'src/win/req-inl.h',
            'src/win/signal.c',
            'src/win/snprintf.c',
            'src/win/stream.c',
            'src/win/stream-inl.h',
            'src/win/tcp.c',
            'src/win/tty.c',
            'src/win/timer.c',
            'src/win/udp.c',
            'src/win/util.c',
            'src/win/winapi.c',
            'src/win/winapi.h',
            'src/win/winsock.c',
            'src/win/winsock.h',
          ],
          'link_settings': {
            'libraries': [
              '-ladvapi32',
              '-liphlpapi',
              '-lpsapi',
              '-lshell32',
              '-luser32',
              '-luserenv',
              '-lws2_32'
            ],
          },
        }, { # Not Windows i.e. POSIX
          'cflags': [
            '-fvisibility=hidden',
            '-g',
            '--std=gnu89',
            '-pedantic',
            '-Wall',
            '-Wextra',
            '-Wno-unused-parameter',
          ],
          'sources': [
            'include/uv-unix.h',
            'include/uv-linux.h',
            'include/uv-sunos.h',
            'include/uv-darwin.h',
            'include/uv-bsd.h',
            'include/uv-aix.h',
            'src/unix/async.c',
            'src/unix/atomic-ops.h',
            'src/unix/core.c',
            'src/unix/dl.c',
            'src/unix/fs.c',
            'src/unix/getaddrinfo.c',
            'src/unix/getnameinfo.c',
            'src/unix/internal.h',
            'src/unix/loop.c',
            'src/unix/loop-watcher.c',
            'src/unix/pipe.c',
            'src/unix/poll.c',
            'src/unix/process.c',
            'src/unix/signal.c',
            'src/unix/spinlock.h',
            'src/unix/stream.c',
            'src/unix/tcp.c',
            'src/unix/thread.c',
            'src/unix/timer.c',
            'src/unix/tty.c',
            'src/unix/udp.c',
          ],
          'link_settings': {
            'libraries': [ '-lm' ],
            'conditions': [
              ['OS=="solaris"', {
                'ldflags': [ '-pthreads' ],
              }],
              ['OS != "solaris" and OS != "android"', {
                'ldflags': [ '-pthread' ],
              }],
            ],
          },
        }],
        [ 'OS in "linux mac ios android"', {
          'sources': [ 'src/unix/proctitle.c' ],
        }],
        [ 'OS in "mac ios"', {
          'sources': [
            'src/unix/darwin.c',
            'src/unix/fsevents.c',
            'src/unix/darwin-proctitle.c',
            'src/unix/pthread-barrier.c'
          ],
          'defines': [
            '_DARWIN_USE_64_BIT_INODE=1',
            '_DARWIN_UNLIMITED_SELECT=1',
          ]
        }],
        [ 'OS!="mac"', {
          # Enable on all platforms except OS X. The antique gcc/clang that
          # ships with Xcode emits waaaay too many false positives.
          'cflags': [ '-Wstrict-aliasing' ],
        }],
        [ 'OS=="linux"', {
          'defines': [ '_GNU_SOURCE' ],
          'sources': [
            'src/unix/linux-core.c',
            'src/unix/linux-inotify.c',
            'src/unix/linux-syscalls.c',
            'src/unix/linux-syscalls.h',
          ],
          'link_settings': {
            'libraries': [ '-ldl', '-lrt' ],
          },
        }],
        [ 'OS=="android"', {
          'sources': [
            'src/unix/linux-core.c',
            'src/unix/linux-inotify.c',
            'src/unix/linux-syscalls.c',
            'src/unix/linux-syscalls.h',
            'src/unix/pthread-fixes.c',
            'src/unix/android-ifaddrs.c',
            'src/unix/pthread-barrier.c'
          ],
          'link_settings': {
            'libraries': [ '-ldl' ],
          },
        }],
        [ 'OS=="solaris"', {
          'sources': [ 'src/unix/sunos.c' ],
          'defines': [
            '__EXTENSIONS__',
            '_XOPEN_SOURCE=500',
          ],
          'link_settings': {
            'libraries': [
              '-lkstat',
              '-lnsl',
              '-lsendfile',
              '-lsocket',
            ],
          },
        }],
        [ 'OS=="aix"', {
          'sources': [ 'src/unix/aix.c' ],
          'defines': [
            '_ALL_SOURCE',
            '_XOPEN_SOURCE=500',
            '_LINUX_SOURCE_COMPAT',
            '_THREAD_SAFE',
          ],
          'link_settings': {
            'libraries': [
              '-lperfstat',
            ],
          },
        }],
        [ 'OS=="freebsd" or OS=="dragonflybsd"', {
          'sources': [ 'src/unix/freebsd.c' ],
        }],
        [ 'OS=="openbsd"', {
          'sources': [ 'src/unix/openbsd.c' ],
        }],
        [ 'OS=="netbsd"', {
          'sources': [ 'src/unix/netbsd.c' ],
        }],
        [ 'OS in "freebsd dragonflybsd openbsd netbsd".split()', {
          'link_settings': {
            'libraries': [ '-lkvm' ],
          },
        }],
        [ 'OS in "ios mac freebsd dragonflybsd openbsd netbsd".split()', {
          'sources': [ 'src/unix/kqueue.c' ],
        }],
      ]
    },

  ]
}