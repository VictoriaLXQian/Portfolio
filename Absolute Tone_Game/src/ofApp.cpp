#include "ofApp.h"
#include <iostream>
#include <stdio.h>

float a;
bool startX, startY;
ofImage circleOne, circleTwo, noteH;
ofVec2f circleO, circleT;
ofVec2f circleOcenter, circleTcenter;
ofVec2f velO, velT;
ofTrueTypeFont scoreFont,text,worLose,regNotes; // title using Amaticr
ofSoundPlayer la;
ofSoundPlayer xi;
ofSoundPlayer xiLow;
ofSoundPlayer duo, duoCello;
ofSoundPlayer rui;
ofSoundPlayer ruiLow;
ofSoundPlayer mi, miCello;
ofSoundPlayer fa, faCello;
ofSoundPlayer soHigh;
ofSoundPlayer so;
ofSoundPlayer playlist[13]={la,xi,xiLow,duo,rui,ruiLow,mi,fa,so,soHigh,duoCello,miCello,faCello};
bool pressOne, pressTwo, pressTre, pressFour, pressFive, pressSix, pressSeven;
bool pressA, pressB, pressC, pressD, pressE, pressF, pressG, pressAny;
bool one, two, three, four, five, six, seven, any;
float pxDistance;
float b;
bool second;
bool youlose, youwin, start, restart;
float currentSec;
int k, f, g;
ofColor pressColor,black, white,pressYellow;
note note1,note2,note3, note4, note5, note6, note7;


//--------------------------------------------------------------
note::note(){
    offsetX = ofRandom (-400,500);
    offsetY = ofRandom(-500,400);
}
void note::setup(){
    noteOne.load("noteOne.png");
}

void note::update(){
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time*0.05, time*0.05,time*0.05)*400.0;
    rY = ofSignedNoise(time*0.03)*400.0;
    rZ = ofSignedNoise(time*0.09)*400.0;
    offsetX += 0.1;
    offsetY += 0.07;
}

void note::draw(){
    ofPushMatrix();
    ofTranslate(ofGetScreenWidth()/2+offsetX, ofGetScreenHeight()/2+offsetY);
    ofScale(0.4,0.4,0.4);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    noteOne.draw(0-noteOne.getWidth()/2, 50-noteOne.getHeight()/2);
    ofPopMatrix();
}

void ofApp::setup(){
    ofSetFrameRate(60);
    text.load("Montserrat-Regular.ttf", 20);
    worLose.load("BodoniFLF-BoldItalic.ttf", 150);
    regNotes.load("BodoniFLF-Roman.ttf", 14);
    scoreFont.load("Montserrat-Bold.ttf", 28);
    circleOne.load("circleOne.png");
    circleTwo.load("circleTwo.png");
    la.load("a.mp3");
    xi.load("b.mp3");
    xiLow.load("bLow.mp3");
    duo.load("c.mp3");
    duoCello.load("cello C.mp3");
    rui.load("d.mp3");
    ruiLow.load("dLow.mp3");
    mi.load("e.mp3");
    miCello.load("cello E.mp3");
    fa.load("f.mp3");
    faCello.load("cello F.mp3");
    so.load("g.mp3");
    soHigh.load("gHigh.mp3");
    noteH.load("noteOne.png");
    ofSeedRandom();
    note1.setup();
    note2.setup();
    note3.setup();
    note4.setup();
    note5.setup();
    note6.setup();
    note7.setup();
    circleO = ofVec2f(0,0);
    circleT = ofVec2f(ofGetScreenWidth(),ofGetScreenHeight());
    velO = ofVec2f(ofRandom(-10,10),ofRandom(-10,10));
    velT = ofVec2f(ofRandom(-13,13),ofRandom(-13,13));
    f = 0;
}
int i = 0;
float rX = 0;
float rY = 0;
float rZ = 0;
//--------------------------------------------------------------
void ofApp::update(){
    pressColor = ofColor(160, 191, 191, 150);//160    191    191
    pressYellow = ofColor (244,184,36);
    black = ofColor (5,17,43);
    white = ofColor (255,255,255);
    //---------------------------------------     collision function     ------------------------------
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
        if (pxDistance > 420 && pxDistance <= 700) {
            velO.rotate(ofRandom(-80,80));
            velT.rotate(ofRandom(-70,70));
        }else if (pxDistance <= 420 && (circleOa == true || circleTa == true)){
            circleTa = false;
            circleOa =false;
            second = true;
        }
    }
    //---------------------------------------     game page     ------------------------------
    k = ofRandom(0, 12);
    
    note1.update();
    note2.update();
    note3.update();
    note4.update();
    note5.update();
    note6.update();
    note7.update();

//    if (g == 2 && start){
//        g = 1;
//        youwin = false;
//        youlose = false;
//        start = false;
//        f ++;
//    }
//    if (g == 3 && start){
//        g = 1;
//        youlose = false;
//        youwin = false;
//        start = false;
//        f --;
//    }
    if (g==2){
        g = 1;
        f ++;
        youwin = false;
        youlose = false;
    }
    if (g == 3){
        g = 1;
        f --;
        youlose = false;
    }
    
}

//*************************************************    FUNCTION: SECOND PAGE    ************************************************

void ofApp::secondPage(){
    ofSetColor(pressYellow);
    text.drawString("Press the accordinate LETTER KEY to listen to the tuned notes", ofGetScreenWidth()/4, 75);
    //---------------------------------------     白键     ------------------------------
    for (float b=0; b < ofGetScreenWidth(); b+=a) {
        ofSetColor(255, 255, 255);
        ofDrawRectangle(b+10, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
    }
    regNotes.drawString("1",1.5*a-4, 325);
    regNotes.drawString("2",2.5*a-2, 325);
    regNotes.drawString("3",3.5*a-1, 325);
    regNotes.drawString("4",4.5*a, 325);
    regNotes.drawString("5",5.5*a, 325);
    regNotes.drawString("6",6.5*a, 325);
    regNotes.drawString("7",7.5*a, 325);
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
    //---------------------------------------     PRESS-INTERACTION     ------------------------------
    if (pressC){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(pressYellow);
        regNotes.drawString("1",1.5*a-4, 325);
        ofDrawEllipse(1.5*a, 290, 20, 14);
        ofDrawLine(1.5*a-16, 290, 1.5*a+16, 290);
        ofDrawLine(1.5*a+10, 290, 1.5*a+10, 235);
        pressC = false;
    }
    if (pressD){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*2, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(pressYellow);
        regNotes.drawString("2",2.5*a-2, 325);
        ofDrawEllipse(2.5*a, 282, 20, 14);
        ofDrawLine(2.5*a+10, 282, 2.5*a+10, 227);
        pressD = false;
    }
    if (pressE){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*3, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(pressYellow);
        ofDrawEllipse(3.5*a, 274, 20, 14);
        ofDrawLine(3.5*a+10, 274, 3.5*a+10, 219);
        regNotes.drawString("3",3.5*a-1, 325);
        pressE = false;
    }
    if (pressF){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*4, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(pressYellow);
        ofDrawEllipse(4.5*a, 266, 20, 14);
        ofDrawLine(4.5*a+10, 266, 4.5*a+10, 211);
        regNotes.drawString("4",4.5*a, 325);
        pressF = false;
    }
    if (pressG){
        ofSetColor(pressColor);
        ofDrawRectangle(10+a*5, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(pressYellow);
        ofDrawEllipse(5.5*a, 258, 20, 14);
        ofDrawLine(5.5*a+10, 258, 5.5*a+10, 203);
        regNotes.drawString("5",5.5*a, 325);
        pressG = false;
    }
    if (pressA){
        ofSetColor(pressColor);
        ofDrawRectangle(10+6*a, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(pressYellow);
        ofDrawEllipse(6.5*a, 250, 20, 14);
        ofDrawLine(6.5*a+10, 250, 6.5*a+10, 195);
        regNotes.drawString("6",6.5*a, 325);
        pressA = false;
    }
    if (pressB){
        ofSetColor(pressColor);
        ofDrawRectangle(10+7*a, ofGetScreenHeight()/2, a-5, (0.66)*ofGetScreenHeight());
        ofSetColor(pressYellow);
        ofDrawEllipse(7.5*a, 242, 20, 14);
        ofDrawLine(7.5*a-10, 242, 7.5*a-10, 297);
        regNotes.drawString("7",7.5*a, 325);
        pressB = false;
    }
    ofSetColor(black);
    regNotes.drawString("C", 5+1.5*a, ofGetScreenHeight()/2+500);
    regNotes.drawString("D", 5+2.5*a, ofGetScreenHeight()/2+500);
    regNotes.drawString("E", 5+3.5*a, ofGetScreenHeight()/2+500);
    regNotes.drawString("F", 5+4.5*a, ofGetScreenHeight()/2+500);
    regNotes.drawString("G", 5+5.5*a, ofGetScreenHeight()/2+500);
    regNotes.drawString("A", 5+6.5*a, ofGetScreenHeight()/2+500);
    regNotes.drawString("B", 5+7.5*a, ofGetScreenHeight()/2+500);
    //---------------------------------------     升降号     ------------------------------
    ofSetColor(black);
    ofDrawRectangle(2*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(3*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(5*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(6*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
    ofDrawRectangle(7*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.8)*ofGetScreenHeight());
}

//*************************************************    FUNCTION: KEYBOARD    ************************************************

void ofApp::pianoKeyboard(){
    for (float b=0; b < ofGetScreenWidth(); b+=a) {
        ofSetColor(white);
        ofDrawRectangle(b+10, ofGetScreenHeight()/3, a-5, (0.66)*ofGetScreenHeight());
    } //白键
    int array [9]= {1,2,3,4,5,6,7,8,9};
    int f = ofRandom(0, 8);
    ofSetColor(pressColor);
    ofDrawRectangle(10+a*array[f],ofGetScreenHeight()/3, a-5, (0.66)*ofGetScreenHeight());
    
    ofSetColor(black); //升降号
    ofDrawRectangle(2*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(3*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(5*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(6*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    ofDrawRectangle(7*(ofGetScreenWidth()/9)-50, (ofGetScreenHeight()/3)-2, a/2, (0.66*0.65)*ofGetScreenHeight());
    
    ofSetCircleResolution(40);
    ofSetColor(white);
    ofDrawCircle(150, 150, 65);
    ofSetColor(black);
    ofDrawCircle(150, 150, 60);
}
//*************************************************    FUNCTION: WIN    ************************************************

void ofApp::win(){
    ofSetColor(181, 208, 142);
    ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
    ofSetColor(white);
    ofDrawRectangle(350, ofGetScreenHeight()/2 - 150, 1000, 220);
    ofSetColor(38,126,3);
    worLose.drawString("Y A S S S !", 370, ofGetScreenHeight()/2+20);
}

//*************************************************    FUNCTION: LOSE    ************************************************


void ofApp::lose(){
    ofSetColor(249, 189, 199);
    ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
    ofSetColor(white);
    ofDrawRectangle(350, ofGetScreenHeight()/2 - 150, 1000, 220);
    ofSetColor(255, 0, 0);
    worLose.drawString("N O P E :(", 400, ofGetScreenHeight()/2+20);
    string notes;
    if (pressOne){
        notes = "C";
    }
    if (pressTwo){
        notes = "D";
    }
    if (pressTre){
        notes = "E";
    }
    if (pressFour){
        notes = "F";
    }
    if (pressFive){
        notes = "G";
    }
    if (pressSix){
        notes = "A";
    }
    if (pressSeven){
        notes = "B";
    }
    if (pressAny){
        notes = "NOT TUNED";
    }
    scoreFont.drawString(notes, ofGetScreenWidth()-300, 160);
}

void ofApp::draw(){
    ofBackground(black);
    if (circleTa || circleOa){
        ofSetColor(ofRandom(0,255),ofRandom(0,255) , ofRandom(0,255));
        note1.draw();
        note2.draw();
        note3.draw();
        note4.draw();
        note5.draw();
        note6.draw();
        note7.draw();
        ofSetColor(white);
        circleOne.draw(circleO);
        circleTwo.draw(circleT);
    }
    //*************************************************     collision, first page   **********************************************
    if (second && ! start) {
        secondPage();
    }
    //*************************************************    Educational Page    ************************************************
    if ((startX && startY) || g == 1) {
        ofBackground(black);
        pianoKeyboard();
        if (youwin){
            win();
            g = 2;
            f ++;
            youwin = false;
        }
        if (youlose){
            lose();
            g = 3;
            f --;
            youlose = false;
        }
        
        ofSetColor(white);
        string score = ofToString (f);
        scoreFont.drawString(score, 137, 160);

//        ------------------------------------  PRESS RETURN KEY TO RESTART  --------------------------------------------
    }
    //*************************************************    GAME Page    ************************************************
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
    if (key == OF_KEY_RETURN) start = true;
    if (key == OF_KEY_COMMAND) restart = true;
    if (key == '1'&&pressOne)
        youwin = true;
    if ((key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7') && pressOne)
        youlose = true;
    one = true;
    if (key == '2'&&pressTwo)
        youwin = true;
    if ((key == '1' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7') && pressTwo)
        youlose = true;
        two = true;
    if (key == '3'&&pressTre)
        youwin = true;
    if ((key == '1' || key == '2' || key == '4' || key == '5' || key == '6' || key == '7')&&pressTre)
        youlose = true;
        three = true;
    if (key == '4'&&pressFour)
        youwin = true;
    if ((key == '1' || key == '2' || key == '3' || key == '5' || key == '6' || key == '7')&&pressFour)
        youlose = true;
        four = true;
    if (key == '5'&&pressFive)
        youwin = true;
    if ((key == '1' || key == '2' || key == '3' || key == '4' || key == '6' || key == '7')&&pressFive)
        youlose = true;
        five = true;
    if (key == '6'&&pressSix)
        youwin = true;
    if ((key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '7')&&pressSix)
        youlose = true;
        six = true;
    if (key == '7'&&pressSeven)
        youwin = true;
    if ((key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6')&&pressSeven)
        youlose = true;
        seven = true;
    if (key == OF_KEY_RIGHT && pressAny)youwin = true;
    if ((key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7') && pressAny)
        youlose = true;
        any = true;
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
    k = ofRandom(0,12);
    if (ofInRange(x, 0, ofGetScreenWidth())) startX = true;
    if (ofInRange(y, 0, ofGetScreenHeight())) startY = true;
    if (startX&&startY) currentSec = ofGetElapsedTimef();
//    cout << currentSec << endl;
    if (startX&&startY) {
        playlist[k].play();
    }
    cout << k << endl;
    if (k==0)pressSix = true;
    if (k==1)pressSeven = true;
    if (k==3 || k==10)pressOne=true;
    if (k==4)pressTwo = true;
    if (k==6 || k==11)pressTre = true;
    if (k==7 || k==12)pressFour = true;
    if (k==8)pressFive = true;
    if (k==2 || k == 5 || k == 9)pressAny = true;
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
