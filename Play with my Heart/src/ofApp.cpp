#include "ofApp.h"
const int framerate = 60;
ofVec2f org, cur, mouse;
ofFbo fbo;  // framebuffer object
ofColor heart(255,230,230);
ofColor pink(214,117,117);
Boolean pressF;
Boolean finalPosition;
float a, b, c, d; //For drawing
int direction;

ofTrueTypeFont gillsans,amaticr,amaticBold;


//--------------------------------------------------------------
void ofApp::setup(){
    gillsans.load("gillsans.ttf", 14);
    amaticr.load("amaticr.ttf", 36);
    amaticBold.load("amaticBold.ttf", 32);
    ofSetFrameRate(framerate);
    ofBackground(255, 255, 255);
    org = ofVec2f(ofGetWidth()/3,ofGetHeight()/2); //First Position
    a = 50;
    b = 25;
    c = 100;
    d = 125;
    cur = org;
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    ofSetBackgroundColor(255, 255, 255);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    switch (direction) {
        case 1:
            cur.x-=8; //LEFT
            break;
        case 2:
            cur.y-=8; // UP
            break;
        case 3:
            cur.x+=8; //RIGHT
            break;
        case 4:
            cur.y+=8; //DOWN
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(214,117,117);
    ofSetLineWidth(4);
    ofSetColor(240, 226, 226);
    amaticr.drawString ("PLAY WITH MY HEART", 100, 150);
    gillsans.drawString ("Press the letters 'W' 'A' 'S' 'D'", 650, 530);
    gillsans.drawString ("in the same way as you use ", 650, 545);
    gillsans.drawString ("arrow key to navigate.", 650, 560);
    gillsans.drawString ("Press 'F' and move the heart to", 650, 585);
    gillsans.drawString ("wherever you like!", 650, 600);
    gillsans.drawString ("Finally, press the mouse,", 650, 625);
    gillsans.drawString ("look at where I hide.", 650, 640);
    ofSetColor(221, 156, 156);
    amaticBold.drawString ("PLAY WITH MY HEART", 120, 200);
    ofSetColor(255, 255, 255);
    if (pressF == true)
        cur = mouse;
    fbo.begin();
    ofSetColor(pink, 4);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(heart);
    ofNoFill();
    ofPolyline closedHeart1;
    closedHeart1.addVertex(cur.x, cur.y-a);
    closedHeart1.addVertex(cur.x+c-b, cur.y-c+b/2);
    closedHeart1.addVertex(cur.x+d, cur.y-a);
    closedHeart1.addVertex(cur.x+c, cur.y);
    closedHeart1.addVertex(cur.x, cur.y+c);
    closedHeart1.addVertex(cur.x-c, cur.y);
    closedHeart1.addVertex(cur.x-d,cur.y-a);
    closedHeart1.addVertex(cur.x-c+b,cur.y-c+b/2);
    closedHeart1.close();
    closedHeart1.draw();
    ofFill();
    ofDrawEllipse(cur.x+a, cur.y-a/2, a/2, a);
    ofDrawEllipse(cur.x-a, cur.y-a/2, a/2, a);
    ofSetColor(0, 0, 0);
    ofDrawEllipse(cur.x+a, cur.y-a/2, a/4, a/2);
    ofDrawEllipse(cur.x-a, cur.y-a/2, a/4, a/2);
    ofFill();
   
    
    
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    if (finalPosition == false)
        fbo.draw(0,0); 
    else
        fbo.draw(100,375); // Mouse press position
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='f') pressF = true;
    if(key == 'w') direction = 2;
    if(key == 's') direction = 4;
    if(key == 'a') direction = 1;
    if(key == 'd') direction = 3;
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    finalPosition = true;
    
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
