#APP_ABI := all
# 29/08/2024 Android 15 : Add Page Size 16Kb support
# APP_ABI := armeabi armeabi-v7a x86 x86_64 arm64-v8a
APP_ABI := armeabi-v7a x86 x86_64 arm64-v8a
# For future consideration (needs testing):
#APP_ABI += mips mips64

# 03/09/2024 Android 15 : Add Page Size 16Kb support
APP_SUPPORT_FLEXIBLE_PAGE_SIZES := true