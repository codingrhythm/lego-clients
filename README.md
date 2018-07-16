# Demo Clients

If you want to run the demo client, please setup and run the server first: https://github.com/codingrhythm/lego-server/


Make sure you check out all sub modules first. There are two of them, `djinni` and `flatbuffers`.

## iOS App

Run `pod install` in `platforms/ios/lego` to install dependencies. Open `lego.xcworkspace` in Xcode and build the app. Tap on the button will send request to your local server and receive data.


## Generate codes

You will need to install `flatc` in order to compile the fbs file. You can install it via Homebrew `brew install flatbuffers`.

### Compile flatbuffer file

`flatc -c lego.fbs`

### Compile Djinni file

Require `djinni` submodule.

`. djinni.sh`