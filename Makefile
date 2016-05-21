./build_ios/gearsbox.xcodeproj: gearsbox.gyp ./deps/djinni/support-lib/support_lib.gyp gearsbox.djinni
	sh ./run_djinni.sh
	deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Ideps/djinni/common.gypi ./gearsbox.gyp

ios: ./build_ios/gearsbox.xcodeproj
	xcodebuild -workspace ios_project/djinni_sqlite.xcworkspace \
		-scheme gearsbox \
		-configuration 'Debug' \
		-sdk iphonesimulator

GypAndroid.mk: gearsbox.gyp ./deps/djinni/support-lib/support_lib.gyp gearsbox.djinni
	sh ./run_djinni.sh
	ANDROID_BUILD_TOP=$(shell dirname `which ndk-build`) deps/gyp/gyp --depth=. -f android -DOS=android -Ideps/djinni/common.gypi ./gearsbox.gyp --root-target=gearsbox_jni

android: GypAndroid.mk
	cd project_android/testgearsbox/ && ./gradlew app:assembleDebug
	@echo "Apks produced at:"
	@python deps/djinni/example/glob.py ./ '*.apk'

gearsbox: ./build_ios/gearsbox.xcodeproj

clean_ios:
	-rm -rf build_ios
	-xcodebuild -workspace ios_project/djinni_sqlite.xcworkspace \
		-scheme gearsbox \
		-configuration 'Debug' \
		-sdk iphonesimulator clean

clean_android:
	-rm -f GypAndroid.mk
	-rm -rf project_android/testgearsbox/build
	-rm -rf project_android/testgearsbox/app/build

clean: clean_ios clean_android

deps:
	git submodule add https://github.com/dropbox/djinni.git deps/djinni
	git submodule add https://chromium.googlesource.com/external/gyp.git deps/gyp
	cd deps/gyp &&git checkout -q 0bb67471bca068996e15b56738fa4824dfa19de0

