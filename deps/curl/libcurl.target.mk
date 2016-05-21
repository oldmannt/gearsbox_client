# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := libcurl
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
LOCAL_SDK_VERSION := 19
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES :=

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

LOCAL_GENERATED_SOURCES :=

GYP_COPIED_SOURCE_ORIGIN_DIRS :=

LOCAL_SRC_FILES := \
	deps/curl/src/amigaos.c \
	deps/curl/src/asyn-ares.c \
	deps/curl/src/asyn-thread.c \
	deps/curl/src/axtls.c \
	deps/curl/src/base64.c \
	deps/curl/src/bundles.c \
	deps/curl/src/conncache.c \
	deps/curl/src/connect.c \
	deps/curl/src/content_encoding.c \
	deps/curl/src/cookie.c \
	deps/curl/src/curl_addrinfo.c \
	deps/curl/src/curl_darwinssl.c \
	deps/curl/src/curl_fnmatch.c \
	deps/curl/src/curl_gethostname.c \
	deps/curl/src/curl_gssapi.c \
	deps/curl/src/curl_memrchr.c \
	deps/curl/src/curl_multibyte.c \
	deps/curl/src/curl_ntlm.c \
	deps/curl/src/curl_ntlm_core.c \
	deps/curl/src/curl_ntlm_msgs.c \
	deps/curl/src/curl_ntlm_wb.c \
	deps/curl/src/curl_rtmp.c \
	deps/curl/src/curl_sasl.c \
	deps/curl/src/curl_schannel.c \
	deps/curl/src/curl_sspi.c \
	deps/curl/src/curl_threads.c \
	deps/curl/src/cyassl.c \
	deps/curl/src/dict.c \
	deps/curl/src/dotdot.c \
	deps/curl/src/easy.c \
	deps/curl/src/escape.c \
	deps/curl/src/file.c \
	deps/curl/src/fileinfo.c \
	deps/curl/src/formdata.c \
	deps/curl/src/ftp.c \
	deps/curl/src/ftplistparser.c \
	deps/curl/src/getenv.c \
	deps/curl/src/getinfo.c \
	deps/curl/src/gopher.c \
	deps/curl/src/gskit.c \
	deps/curl/src/gtls.c \
	deps/curl/src/hash.c \
	deps/curl/src/hmac.c \
	deps/curl/src/hostasyn.c \
	deps/curl/src/hostcheck.c \
	deps/curl/src/hostip.c \
	deps/curl/src/hostip4.c \
	deps/curl/src/hostip6.c \
	deps/curl/src/hostsyn.c \
	deps/curl/src/http.c \
	deps/curl/src/http2.c \
	deps/curl/src/http_chunks.c \
	deps/curl/src/http_digest.c \
	deps/curl/src/http_negotiate.c \
	deps/curl/src/http_negotiate_sspi.c \
	deps/curl/src/http_proxy.c \
	deps/curl/src/idn_win32.c \
	deps/curl/src/if2ip.c \
	deps/curl/src/imap.c \
	deps/curl/src/inet_ntop.c \
	deps/curl/src/inet_pton.c \
	deps/curl/src/krb5.c \
	deps/curl/src/ldap.c \
	deps/curl/src/llist.c \
	deps/curl/src/md4.c \
	deps/curl/src/md5.c \
	deps/curl/src/memdebug.c \
	deps/curl/src/mprintf.c \
	deps/curl/src/multi.c \
	deps/curl/src/netrc.c \
	deps/curl/src/non-ascii.c \
	deps/curl/src/nonblock.c \
	deps/curl/src/nss.c \
	deps/curl/src/nwlib.c \
	deps/curl/src/nwos.c \
	deps/curl/src/openldap.c \
	deps/curl/src/parsedate.c \
	deps/curl/src/pingpong.c \
	deps/curl/src/pipeline.c \
	deps/curl/src/polarssl.c \
	deps/curl/src/polarssl_threadlock.c \
	deps/curl/src/pop3.c \
	deps/curl/src/progress.c \
	deps/curl/src/qssl.c \
	deps/curl/src/rawstr.c \
	deps/curl/src/rtsp.c \
	deps/curl/src/security.c \
	deps/curl/src/select.c \
	deps/curl/src/sendf.c \
	deps/curl/src/share.c \
	deps/curl/src/slist.c \
	deps/curl/src/smtp.c \
	deps/curl/src/socks.c \
	deps/curl/src/socks_gssapi.c \
	deps/curl/src/socks_sspi.c \
	deps/curl/src/speedcheck.c \
	deps/curl/src/splay.c \
	deps/curl/src/ssh.c \
	deps/curl/src/sslgen.c \
	deps/curl/src/ssluse.c \
	deps/curl/src/strdup.c \
	deps/curl/src/strequal.c \
	deps/curl/src/strerror.c \
	deps/curl/src/strtok.c \
	deps/curl/src/strtoofft.c \
	deps/curl/src/telnet.c \
	deps/curl/src/tftp.c \
	deps/curl/src/timeval.c \
	deps/curl/src/transfer.c \
	deps/curl/src/url.c \
	deps/curl/src/version.c \
	deps/curl/src/warnless.c \
	deps/curl/src/wildcard.c \
	deps/curl/src/x509asn1.c


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	-gdwarf-2 \
	-Werror \
	-Wall \
	-Wextra \
	-Wno-missing-field-initializers \
	-g \
	-O0 \
	-DDEBUG=1

MY_DEFS_Debug := \
	'-DDEBUG=1'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(LOCAL_PATH)/deps/curl \
	$(LOCAL_PATH)/deps/curl/curl


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-std=c++11 \
	-frtti \
	-fexceptions \
	-Wno-literal-suffix


# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	-gdwarf-2 \
	-Werror \
	-Wall \
	-Wextra \
	-Wno-missing-field-initializers \
	-Os \
	-fomit-frame-pointer \
	-fdata-sections \
	-ffunction-sections \
	-DNDEBUG=1

MY_DEFS_Release := \
	'-DNDEBUG=1'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(LOCAL_PATH)/deps/curl \
	$(LOCAL_PATH)/deps/curl/curl


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-std=c++11 \
	-frtti \
	-fexceptions \
	-Wno-literal-suffix


LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.
include $(BUILD_STATIC_LIBRARY)