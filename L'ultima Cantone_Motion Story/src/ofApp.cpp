#include "ofApp.h"

float midX, midY; // midpoint
float barOne, barTwo; // train window-movement
float yTrain;
ofVec2f rP,posFm; //running person, the station name MOVEMENT
ofTrueTypeFont gillsans,amaticr,title;
float startX, startY; //RAINDROP MOVEMENT
float picsizeX,picsizeY;
float picX,picY;
ofImage raindrop;
float sec;
float x,y;
float a, b, c, d; // HEARTBREAK
float l1;
float distant;
int dir,dist;
float counter;
float xMid, yMid, yTwo;
float xOne, yOne;
ofImage image;
// cry face
float xFace, yFace, xPos, xPosone, yPos;
// wall with photo, still, arrival scene
ofVec2f mid;
ofImage photo;
// night girl looking at the window
ofVec2f girl,hair;
float girlX, girlY;
// from night to morning
ofImage moonlight;
float z,w;
// stamp moving on the wall
float stampTime;
int direction;
ofVec2f aus,chin,dank,fra,gre,hgr,ita,neth,pol;
ofVec2f pic;
Boolean pressA,pressC,pressD,pressF,pressG,pressH,pressI,pressN,pressP;
ofImage stampAus,stampChin,stampDnmk,stampFra,stampGre,stampHgr,stampIta,stampNeth,stampPol;
// snow scene
snow ml0,ml1,ml2,ml3,ml4,ml5,ml6,ml7,ml8,ml9; // when using the instructor methods, drawing a new one just add the code wherever ml0 is called.
float snowX, snowY;
// TRAIN LAST SCENE
float lsceneOne, lsceneTwo;
ofVec2f person, portaG;
float increment;
// landscape
ofImage landscape;
float landX;
// final writing
float wX, wY;
ofSoundPlayer sound;

//--------------------------------------------------------------

snow::snow(){
    offsetX=ofRandom(-400, 500);
    offsetY=ofRandom(-500, 500);
}
//int sec;
void snow::setup(){  // why can't we load the image in the constructor?
    snowflake.load("snow.png");
}

void snow::update(){
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.05, time * 0.05, time * 0.05) * 400.0;  // rotate +- 400deg
    // https://www.reddit.com/r/gamedev/comments/4y23pn/how_do_i_generate_deterministic_noise_that/
    rY = ofSignedNoise(time * 0.03) * 400.0;
    rZ = ofSignedNoise(time * 0.09) * 400.0;
    offsetY += 0.2;
    if (offsetY > ofGetHeight()){
        offsetY = ofRandom(-500, -100);
    }
}
void snow::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 + offsetX, ofGetHeight()/2 + offsetY);
    ofScale(0.025, 0.025, 0.025);  // can be 3 dimensional
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    snowflake.draw(0 - snowflake.getWidth()/2, 0 - snowflake.getHeight()/2);
    // draw at new 0,0
    ofPopMatrix();
}
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    sound.load("Audio.wav");
    midX = ofGetWidth() / 2;
    midY = ofGetHeight() / 2;
    barOne = midX - 300;
    barTwo = midX + 500;
    rP = ofVec2f(650, 450);
    posFm = ofVec2f(200,350);
    yTrain = midY;
    gillsans.load("gillsans.ttf", 20);
    amaticr.load("amaticr.ttf", 19);
    title.load("amaticrBold.ttf", 22);
    // raindrop
    image.load("leavingNight.jpg");
    raindrop.load("Raindrop.png");
    picX = 0;
    picY = 0;
    picsizeX = ofGetWidth();
    picsizeY = ofGetHeight();
    
    // wall with photo
    mid = ofVec2f (ofGetWidth()/2,ofGetHeight()/2);
    photo.load("faceUse.png");
    
    // HEARTBREAK
    a = 50;
    b = 25;
    c = 100;
    d = 125;
    dir = 1;
    dist = 0;
    l1 = 50;
    x = midX;
    y = midY;
    yTwo = midY-a;
    xOne = midX;
    
    // GIRL ALONE
    girlX = ofGetWidth()/2;
    girlY = ofGetHeight()/2;
    girl = ofVec2f(girlX,girlY);
    hair = ofVec2f(girlX-180,girlY+20);
    
    // from night to morning
    z = 255;
    w = z;
    moonlight.load("moon.png");
    
    // cry face
    xFace = midX;
    yFace = midY;
    xPos = ofGetWidth()/2;
    xPosone = xPos;
    yPos = ofGetHeight()/2;

    // landscape
    landscape.load("Landscape_F.png");
    landX = 0-ofGetWidth()*3;
    
    //stamp moving on the wall
    stampAus.load("austria.jpg");
    stampChin.load("china.jpg");
    stampDnmk.load("danmark.jpg");
    stampFra.load("france.jpg");
    stampGre.load("greece.jpg");
    stampHgr.load("hungry.jpg");
    stampIta.load("italia.jpg");
    stampNeth.load("netherland.jpg");
    stampPol.load("poland.jpg");
    pic = ofVec2f (670,200);
    aus = ofVec2f (200,-50);
    chin = ofVec2f (500,50);
    dank = ofVec2f (0,0);
    fra = ofVec2f (200,50);
    gre = ofVec2f (700,50);
    hgr = ofVec2f (0,0);
    ita = ofVec2f (200,-50);
    neth = ofVec2f (700,50);
    pol = ofVec2f (0,0);
    
//   -----------  Snow  ---------
    snowX = midX;
    snowY = midY;
    ofSeedRandom();
    ml0.setup();
    ml1.setup();
    ml2.setup();
    ml3.setup();
    ml4.setup();
    ml5.setup();
    ml6.setup();
    ml7.setup();
    ml8.setup();
    ml9.setup();
    
//    ----------------------  Last Scene  --------------------
    increment = 3;
    person = ofVec2f(650, 450);
    portaG = ofVec2f(200,350);
    
//    ----------------  Writing  -----------
    wX = midX;
    wY = ofGetHeight();
    

}

//--------------------------------------------------------------
float inc = 0.5;
ofVec2f rpFinal;
float dirt;
float musictime;
void ofApp::update(){
    sec = ofGetElapsedTimef();
    musictime = ofGetFrameNum();
    if (musictime == 0){
    sound.play();
    }
    
//    ----------- TRAIN ----------
    inc += 0.007;
    barOne -= inc;
    barTwo -= inc;
    if (barOne+50 < 0){
        barOne = midX + 1000;
    }
    if (barTwo+50 < 0){
        barTwo =midX+1000;
    }
    dirt = 0.15;
    rP.x = ofMap(dirt, 0, 320, rP.x, 1700);
    posFm.x = ofMap(dirt, 0, 500, posFm.x, 1700);
    
//     ----------  Raindrop on Window ----------
    if (sec > 27.5) {
        midY += 0.6;
        picsizeX *= 0.9995;
        picsizeY *= 0.9995;
        picX = (ofGetWidth()-image.getWidth())/2;
        picY = (ofGetHeight()-image.getHeight())/2;
    }
    
//    -----------  Broken Heart  -----------
    if (sec > 66){
        yTwo += 0.3;
        distant = yTwo - y;
        if (distant >= c) {
            yTwo = y+c;
            x += 0.2;
            xOne -= 0.2;
        }
    }
    
//    -----------  Girl Alone  -------------
    if (sec > 92){
        girl.x = ofMap(girlX, 0, 150, girlX, girlX-3);
        hair.x = ofMap(girlX, 0, 150, girlX-180, girlX-180.75);
    }
    if (sec > 96){
        girl.x = ofMap(girlX, 0, 250, girlX-3, girlX+5);
        hair.x = ofMap(girlX, 0, 150, girlX-180.75, girlX-179.75);
    }
    if (sec > 101){
        girl.x = ofMap(girlX, 0, 150, girlX+5, girlX);
        hair.x = ofMap(girlX, 0, 150, girlX-179.5, girlX-180);
    }
//      ----------  All Night  --------------
    if (sec > 106){
        w -= 0.3;
        z -= 0.19;
    }
    
//    -----------  Cry Face  -----------------
    if (sec > 120){
        xPos-=0.5;
        if (xPos < girlX - 105){
            xPos = girlX;
        }
        xPosone+=0.5;
        if (xPosone > girlX + 105){
            xPosone = girlX;
        }
        yPos+=0.65;
        if (yPos > (ofGetHeight()/2+90)){
            yPos = girlY;
        }
    }
//    ----------  Landscape  ----------------
    if (sec > 130){
        landX +=3;
    }
//    ----------  Stamp  --------------------
    if (sec > 152){
//        pic.x = ofMap(10, 0, 10, 670, 1200);
        pic.y --;
        switch (direction) {
                
            case 1:
                aus.x--; //LEFT
                chin.x--;
                dank.x--;
                fra.x--;
                gre.x--;
                hgr.x--;
                ita.x--;
                neth.x--;
                pol.x--;
                break;
            case 2:
                aus.y--; // UP
                chin.y--;
                dank.y--;
                fra.y--;
                gre.y--;
                hgr.y--;
                ita.y--;
                neth.y--;
                pol.y--;
                break;
            case 3:
                aus.x++; //RIGHT
                chin.x++;
                dank.x++;
                fra.x++;
                gre.x++;
                hgr.x++;
                ita.x++;
                neth.x++;
                pol.x++;
                break;
            case 4:
                aus.y++; //DOWN
                chin.y++;
                dank.y++;
                fra.y++;
                gre.y++;
                hgr.y++;
                ita.y++;
                neth.y++;
                pol.y++;
                break;
            default:
                break;
        }
    }
    
//     ----------------  SNOW SCENE  --------------
    ml0.update();
    ml1.update();
    ml2.update();
    ml3.update();
    ml4.update();
    ml5.update();
    ml6.update();
    ml7.update();
    ml8.update();
    ml9.update();
    
//    -----------  Train LAST SCENE  -----------------
    if (sec > 230){
        increment -= 0.07;
        lsceneOne -= increment;
        lsceneTwo -= increment;
        if (lsceneOne+50 > ofGetWidth()){
            lsceneOne = midX - 1000;
        }
        if (lsceneTwo+50 > ofGetWidth()){
            lsceneTwo =midX - 1000;
        }
    }
    
//    ----------  LAST SCENE  ---------------
    if (sec > 242){
        wY -=0.8;
    }
    
}
void ofApp::opening(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    if (sec > 0) {
        amaticr.drawString("I always remember that day,", midX, midY);
    }
    if (sec > 1.5){
        amaticr.drawString("the day you were waving goodbye.", midX, midY+50);
    }
    if (sec > 3.5){
        amaticr.drawString("And I always remember you said", midX, midY+100);
    }
    if (sec > 5) {
        amaticr.drawString("'You always have a home here. We are all waiting for you'.", midX-3, midY+150);
    }
}

void ofApp::train(){
    if (sec > 9){
        ofBackground(255,255,255,180);
        ofSetColor(0, 0, 0);
        ofDrawRectangle(posFm, 230, 60);//Station Name
        ofDrawEllipse(rP, 30, 36);
        ofDrawRectangle(rP.x-10, rP.y+18, 20, 40);
        ofSetLineWidth(7);
        ofDrawLine(posFm.x+60, posFm.y+60, posFm.x+60, 535);
        ofDrawLine(posFm.x+170, posFm.y+60, posFm.x+170, 535);
        ofDrawLine(rP.x-5, rP.y+58, rP.x-12, rP.y+100);
        ofDrawLine(rP.x+4, rP.y+58, rP.x+4, rP.y+98);
        ofSetLineWidth(5);
        ofDrawLine(rP.x-10, rP.y+25, rP.x-16, rP.y+68);
        ofDrawLine(rP.x+10, rP.y+22, rP.x+18, rP.y+45);
        ofDrawLine(rP.x+18, rP.y+45, rP.x+22, rP.y+15);
        ofSetColor(255, 255, 255);
        gillsans.drawString("M. P.ta GARIBALDI", posFm.x+8, posFm.y+40);
        ofSetColor(0,0,0);
        ofDrawRectangle(0, 0, 1100, 100);
        ofDrawRectangle(barOne, 100, 50, 800); // bar one
        ofDrawRectangle(barTwo, 100, 50, 800); // bar two
        ofDrawRectangle(0, 700, 1100, 100);
        ofDrawRectangle(0, 250, 1800, 20);
        ofSetLineWidth(4);
        ofDrawLine(0, 550, 1700, 550); // Drawing the frame of the window
        ofSetColor(255, 255, 255);
    }
}

void ofApp::rain(){
    if (sec > 27){
    ofBackground(0,0,0);
    image.draw(picX,picY);
    image.resize(picsizeX, picsizeY);
    raindrop.draw(0, 0);
    ofSetColor (255,255,255);
    amaticr.drawString("and you,", midX-20, midY-250);
    amaticr.drawString("just like this familiar city,", midX-82, midY-200);
    amaticr.drawString("disappeared, ", midX-30, midY-150);
    amaticr.drawString("in a rainy night.", midX-48, midY-100);
    }
    if (sec > 45){
        title.drawString("L'ultima Canzone", midX-60, ofGetHeight()/3); // l'ultima canzone
    }
    if (sec > 47){
        amaticr.drawString("The Last Song", midX-40, ofGetHeight()/3+50);
    }
}
//--------------------------------------------------------------
void ofApp::emptyroom(){
    if (sec > 49){
        ofBackground(0, 0, 0);
    }
    if (sec > 52){
        ofBackground(251,233,238);
        ofSetColor(0, 0, 0);
        if (sec > 53.5)
            amaticr.drawString("My new place is an empty room,", ofGetWidth()/2-300, ofGetHeight()/2-270);
        if (sec > 55.5)
            amaticr.drawString("with walls in my favorite color,", ofGetWidth()/2-300, ofGetHeight()/2-220);
    }
    if (sec > 57.5){
        amaticr.drawString("a suitcase I traveled with,", ofGetWidth()/2-300, ofGetHeight()/2-170);
        ofSetColor(248, 252, 253);
        ofDrawRectangle(mid.x-280, mid.y+200, 10, 60);
        ofDrawRectangle(mid.x-230, mid.y+200, 10, 60);
        ofSetColor (13, 57, 73);//outside
        ofDrawRectRounded(mid.x-350, mid.y+260, 200, 150, 15);
        ofSetColor (34, 91, 111);
        ofDrawRectRounded(mid.x-330, mid.y+280, 160, 120, 10);
        ofDrawRectRounded(mid.x-285, mid.y+190, 70, 15, 5);
        ofSetColor (255,255,255);
    }
    if (sec > 59.5){
        ofSetColor(0, 0, 0);
        amaticr.drawString("and a photo of you.", ofGetWidth()/2-300, ofGetHeight()/2-120);
        ofSetColor (255, 255, 255);
        ofDrawRectangle(660,190,160,200); // Portrait Photo Frame
        photo.draw(670,200);
        photo.resize(140,180);
    }
}
void ofApp::brokenheart(){
        ofBackground(214,117,117);
        ofSetLineWidth(3.0);  // Line widths apply to polylines
        ofSetColor(255,230,230);
        ofPolyline closedHeart1, closedHeart2, heartBreak;
        closedHeart1.addVertex(x,y-a);
        closedHeart1.addVertex(x+c-b, y-c+b/2);
        closedHeart1.addVertex(x+d, y-a);
        closedHeart1.addVertex(x+c, y);
        closedHeart1.addVertex(x, y+c);
        closedHeart1.draw();
        closedHeart2.addVertex(xOne, y+c);
        closedHeart2.addVertex(xOne-c, y);
        closedHeart2.addVertex(xOne-d,y-a);
        closedHeart2.addVertex(xOne-c+b,y-c+b/2);
        closedHeart2.addVertex(xOne,y-a);
        closedHeart2.draw();
        ofDrawEllipse(x+a, y-a/2, a/2, a);
        ofDrawEllipse(xOne-a, y-a/2, a/2, a);
        ofSetColor(0, 0, 0);
        ofDrawEllipse(x+a, y-a/2, a/4, a/2);
        ofDrawEllipse(xOne-a, y-a/2, a/4, a/2);
        ofSetColor(255, 255, 255);
        ofDrawLine(xOne,y-a,xOne, yTwo);
        ofDrawLine(x, y-a, x, yTwo);
}
void ofApp::girlalone(){
    ofBackground(251,233,238); // background pink as the photo wall scene
    // window
    ofSetColor(31,50,137);
    ofDrawRectangle(girlX-300, girlY - 240, 600, 400);
    // window frame
    ofSetColor (197,150,97);
    ofDrawRectangle(girlX-300, girlY -40, 600, 4); //horizontal
    ofDrawRectangle(girlX -100, girlY -240, 4, 400);
    ofDrawRectangle(girlX +100, girlY -240, 4, 400);
    ofDrawRectangle(girlX-320, girlY+160, 640, 15);
    // moon
    ofSetColor(236,234,190);
    ofDrawCircle(girlX + 200, girlY-150, 35);
    // girl shadow
    ofSetColor(231, 214, 188);
    ofDrawRectRounded(girlX- 195, girlY + 100, 10, 120, 70, 20, 20, 10, 10);
    ofSetColor(242, 249, 255); // dress
    ofDrawTriangle(girlX-185, girlY + 155, girlX-90, girlY + 155, girl.x -140, girlY +340);
    ofDrawTriangle(girlX -140, girlY + 105, girl.x-220, girlY + 390, girl.x - 60, girlY + 390); // MOVEMENT
    ofSetColor(69, 43, 3); //hair_MOVEMENT
    ofDrawRectRounded(hair.x, hair.y, 10, 90, 170, 40, 40, 25, 25);
}
void ofApp::allnight(){
    ofBackground(194, 213, 234);
    ofSetColor(9,15,41,w);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255,255,255,z);
    ofPushMatrix();
    ofScale(0.06, 0.06);
    moonlight.draw(1000, 700);
    ofPopMatrix();
    ofSetColor (86,51,13);
    ofDrawRectangle(girlX-100, girlY - 5, 200, 130);
    // window
    ofSetColor(188,166,173);
    ofDrawRectangle(girlX-90, girlY, 180, 120);
    // window frame
    ofSetColor (86,51,13);
    ofDrawRectangle(girlX-90, girlY +58, 180, 4); //horizontal
    ofDrawRectangle(girlX -35, girlY, 4, 120);
    ofDrawRectangle(girlX +35, girlY, 4, 120);
}
void ofApp::cry(){
    ofBackground(0,0,0);
    ofSetColor(214, 225, 240);
    ofDrawRectangle(girlX-160, girlY-90, 320, 180);
    ofSetColor(253,234,182);
    ofDrawCircle(girlX, girlY, 70);// Round Face + COLOR
    ofSetColor(255, 255, 255);
    ofDrawCircle(girlX-28, girlY-15, 21); //Left Eye Ball
    ofDrawCircle(girlX+28, girlY-15, 21); //Right Eye Ball
    ofSetColor(0, 0, 0);
    ofDrawCircle(girlX-28, girlY-15, 10.5); //Left Eye
    ofDrawCircle(girlX+28, girlY-15, 10.5); //Right Eye
    ofSetLineWidth(1.5);
    ofDrawLine(girlX, girlY+8, girlX, girlY+30); //Nose
    ofDrawLine(girlX-15, girlY+40, girlX+15, girlY+40); // Mouth (The Neutral Face)
    ofSetColor(68, 178, 201);
    ofDrawEllipse(xFace-25, yPos-20, 6, 9);
    ofDrawEllipse(xFace-45, yPos-20, 6, 9);
    ofDrawEllipse(xFace+25, yPos-20, 6, 11);
    ofDrawEllipse(xFace+45, yPos-20, 6, 11);
    ofDrawCircle(xPos-40, girlY-15, 5);
    ofDrawCircle(xPosone+40, girlY-15, 5);
    ofSetColor(214, 225, 240);
}

void ofApp::travel(){
    ofBackground(0,0,0);
    ofSetColor(255,255,255);
    landscape.draw(landX, 0+ofGetHeight()*0.13);
    landscape.resize(ofGetWidth()*3, ofGetHeight()*0.8);
    ofSetColor(0,0,0);
    ofDrawRectangle(0, 0, 1100, 100);
    ofDrawRectangle(midX-410, 100, 50, 800); // bar one
    ofDrawRectangle(midX+355, 100, 50, 800); // bar two
    ofDrawRectangle(0, 700, 1100, 100);
    ofDrawRectangle(0, 250, 1800, 5);
}
void ofApp::stampwall(){
    ofBackground(251,233,238);
    ofSetColor (255, 255, 255);
    ofDrawRectangle(pic.x-10,pic.y-10,160,200); // Portrait Photo Frame
    photo.draw(pic);
    photo.resize(140,180);
    ofSetColor (0,0,0);
    if (sec > 152 && sec < 160) {
        amaticr.drawString("I started to forget,",girlX-350, girlY-270);
    }
    if (sec > 154 && sec < 160) {
        amaticr.drawString("the face you,",girlX-350, girlY-220);
    }
    if (sec > 156 && sec < 160) {
        amaticr.drawString("the imagery of home,",girlX-350, girlY-170);
    }
    if (sec > 158 && sec < 160) {
        amaticr.drawString("and the life in that city.",girlX-350, girlY-120);
    }
    if (sec > 160 && sec < 168) {
        amaticr.drawString("Use ARROW keys to move up, left, right, down.", girlX-400, girlY-200);
        amaticr.drawString("Press the Initial Letter of the Origin (Country) of the Stamp", girlX-400, girlY-150);
        amaticr.drawString("Find out where I travelled to in 50s :)", girlX-400, girlY-100);
    }
    
    if (sec > 166){
        ofSetColor (255,255,255,100);
        ofDrawRectangle(600,200,170,170);
        ofSetColor (255,255,255);
        
    }
    if (sec > 168) {
        stampAus.draw(aus.x,aus.y);
        stampAus.resize(150, 150);
    }
    if (pressA){
        aus = ofVec2f(610,210);
    }
    if (aus == ofVec2f(610,210)){
        ofDrawRectangle(300, 500, 120, 170);
        stampChin.resize(100,150);
        stampChin.draw(chin.x,chin.y);
    }
    if (pressC){
        chin = ofVec2f (310,510);
    }
    if (chin == ofVec2f (310,510)) {
        ofDrawRectangle(200, 100, 170, 230);
        stampDnmk.resize(150, 210);
        stampDnmk.draw(dank.x, dank.y);
    }
    if (pressD){
        dank = ofVec2f(210,110);
    }
    if (dank == ofVec2f(210,110)) {
        ofDrawRectangle(50, 400, 150, 110);
        stampFra.resize(140, 100);
        stampFra.draw(fra.x, fra.y);
    }
    if (pressF) {
        fra = ofVec2f (55,405);
    }
    if (fra == ofVec2f (55,405)) {
        ofDrawRectangle(395, 280, 185, 130);
        stampGre.resize(175, 120);
        stampGre.draw(gre.x,gre.y);
    }
    if (pressG) {
        gre = ofVec2f (400,285);
    }
    if (gre == ofVec2f (400,285)) {
        ofDrawRectangle(700, 460, 160, 120);
        stampHgr.resize(140, 100);
        stampHgr.draw(hgr.x, hgr.y);
    }
    if (pressH) {
        hgr = ofVec2f(710,470);
    }
    if (hgr == ofVec2f(710,470)) {
        ofDrawRectangle(500, 450, 155, 260);
        stampIta.resize(135, 240);
        stampIta.draw(ita.x, ita.y);
    }
    if (pressI) {
        ita = ofVec2f (510,460);
    }
    if (ita == ofVec2f (510,460)) {
        ofDrawRectangle(218, 350, 160, 130);
        stampNeth.resize(150, 120);
        stampNeth.draw(neth.x, neth.y);
    }
    if (pressN) {
        neth = ofVec2f (223,355);
    }
    if (neth == ofVec2f (223,355)) {
        ofDrawRectangle(390, 35, 195, 160);
        stampPol.resize(175, 140);
        stampPol.draw(pol.x, pol.y);
    }
    if (pressP){
        pol = ofVec2f (400,45);
        cout << stampTime << endl;
    }
}
void ofApp::snow(){
    ofBackground(179,196,193); //change a color as the building color
    ofSetColor (86,51,13);
    ofDrawRectangle(snowX-220, snowY - 250, 440, 286);
    // window
    ofSetColor(188,166,173);
    ofDrawRectangle(snowX-200, snowY - 240, 400, 266);
    // window frame
    ofSetColor (86,51,13);
    ofDrawRectangle(snowX-200, snowY -107, 400, 4); //horizontal
    ofDrawRectangle(snowX -75, snowY -240, 4, 266);
    ofDrawRectangle(snowX +75, snowY -240, 4, 266);
    ofSetColor(255, 255, 255);
    ml0.draw();
    ml1.draw();
    ml2.draw();
    ml3.draw();
    ml4.draw();
    ml5.draw();
    ml6.draw();
    ml7.draw();
    ml8.draw();
    ml9.draw();
    ofSetColor(0, 0, 0);
    amaticr.drawString("Some years later,", snowX - 430, snowY+100);
    amaticr.drawString("in a gloomy afternoon，", snowX - 430, snowY+ 140);
    amaticr.drawString("I had a dream.", snowX - 430, snowY+ 180);
    amaticr.drawString("you were still there,", snowX - 430, snowY+ 220);
    amaticr.drawString("at the station.", snowX - 430, snowY+ 260);
    amaticr.drawString("The melody I had played", snowX - 225, snowY+ 100);
    amaticr.drawString("was playing again.", snowX - 225, snowY+ 140);
    amaticr.drawString("Nothing changed.", snowX - 225, snowY+ 180);
}
void ofApp::station(){
    ofBackground(255,255,255);
    if (sec > 232){
        ofSetColor(0,0,0);
        ofDrawRectangle(0, 0, 1100, 100);
        ofDrawRectangle(lsceneOne, 100, 50, 800); // bar one
        ofDrawRectangle(lsceneTwo, 100, 50, 800); // bar two
        ofDrawRectangle(0, 700, 1100, 100);
        ofDrawRectangle(0, 250, 1800, 20);
        ofSetLineWidth(4);
        ofDrawLine(0, 550, 1700, 550); // Drawing the frame of the window
    }
    if (sec > 238){
        ofSetColor(0, 0, 0);
        ofDrawRectangle(portaG, 230, 60);//Station Name
        ofDrawEllipse(person, 30, 36);
        ofDrawRectangle(person.x-10, person.y+18, 20, 40);
        ofSetLineWidth(7);
        ofDrawLine(portaG.x+60, portaG.y+60, portaG.x+60, 535);
        ofDrawLine(portaG.x+170, portaG.y+60, portaG.x+170, 535);
        ofDrawLine(person.x-5, person.y+58, person.x-12, person.y+100);
        ofDrawLine(person.x+4, person.y+58, person.x+4, person.y+98);
        ofSetLineWidth(5);
        ofDrawLine(person.x-10, person.y+25, person.x-16, person.y+68);
        ofDrawLine(person.x+10, person.y+22, person.x+18, person.y+45);
        ofDrawLine(person.x+18, person.y+45, person.x+22, person.y+15);
        ofSetColor(255, 255, 255);
        gillsans.drawString("M. P.ta GARIBALDI", portaG.x+8, portaG.y+40);
    }
}
void ofApp::draw(){
    cout << sec << endl;
    opening();
    train();
    rain();
    emptyroom();
    if (sec > 62){
        ofBackground(0, 0, 0);
        amaticr.drawString("I am used to international travels,", ofGetWidth()/2-135, ofGetHeight()/2);
    }
    if (sec > 64) {
        ofBackground(0, 0, 0);
        amaticr.drawString("But, not this empty room.", ofGetWidth()/2-100, ofGetHeight()/2);
    }
    if (sec > 66){
    brokenheart();
        if (sec > 79) {
            amaticr.drawString("I miss", ofGetWidth()/2-15, ofGetHeight()/2-40);
        }
        if (sec > 81.5){
            amaticr.drawString("The red wall in my room.", ofGetWidth()/2-75, ofGetHeight()/2);
        }
        if (sec > 84.5){
            amaticr.drawString("The sound of the moka pot in the morning.", ofGetWidth()/2-135, ofGetHeight()/2+40);
        }
        if (sec > 87){
            title.drawString("......", ofGetWidth()/2-15, ofGetHeight()/2+80);
        }
        if (sec > 87.5){
            amaticr.drawString("I miss home.", ofGetWidth()/2-30, ofGetHeight()/2+120);
        }
    }
    if (sec > 90){
        girlalone();
    }
    if (sec > 105){
        allnight();
        if (sec > 108){
            amaticr.drawString("And now, standing ,looking at the moon, thinking of my distant home", ofGetWidth()/2-200, ofGetHeight()-80);
        }
    }
    if (sec > 120){
        cry();
    }
    if (sec > 126){
        amaticr.drawString("I left this empty room. On the journey agian.", ofGetWidth()/2-150, ofGetHeight()-80);
    }
    if (sec > 130){
        travel();
    }
    if (sec > 152){
        stampwall();
    }
    if (sec > 222){
        snow();
    }
    if (sec > 230){
        station();
    }
    if (sec > 242){
        // writing
        ofBackground(0, 0, 0);
        ofSetColor(255, 255, 255);
        amaticr.drawString("After almost three years,", wX-75, wY-100);
        amaticr.drawString("I went back to Milano.", wX-70, wY-60);
        amaticr.drawString("I forgot how to use the keys.", wX-85, wY);
        amaticr.drawString("I took the wrong train back home.", wX-108, wY+40);
        amaticr.drawString("I forgot the 'secret' roads to walk around in the center.", wX-180, wY+80);
        amaticr.drawString("The bakery shop I used to go in the morning was gone.", wX-165, wY+120);
        amaticr.drawString("But,", wX-15, wY+180);
        amaticr.drawString("when I heard my host mom saying", wX-100, wY+220);
        amaticr.drawString("'Home is always home. Nothing changes too much.'", wX-155, wY+260);
        amaticr.drawString("I knew I was at home.", wX-65, wY+300);
        title.drawString("HOME IS ALWAYS HOME.", wX-70, wY+380);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT) direction = 1; //move left
    if(key == OF_KEY_UP) direction = 2; //move up
    if(key == OF_KEY_RIGHT) direction = 3; //move right
    if(key == OF_KEY_DOWN) direction = 4; //move down
    if(key == 'a') pressA = true;
    if(key == 'c') pressC = true;
    if(key == 'd') pressD = true;
    if(key == 'f') pressF = true;
    if(key == 'g') pressG = true;
    if(key == 'h') pressH = true;
    if(key == 'i') pressI = true;
    if(key == 'n') pressN = true;
    if(key == 'p') pressP = true;
//        stampTime = ofGetElapsedTimef();

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
