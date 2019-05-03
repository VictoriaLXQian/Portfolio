#include "ofApp.h"
#include <iostream>
#include <stdio.h>

float a;
bool startX, startY;
ofImage circleOne, circleTwo, noteH;
ofVec2f circleO, circleT;
ofVec2f circleOcenter, circleTcenter;
ofVec2f velO, velT;
ofTrueTypeFont gillsans,title; // title using Amaticr
ofSoundPlayer la;
ofSoundPlayer xi;
ofSoundPlayer xiLow;
ofSoundPlayer duo;
ofSoundPlayer rui;
ofSoundPlayer ruiLow;
ofSoundPlayer mi;
ofSoundPlayer fa;
ofSoundPlayer soHigh;
ofSoundPlayer so;
ofSoundPlayer playlist[10]={la,xi,xiLow,duo,rui,ruiLow,mi,fa,so,soHigh};
bool pressOne, pressTwo, pressTre, pressFour, pressFive, pressSix, pressSeven;
bool pressA, pressB, pressC, pressD, pressE, pressF, pressG;
bool relA;
bool pressAny, timePass, gameover;
float pxDistance;
float b;
bool second;
int playNotes;
int lose;
bool youlose, youwin;
float sec;
float currentSec;
int k;
int f;
ofColor pressColor,black, white;
note note1,note2;


//--------------------------------------------------------------
note::note(){
    offsetX = ofRandom (-400,500);
    offsetY = ofRandom(-500,400);
}
void note::setup(){
    noteOne.load("noteOne.png");
//    noteTwo.load("noteTwo.png");
//    noteThree.load("noteThree.png");
}

void note::update(){
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time*0.05, time*0.05,time*0.05)*400.0;
    rY = ofSignedNoise(time*0.03)*400.0;
    rZ = ofSignedNoise(time*0.09)*400.0;
    offsetY += 0.02;
    if (offsetY > ofGetHeight()){
        offsetY = ofRandom(-500, -100);
    }
}

void note::draw(){
    ofPushMatrix();
    ofTranslate(ofGetScreenWidth()/2+offsetX, ofGetScreenHeight()/2+offsetY);
    ofScale(2.5,2.5,2.5);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    noteOne.draw(0-noteOne.getWidth()/2, 0-noteOne.getHeight()/2);
//    noteTwo.draw(0-noteTwo.getWidth()/2, 0-noteTwo.getHeight()/2);
//    noteThree.draw(0-noteThree.getWidth()/2, 0-noteThree.getHeight()/2);
    ofPopMatrix();
}

void ofApp::setup(){
    ofSetFrameRate(60);
    gillsans.load("gillsans", 12);
    title.load("amaticr.ttf", 16);
    circleOne.load("circleOne.png");
    circleTwo.load("circleTwo.png");
    la.load("a.mp3");
    xi.load("b.mp3");
    xiLow.load("bLow.mp3");
    duo.load("c.mp3");
    rui.load("d.mp3");
    ruiLow.load("dLow.mp3");
    mi.load("e.mp3");
    fa.load("f.mp3");
    so.load("g.mp3");
    soHigh.load("gHigh.mp3");
    noteH.load("noteOne.png");
    ofSeedRandom();
    note1.setup();
    circleO = ofVec2f(0,0);
    circleT = ofVec2f(ofGetScreenWidth(),ofGetScreenHeight());
    velO = ofVec2f(ofRandom(-15,15),ofRandom(-15,15));
    velT = ofVec2f(ofRandom(-17,17),ofRandom(-17,17));
    
}
int i = 0;
float rX = 0;
float rY = 0;
float rZ = 0;
//--------------------------------------------------------------
void ofApp::update(){
    pressColor = ofColor(0, 0, 255);
    black = ofColor (0,0,0);
    white = ofColor (255,255,255);
    //sec = (ofGetFrameNum()/60) % 60;
    sec = ofGetElapsedTimef();
    //cout << sec << endl;
    
    i ++;
    circleOcenter = ofVec2f(circleO.x+210,circleO.y+210);
    circleTcenter = ofVec2f(circleT.x+210, circleT.y+210);
    a = ofGetScreenWidth()/9;
    b = (ofGetScreenWidth()-700)/8;
    if (!circleOa) {
        return;
    }
    if (!circleTa) {
        return;
    }
    circleO+=(velO*0.3);
    circleT+=(velT*0.3);
    if(circleO.x+420 > ofGetScreenWidth()){
        circleO.x = ofGetScreenWidth()-420;
        velO.x *= -1;
    }
    if(circleT.x+420 > ofGetScreenWidth()){
        circleT.x = ofGetScreenWidth()-420;
        velT.x *= -1;
    }
    if(circleO.x < 0){
        circleO.x = 0;
        velO.x *= -1;
    }
    if(circleT.x < 0){
        circleT.x = 0;
        velT.x *= -1;
    }
    if(circleO.y+420 > ofGetScreenHeight()){
        circleO.y = ofGetScreenHeight()-420;
        velO.y *= -1;
    }
    if(circleT.y+420 > ofGetScreenHeight()){
        circleT.y = ofGetScreenHeight()-420;
        velT.y *= -1;
    }
    if(circleO.y < 0){
        circleO.y = 0;
        velO.y *= -1;
    }
    if(circleT.y < 0){
        circleT.y = 0;
        velT.y *= -1;
    }
    pxDistance = sqrt(pow((circleOcenter.x-circleTcenter.x),2)+pow((circleOcenter.y-circleTcenter.y), 2));
    if (i > 1){
        if (pxDistance > 420 && pxDistance <= 1000) {
            velO.rotate(ofRandom(-50,50));
            velT.rotate(ofRandom(-35,35));
        }else if (pxDistance <= 420 && (circleOa == true || circleTa == true)){
            circleTa = false;
            circleOa =false;
            second = true;
        }
    }
    // collision function
    k = ofRandom(0, 9);
    
    note1.update();
}


//--------------------------------------------------------------
void ofApp::secondPage(){
//        title.drawString("Press the accordinate letter key to listen to the tuned notes", ofGetScreenWidth()/3+150, ofGetScreenHeight()*0.7);
    
    for (float b=0; b < ofGetScreenWidth(); b+=a) {
        ofSetColor(255, 255, 255);
        ofDrawRectangle(b+10, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
    } //白键
    for (float c=1; c < 6; c++){
        ofDrawLine(0, 200+15*c, ofGetScreenWidth(), 200+15*c);
    }
    ofSetLineWidth(2);
    ofDrawEllipse(1.5*a, 290, 20, 14);
    ofDrawLine(1.5*a-16, 290, 1.5*a+16, 290);
    ofDrawLine(1.5*a+10, 290, 1.5*a+10, 235); // do
    ofDrawEllipse(2.5*a, 282, 20, 14);
    ofDrawLine(2.5*a+10, 282, 2.5*a+10, 227);//rui
    ofDrawEllipse(3.5*a, 274, 20, 14);
    ofDrawLine(3.5*a+10, 274, 3.5*a+10, 219); // mi
    ofDrawEllipse(4.5*a, 266, 20, 14);
    ofDrawLine(4.5*a+10, 266, 4.5*a+10, 211); // fa
    ofDrawEllipse(5.5*a, 258, 20, 14);
    ofDrawLine(5.5*a+10, 258, 5.5*a+10, 203); // so
    ofDrawEllipse(6.5*a, 250, 20, 14);
    ofDrawLine(6.5*a+10, 250, 6.5*a+10, 195); // la
    ofDrawEllipse(7.5*a, 242, 20, 14);
    ofDrawLine(7.5*a-10, 242, 7.5*a-10, 297); // xi
    ofPushMatrix();
    ofTranslate(0.3*a, 200);
    ofScale(0.35, 0.35);
    noteH.draw(0,0);
    ofPopMatrix();
    ofSetColor(0, 0, 0);
    gillsans.drawString("C", 5+1.5*a, ofGetScreenHeight()/2+500);
    gillsans.drawString("D", 5+2.5*a, ofGetScreenHeight()/2+500);
    gillsans.drawString("E", 5+3.5*a, ofGetScreenHeight()/2+500);
    gillsans.drawString("F", 5+4.5*a, ofGetScreenHeight()/2+500);
    gillsans.drawString("G", 5+5.5*a, ofGetScreenHeight()/2+500);
    gillsans.drawString("A", 5+6.5*a, ofGetScreenHeight()/2+500);
    gillsans.drawString("B", 5+7.5*a, ofGetScreenHeight()/2+500);
    if (pressA){
        ofSetColor(pressColor);
        ofDrawRectangle(10+6*a, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(white);
        gillsans.drawString("A", 5+6.5*a, ofGetScreenHeight()/2+500);
        gillsans.drawString("6",3+6.5*a, 320);
    }
    else if (pressB){
        ofSetColor(pressColor);
        ofDrawRectangle(10+7*a, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(white);
        gillsans.drawString("B", 5+7.5*a, ofGetScreenHeight()/2+500);
        gillsans.drawString("7",5+7.5*a, 320);
    }
    else if (pressC){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(white);
        gillsans.drawString("C", 5+1.5*a, ofGetScreenHeight()/2+500);
        gillsans.drawString("1",1.5*a, 320);
    }
    else if (pressD){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*2, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(white);
        gillsans.drawString("D", 5+2.5*a, ofGetScreenHeight()/2+500);
        gillsans.drawString("2",5+2.5*a, 320);
    }
    else if (pressE){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*3, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(white);
        gillsans.drawString("E", 5+3.5*a, ofGetScreenHeight()/2+500);
        gillsans.drawString("3",5+3.5*a, 320);
    }
    else if (pressF){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*4, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(white);
        gillsans.drawString("F", 5+4.5*a, ofGetScreenHeight()/2+500);
        gillsans.drawString("4",5+4.5*a, 320);
    }
    else if (pressG){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*5, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(white);
        gillsans.drawString("G", 5+5.5*a, ofGetScreenHeight()/2+500);
        gillsans.drawString("5",5+5.5*a, 320);
    }
    ofSetColor(0, 0, 0); //升降号
    ofDrawRectangle(2*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(3*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(5*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(6*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(7*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
}
void ofApp::pianoKeyboard(){
    for (float b=0; b < ofGetScreenWidth(); b+=a) {
        ofSetColor(255, 255, 255);
        ofDrawRectangle(b+10, ofGetScreenHeight()/3, a-5, (0.66)*ofGetScreenHeight());
    } //白键
    ofSetColor(0, 0, 0); //升降号
    ofDrawRectangle(2*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(3*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(5*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(6*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(7*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    
}
void ofApp::win(){
    ofSetColor(0, 255, 0);
    ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
    note1.draw();
    
}
void ofApp::lose(){
    ofSetColor(255, 0, 0);
    ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
    note1.draw();
    
}
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(ofColor::white);
    if ( circleTa || circleOa){
        circleOne.draw(circleO);
        circleTwo.draw(circleT);
    }
    // collision, image inset_ first page
    if (second && ! startX) {
        secondPage();
    }
    if (startX && startY) {
        pianoKeyboard();
    }
    if (youlose == true){
        lose();
        return;
    } else if (youwin == true){
        win();
        return;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'a':
            la.play();
            pressA = true;
            break;
        case 'b':
            xi.play();
            pressB = true;
            break;
        case 'c':
            duo.play();
            pressC = true;
            break;
        case 'd':
            rui.play();
            pressD = true;
            break;
        case 'e':
            mi.play();
            pressE = true;
            break;
        case 'f':
            fa.play();
            pressF = true;
            break;
        case 'g':
            so.play();
            pressG = true;
            break;
    }
    // second page, toned notes play
    if (key == '9') gameover= true;
    if (key == '1'&&pressOne) youwin = true;
    if ((key != '1') && pressOne) youlose = true;
    if (key == '2'&&pressTwo) youwin = true;
    if ((key != '2') && pressTwo) youlose = true;
    if (key == '3'&&pressTre) youwin = true;
    if (key != '3'&&pressTre) youlose = true;
    if (key == '4'&&pressFour) youwin = true;
    if (key != '4'&&pressFour) youlose = true;
    if (key == '5'&&pressFive) youwin = true;
    if (key != '5'&&pressFive) youlose = true;
    if (key == '6'&&pressSix) youwin = true;
    if (key != '6'&&pressSix) youlose = true;
    if (key == '7'&&pressSeven) youwin = true;
    if (key != '7'&&pressSeven) youlose = true;
    if ((key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7') && pressAny) youlose = true;
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
    if (ofInRange(x, 0, ofGetScreenWidth())) startX = true;
    if (ofInRange(y, 0, ofGetScreenHeight())) startY = true;
    if (startX&&startY) currentSec = ofGetElapsedTimef();
    cout << currentSec << endl;
    float current = sec - currentSec;
    if (current >= 1 && current <= 6) timePass = true;
    //cout << current << endl;
    if (startX&&startY) {
        playlist[k].play();
    }
//    cout << k << endl;
    if (k==0)pressSix = true;
    if (k==1)pressSeven = true;
    if (k==3)pressOne=true;
    if (k==4)pressTwo = true;
    if (k==6)pressTre = true;
    if (k==7)pressFour = true;
    if (k==8)pressFive = true;
    if (k==2 || k == 5 || k == 9) pressAny = true;
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
