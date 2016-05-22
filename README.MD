the third party codes and utilities used in projects  

###party codes dependence  
1. curl  
2. libuv  
3. zf_log  
4. jsoncpp  
5. sqlit3  

###interface for c++   
1. IHttpRequest.h  
2. ILog.h  
3. json.h  

###interface for j/o  
1. gearbox_log  
2. async_loop  
3. callback_i64str, need to be implement in j/o  

this should be a sub folder in clent project, I will modify USNIT as as sample  

1. add gearsbox to clent, in root of client directory run the command below
	git submodule add https://github.com/oldmannt/gearsbox_client.git gearsbox
2. create client.djinni, client.gyp, run_djinni.sh in clent
1. create xcworkspace in ios

.####more infomation  
http://ph0b.com/android-studio-gradle-and-ndk-integration/
http://ph0b.com/new-android-studio-ndk-support/  
http://www.slideshare.net/ph0b/mastering-the-ndk-with-android-studio-and-the-gradleexperimental-plugin  
http://tools.android.com/tech-docs/new-build-system/gradle-experimental  
https://codelabs.developers.google.com/codelabs/android-studio-jni/index.html?index=..%2F..%2Findex#0  