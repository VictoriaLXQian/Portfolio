#include "ofApp.h"
#include "ofSerial.h"
#include "ofArduino.h"

float a;
int sec;
int five;
int n;
// average 12 hours a day, 12 interval
float milanTime, milanSunrise, milanSunset;
float milanCloud;
string milanSummary;
int r, g, b;
bool milan;

//--------------------------------------------------------------

void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    cout << "start" << endl;
    std::string urlMilan = "YOUR API KEY";
    bool milan = jsonMilan.open(urlMilan);
    cout << n << endl;
    // Connect OpenFrameworks to Arduino
    int baud = 57600;
    ard.connect("/dev/cu.usbmodem146330",baud);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = false;
    

    
}

//--------------------------------------------------------------
void ofApp::update(){
    sec ++;
    //cout << sec << endl;
    five = sec % 18000;
    if (five == 0) {
        std::string urlMilan = "YOUR API KEY";
        bool milan = jsonMilan.open(urlMilan);
        n++;
    }
    // Send API Request EVERY FIVE MINUTES
    //updateArduino();
    milanTime = jsonMilan["currently"]["time"].asFloat();
    milanSunrise = jsonMilan["daily"]["data"][0]["sunriseTime"].asFloat();
    milanSunset = jsonMilan["daily"]["data"][0]["sunsetTime"].asFloat();
    milanCloud = jsonMilan["currently"]["cloudCover"].asFloat();
    milanSummary = jsonMilan["currently"]["summary"].asString();
    a = (milanSunset - milanSunrise)/12;

    if (milanTime > milanSunrise && milanTime < milanSunset){
        milan = true;
        cout << "DAY" << endl;
    }else if (milanTime < milanSunrise || milanTime > milanSunset){
        milan = false;
        cout << "MILANO NIGHT" << endl;
    }
    cout << n << endl;
}

void ofApp::setupArduino(const int & version){

    ofRemoveListener(ard.EInitialized, this,&ofApp::setupArduino);
    bSetupArduino = true;
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    ard.sendDigitalPinMode(6, ARD_PWM); // ard_output for turn on and off
    ard.sendDigitalPinMode(10, ARD_PWM);
    ard.sendDigitalPinMode(11, ARD_PWM);
    //ard.sendAnalogPinReporting(1, ARD_PWM);
    //ard.sendAnalogPinReporting(2, ARD_PWM);
    //ard.sendAnalogPinReporting(3, ARD_PWM);
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::updateArduino(){
    ard.update();
    if (bSetupArduino){
        ofSetColor (255,255,255);
        string msg;
    
       // cout << bSetupArduino << endl;

        if (milan == true){
            msg = "IT DAY";
            ofDrawBitmapString(msg, 200, 300);
            ard.sendPwm(11, 240);
            ard.sendPwm(10, 183);
            ard.sendPwm(6, 125);
            //cout << "DAY" << endl;
        }else if (milan == false)
            ard.sendPwm(11, 0);
            ard.sendPwm(10, 0);
            ard.sendPwm(6, 0);
        
    }

    
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
    if (!bSetupArduino){
        ofDrawBitmapString("Arduino is not ready", 200, 200);
    }else{
        ofDrawBitmapString("Arduino is connected", 200, 300);
    }
    //gui.draw();
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
