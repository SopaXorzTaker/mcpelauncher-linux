#pragma once

#include <string>
#include <unistd.h>
#include <sys/param.h>
#include "../mcpe/gl.h"
#include "../mcpe/AppPlatform.h"

class ImageData;
class ImagePickingCallback;

class LinuxAppPlatform : public AppPlatform {

public:
    static void** myVtable;
    static void initVtable(void** base, int baseSize);

    static bool mousePointerHidden;

    std::string region;
    std::string internalStorage, externalStorage, userdata;

    LinuxAppPlatform();

    std::string getDataUrl() { // this is used only for sounds
        printf("get data url: assets/\n");
        return "assets/";
    }

    std::string getImagePath(std::string const& img, bool b) {
        printf("get image path: %s (%i)\n", img.c_str(), b);
        return (b ? (std::string("assets/images/") + img) : img);
    }
    void loadPNG(ImageData&, std::string const&, bool);

    void hideMousePointer() {
        mousePointerHidden = true;
    }
    void showMousePointer() {
        mousePointerHidden = false;
    }

    void swapBuffers() {
        //printf("swap buffers\n");
    }
    std::string const& getSystemRegion() {
        printf("get system region: %s\n", region.c_str());
        return region;
    }

    std::string getGraphicsVendor() {
        printf("vendor: %s\n", gl::getOpenGLVendor().c_str());
        return gl::getOpenGLVendor();
    }
    std::string getGraphicsRenderer() {
        printf("renderer: %s\n", gl::getOpenGLRenderer().c_str());
        return gl::getOpenGLRenderer();
    }
    std::string getGraphicsVersion() {
        printf("version: %s\n", gl::getOpenGLVersion().c_str());
        return gl::getOpenGLVersion();
    }
    std::string getGraphicsExtensions() {
        printf("extensions: %s\n", gl::getOpenGLExtensions().c_str());
        return gl::getOpenGLExtensions();
    }

    void pickImage(ImagePickingCallback& callback) {
        printf("pick image\n");
    }
    std::string& getExternalStoragePath() {
        printf("external storage path = %s\n", externalStorage.c_str());
        return externalStorage;
    }
    std::string& getInternalStoragePath() {
        printf("internal storage path = %s\n", internalStorage.c_str());
        return internalStorage;
    }
    std::string& getUserdataPath() {
        printf("userdata path = %s\n", userdata.c_str());
        return userdata;
    }
    std::string readAssetFile(std::string const&);
    std::string getApplicationId() {
        printf("application id = com.mojang.minecraftpe\n");
        return "com.mojang.minecraftpe";
    }
    std::string getDeviceId() {
        printf("device id = linux\n");
        return "linux";
    }
    std::string createUUID();
    bool isFirstSnoopLaunch() {
        printf("is first snoop launch = true\n");
        return true;
    }
    bool hasHardwareInformationChanged() {
        printf("has hardware information change = false\n");
        return false;
    }
    bool isTablet() {
        printf("is tablet = true\n");
        return true;
    }

};