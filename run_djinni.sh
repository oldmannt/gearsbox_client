#! /usr/bin/env bash

base_dir=$(cd "`dirname "0"`" && pwd)
cpp_out="$base_dir/generated-src/cpp"
jni_out="$base_dir/generated-src/jni"
objc_out="$base_dir/generated-src/objc"
java_out="$base_dir/generated-src/java/dyno/fun/gearsbox"
yaml_out="$base_dir/generated-src/yaml" 
java_package="dyno.fun.gearsbox"
namespace="gearsbox"
objc_prefix="GB"
djinni_file="gearsbox.djinni"
 
deps/djinni/src/run \
   --java-out $java_out \
   --java-package $java_package \
   --ident-java-field mFooBar \
   \
   --cpp-out $cpp_out \
   --cpp-namespace $namespace \
   \
   --jni-out $jni_out \
   --ident-jni-class NativeFooBar \
   --ident-jni-file NativeFooBar \
   \
   --objc-out $objc_out \
   --objc-type-prefix $objc_prefix \
   \
   --objcpp-out $objc_out \
   \
   --yaml-out "$yaml_out/yaml" \
   --yaml-out-file "yaml-gearsbox.yaml" \
   --yaml-prefix "gb_" \
   \
   --idl $djinni_file