// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

package com.mycompany.lego;

/**
 *######################################
 * App Architecture Related Interfaces #
 *######################################
 */
public final class People {


    /*package*/ final String mFirstName;

    /*package*/ final String mLastName;

    public People(
            String firstName,
            String lastName) {
        this.mFirstName = firstName;
        this.mLastName = lastName;
    }

    public String getFirstName() {
        return mFirstName;
    }

    public String getLastName() {
        return mLastName;
    }

    @Override
    public String toString() {
        return "People{" +
                "mFirstName=" + mFirstName +
                "," + "mLastName=" + mLastName +
        "}";
    }

}