// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

package com.mycompany.lego;

import java.util.concurrent.atomic.AtomicBoolean;

/** Shared core APIs */
public abstract class LegoCore {
    /** get data */
    public abstract void getData(boolean useGrpc);

    /** send data */
    public abstract void sendData(Template data, boolean useGrpc);

    /** upload file */
    public abstract void uploadFile(byte[] fileData);

    /** download file */
    public abstract void downloadFile(String fileId);

    /** class method to create core API instance */
    public static native LegoCore create(LegoPlatform platform);

    private static final class CppProxy extends LegoCore
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public void getData(boolean useGrpc)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_getData(this.nativeRef, useGrpc);
        }
        private native void native_getData(long _nativeRef, boolean useGrpc);

        @Override
        public void sendData(Template data, boolean useGrpc)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_sendData(this.nativeRef, data, useGrpc);
        }
        private native void native_sendData(long _nativeRef, Template data, boolean useGrpc);

        @Override
        public void uploadFile(byte[] fileData)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_uploadFile(this.nativeRef, fileData);
        }
        private native void native_uploadFile(long _nativeRef, byte[] fileData);

        @Override
        public void downloadFile(String fileId)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_downloadFile(this.nativeRef, fileId);
        }
        private native void native_downloadFile(long _nativeRef, String fileId);
    }
}
