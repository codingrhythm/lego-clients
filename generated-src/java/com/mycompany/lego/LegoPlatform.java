// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

package com.mycompany.lego;

/** Platform APIs */
public abstract class LegoPlatform {
    /** get platform specific storage path */
    public abstract String getStoragePath();

    /**
     * event subscriptions
     * notify UI layer when data is updated
     */
    public abstract void dataUpdated(Template data);

    /** http methods */
    public abstract void httpDownloadFile(String fileId, NetworkCallback callback);

    public abstract void httpUploadFile(String path, NetworkCallback callback);

    public abstract void httpGetData(NetworkCallback callback);

    public abstract void httpSendData(Template data, NetworkCallback callback);

    /** grpc methods */
    public abstract void grpcGetData(NetworkCallback callback);

    public abstract void grpcSendData(Template data, NetworkCallback callback);
}