./build_ios/libdjinni_sqlite.xcodeproj: libdjinni_sqlite.gyp ./deps/djinni/support-lib/support_lib.gyp djinni_sqlite.djinni
	sh ./run_djinni.sh
	deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Ideps/djinni/common.gypi ./libdjinni_sqlite.gyp

ios: ./build_ios/libdjinni_sqlite.xcodeproj
	xcodebuild -workspace ios_project/djinni_sqlite.xcworkspace \
		-scheme djinni_sqlite \
		-configuration 'Debug' \
		-sdk iphonesimulator

GypAndroid.mk: libdjinni_sqlite.gyp ./deps/djinni/support-lib/support_lib.gyp djinni_sqlite.djinni
	sh ./run_djinni.sh
	ANDROID_BUILD_TOP=$(shell dirname `which ndk-build`) deps/gyp/gyp --depth=. -f android -DOS=android -Ideps/djinni/common.gypi ./libdjinni_sqlite.gyp --root-target=libdjinni_sqlite_jni

android: GypAndroid.mk
	cd android_project/TodoApp/ && ./gradlew app:assembleDebug
	@echo "Apks produced at:"
	@python deps/djinni/example/glob.py ./ '*.apk'

sqlite: ./build_ios/libdjinni_sqlite.xcodeproj