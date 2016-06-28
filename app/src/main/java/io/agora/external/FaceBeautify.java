package io.agora.external;

public class FaceBeautify {
    private static class SoHolder {
        static {
            System.loadLibrary("videoprp");
            System.loadLibrary("FaceBeautify");
        }

        private static final FaceBeautify sInstance = new FaceBeautify();
    }

    private FaceBeautify() {
    }

    public static FaceBeautify getInstance() {
        return SoHolder.sInstance;
    }

    public static class BRIGHTNESS {
        public static final float MAX_VALUE = 1.5f;
        public static final float MIN_VALUE = .0f;
    }

    public static class BEAUTIFY {
        public static final int MAX_VALUE = 15;
        public static final int MIN_VALUE = 0;
    }

    public int start() {
        return doStartFB();
    }

    public int setBrightness(float brightness) {
        return doSetLighteningFactor(brightness);
    }

    public int setBeautify(int beautify) {
        return doSetSmoothnessFactor(beautify);
    }

    public int stop() {
        return doStopFB();
    }

    private native int doStartFB();

    private native int doSetLighteningFactor(float factor);

    private native int doSetSmoothnessFactor(int factor);

    private native int doStopFB();
}
