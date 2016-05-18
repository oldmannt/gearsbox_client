./build_ios/gearsbox.xcodeproj: gearsbox.gyp ./deps/djinni/support-lib/support_lib.gyp gearsbox.djinni
	sh ./run_djinni.sh
	deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Ideps/djinni/common.gypi ./gearsbox.gyp

ios: ./build_ios/gearsbox.xcodeproj
	xcodebuild -workspace ios_project/djinni_sqlite.xcworkspace \
		-scheme gearsbox \
		-configuration 'Debug' \
		-sdk iphonesimulator

GypAndroid.mk: libdjinni_sqlite.gyp ./deps/djinni/support-lib/support_lib.gyp gearsbox.djinni
	sh ./run_djinni.sh
	ANDROID_BUILD_TOP=$(shell dirname `which ndk-build`) deps/gyp/gyp --depth=. -f android -DOS=android -Ideps/djinni/common.gypi ./gearsbox.gyp --root-target=gearsbox_jni

android: GypAndroid.mk
	cd android_project/TodoApp/ && ./gradlew app:assembleDebug
	@echo "Apks produced at:"
	@python deps/djinni/example/glob.py ./ '*.apk'

gearsbox: ./build_ios/gearsbox.xcodeproj