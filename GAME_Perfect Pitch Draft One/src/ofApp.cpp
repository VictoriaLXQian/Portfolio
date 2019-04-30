#include "ofApp.h"
#include <iostream>
#include <stdio.h>

float a;
bool startX, startY;
ofImage circleOne, circleTwo, circleThree;
ofVec2f circleO, circleT, circleThr;
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
int whatever;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    gillsans.load("gillsans", 12);
    title.load("amaticr.ttf", 16);
    circleOne.load("circleOne.png");
    circleTwo.load("circleTwo.png");
    circleThree.load("circleThree.png");
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
    circleO = ofVec2f(0,0);
    circleT = ofVec2f(ofGetScreenWidth(),ofGetScreenHeight());
    velO = ofVec2f(ofRandom(-15,15),ofRandom(-15,15));
    velT = ofVec2f(ofRandom(-17,17),ofRandom(-17,17));

    
}
int i = 0;

//--------------------------------------------------------------
void ofApp::update(){
    //sec = (ofGetFrameNum()/60) % 60;
    sec = ofGetElapsedTimef();
    //cout << sec << endl;
    float g;
    g = 5;
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
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(ofColor::white);
    if ( circleTa || circleOa){
        circleOne.draw(circleO);
        circleTwo.draw(circleT);
    }
    // collision, image inset_ first page
    if (second && ! startX) {
        for (int c = 0; c < 8;  c++) {
            ofDrawRectangle(b*c+(c-1)*100, ofGetScreenHeight()/2, 100, 100);
        }
        ofSetColor(0, 0, 0);
        gillsans.drawString("C", b + 48, ofGetScreenHeight()/2+50);
        gillsans.drawString("D", b*2 + 148, ofGetScreenHeight()/2+50);
        gillsans.drawString("E", b*3 + 248, ofGetScreenHeight()/2+50);
        gillsans.drawString("F", b*4 + 348, ofGetScreenHeight()/2+50);
        gillsans.drawString("G", b*5 + 448, ofGetScreenHeight()/2+50);
        gillsans.drawString("A", b*6 + 548, ofGetScreenHeight()/2+50);
        gillsans.drawString("B", b*7 + 648, ofGetScreenHeight()/2+50);
        ofSetColor(255, 255, 255);
        title.drawString("Press the accordinate letter key to listen to the tuned notes", ofGetScreenWidth()/3+150, ofGetScreenHeight()*0.7);
    }
    if (startX && startY) {
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
        if (youlose == true){
            ofSetColor(255, 0, 0);
            ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
        }
        if (youwin == true){
            ofSetColor(0, 255, 0);
            ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
        }
    }    
//    while (startX && startY) {
//            for (float b=0; b < ofGetScreenWidth(); b+=a) {
//            ofSetColor(255, 255, 255);
//            ofDrawRectangle(b+10, ofGetScreenHeight()/3, a-5, (0.66)*ofGetScreenHeight());
//            } //白键
//            ofSetColor(0, 0, 0); //升降号
//            ofDrawRectangle(2*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
//            ofDrawRectangle(3*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
//            ofDrawRectangle(5*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
//            ofDrawRectangle(6*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
//            ofDrawRectangle(7*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
//            if (youlose == true){
//                ofSetColor(255, 0, 0);
//                ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenWidth());
//                continue;
//            }else (youwin == true);
//                ofSetColor(0, 255, 0);
//                ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
//                continue;
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'a':
            la.play();
            break;
        case 'b':
            xi.play();
            break;
        case 'c':
            duo.play();
            break;
        case 'd':
            rui.play();
            break;
        case 'e':
            mi.play();
            break;
        case 'f':
            fa.play();
            break;
        case 'g':
            so.play();
            break;
    }
    // second page, toned notes play
    //if (key == '9') gameover= true;
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
    if (ofInRange(key, 1, 7) && pressAny) youlose = true;
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
    cout << k << endl;
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
