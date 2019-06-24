#include "ofApp.h"
#include "ofSerial.h"
#include "ofArduino.h"

int milanTime, milanSunrise, milanSunset;
int hongkongTime, hongkongSunrise, hongkongSunset;
int hkStart, hkEnd;
int americaTime, americaSunrise, americaSunset;
bool hongkong;
bool milan;
bool usa;

//--------------------------------------------------------------

void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    std::string urlMilan = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/45.4642,9.1900";
    std::string urlHkg = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/22.3193,114.1694";
    std::string urlNc = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/35.7796,-78.6382";
    bool nc = jsonNc.open(urlNc);
    bool milan = jsonMilan.open(urlMilan);
    bool hkg = jsonHkg.open(urlHkg);
    hongkongTime = jsonHkg["currently"]["time"].asInt();
    hongkongSunrise = jsonHkg["daily"]["data"][0]["sunriseTime"].asInt();
    hongkongSunset = jsonHkg["daily"]["data"][0]["sunsetTime"].asInt();
    hkStart =jsonHkg["daily"]["data"][0]["time"].asFloat();
    hkEnd =jsonHkg["daily"]["data"][1]["time"].asFloat();
    gui.setup();
    gui.add(time.setup("timeTest",hongkongTime,hkStart,hkEnd));
    
    int baud = 57600;
    ard.connect("/dev/cu.usbmodem14101",baud);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = false;

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateArduino();
    milanTime = jsonMilan["currently"]["time"].asInt();
    milanSunrise = jsonMilan["daily"]["data"][0]["sunriseTime"].asInt();
    milanSunset = jsonMilan["daily"]["data"][0]["sunsetTime"].asInt();
    americaTime = jsonNc["currently"]["time"].asInt();
    americaSunrise = jsonNc["daily"]["data"][0]["sunriseTime"].asInt();
    americaSunset = jsonNc["daily"]["data"][0]["sunsetTime"].asInt();
    
    if (americaTime > americaSunrise && americaTime < americaSunset) {
        usa = true;
    }else if (americaTime < americaSunrise || americaTime > americaSunset)
        usa = false;
    if (milanTime > milanSunrise && milanTime < milanSunset){
        milan = true;
    }else if (milanTime < milanSunrise || milanTime > milanSunset)
        milan = false;
    if (time > hongkongSunrise && time < hongkongSunset) {
        hongkong = true;
    }else if (time < hongkongSunrise||time > hongkongSunset)
        hongkong = false;    
}

void ofApp::setupArduino(const int & version){

    ofRemoveListener(ard.EInitialized, this,&ofApp::setupArduino);
    bSetupArduino = true;
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();

//    for (int i = 0; i < 13; i++){
//        ard.sendDigitalPinMode(i, ARD_OUTPUT);
//        ard.sendDigital(i, ARD_LOW);
//    }
    ard.sendDigitalPinMode(8, ARD_OUTPUT);
    ard.sendDigitalPinMode(13, ARD_OUTPUT);
    ard.sendDigitalPinMode(12, ARD_OUTPUT);
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::updateArduino(){
    ard.update();
    ofSetColor (255,255,255);
    if (bSetupArduino){
//        cout << bSetupArduino << endl;
        string msg;
        if (hongkong==true){
            ard.sendDigitalPinMode(11, ARD_HIGH);
            msg = "HK DAY";
            ofDrawBitmapString(msg, 200, 200);
        }else
            ard.sendDigitalPinMode(11, ARD_LOW);
            msg = "HK NIGHT";
            ofDrawBitmapString(msg, 200, 200);
        if (milan == true){
            msg = "IT DAY";
            ofDrawBitmapString(msg, 200, 300);
            ard.sendDigital(13, ARD_HIGH);
        }else
            ard.sendDigital(13,ARD_LOW);
            msg = "IT NIGHT";
            ofDrawBitmapString(msg, 200, 300);
        if (usa == true){
            ard.sendDigital(8, ARD_HIGH);
            msg = "USA DAY";
            ofDrawBitmapString(msg, 200, 400);
        }else
            ard.sendDigital(8, ARD_LOW);
            msg = "USA NIGHT";
            ofDrawBitmapString(msg, 200, 400);
    }
    gui.draw();
}
void ofApp::digitalPinChanged(const int & pinNum) {
    // do something with the digital input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ard.getDigital(pinNum));
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
    // do something with the analog input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor (255,255,255);
//    if (hongkong == true)
//        ofDrawBitmapString("HK DAY", 200, 200);
//    if (milan == true)
//        ofDrawBitmapString("IT DAY", 200, 300);
//    if (usa == true)
//        ofDrawBitmapString("USA DAY", 200, 400);
//    if (bSetupArduino){
//        cout << bSetupArduino << endl;
//        string msg;
//        if (hongkong==true){
//            ard.sendDigitalPinMode(13, ARD_HIGH);
//            msg = "HK DAY";
//            ofDrawBitmapString(msg, 200, 200);
//        }else
//            ard.sendDigitalPinMode(13, ARD_LOW);
//            msg = "HK NIGHT";
//            ofDrawBitmapString(msg, 200, 200);
//        if (milan == true){
//            msg = "IT DAY";
//            ofDrawBitmapString(msg, 200, 300);
//            ard.sendDigital(12, ARD_HIGH);
//        }else
//            ard.sendDigital(12,ARD_LOW);
//            msg = "IT NIGHT";
//            ofDrawBitmapString(msg, 200, 300);
//        if (usa == true){
//            ard.sendDigital(8, ARD_HIGH);
//            msg = "USA DAY";
//            ofDrawBitmapString(msg, 200, 400);
//        }else
//            ard.sendDigital(8, ARD_LOW);
//            msg = "USA NIGHT";
//            ofDrawBitmapString(msg, 200, 400);
//    }
    if (!bSetupArduino){
        ofDrawBitmapString("Arduino is not ready", 200, 200);
    }else{
        ofDrawBitmapString("Arduino is connected", 200, 300);
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
