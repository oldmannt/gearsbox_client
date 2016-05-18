{ 'targets': [
    {
      'target_name': 'libcurl',
      'type': 'static_library',
      'sources': [
        "<!@(python ../djinni/example/glob.py ./ '*.c')",
      ],
      'all_dependent_settings': {
        'include_dirs': [
          '.',
          './curl',
        ]
      },
      'include_dirs': [
        '.',
        './curl',
      ],
    },
  ]
}

