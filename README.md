## NOTICE

If you want to run this demo with our broadcasting SDK, please contact us at sales@agora.io. China users can dial 400 632 6626 for help.

Agora.io live broadcasting SDK will be formally released in Mid July. If you want to run this demo with our broadcasting SDK now, please contact us at sales@agora.io. China users can dial 400 632 6626 for help.

声网Agora.io 实时互动直播SDK将于7月中正式发布。如果你现在等不及想跑demo，可以联系sales@agora.io。中国用户可直接拨打400 632 6626 获取SDK。


## Bug reports

* https://github.com/AgoraLab/OpenLive_Android/issues


## Build Instructions

Android SDK/NDK tools need to be ready on you host machine, if you does not have them ready, follow instructions here:

* https://developer.android.com/studio/index.html
* https://developer.android.com/ndk/index.html


We use `Gradle` to build, if you want know more about `Gradle`, follow instructions here:

* https://developer.android.com/studio/build/index.html
* http://gradle.org/getting-started-android-build/



NOTICE: before building, you need to


1. update your key at app/src/main/res/values/strings_config.xml

	private_vendor_key

	you can get your vendor key at https://dashboard.agora.io/


2. update libraries at app/libs


3. build native codes(such as face beautify module, and you need to put generated *.so files under app/libs)

		cd app/src/main
		ndk-build

Gradle build instructions

	./gradlew assembleDebug
This will generate the APK, you need to install and run this APK on Android devices.

Or just use the one step command to build and install 

	./gradlew installDebug


Enjoy video broadcasting
