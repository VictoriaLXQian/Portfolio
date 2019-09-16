#include "ofApp.h"
using namespace std;
ofColor color, cold, hot, day, night, uv;
float milanHigh,milanLow,milanCurrent,milanUv;
float minnHigh,minnLow,minnCurrent,minnUv;
float nycHigh, nycLow, nycCurrent,nycUv, nycForlow, nycForhigh;
float ncHigh, ncLow, ncCurrent,ncUv;
float hkgHigh, hkgLow, hkgCurrent, hkgUv;
float x; // x is a constant to transfer to the scale of the screen
bool nycX, nycY;
bool ncX, ncY;
bool milanX, milanY;
bool hkgX, hkgY;
bool minnX, minnY;
float nycAver;
float nycTime, nycSunrise, nycSunset,nycStart,nycEnd;
float ncTime, ncSunrise, ncSunset;
float hkgTime, hkgSunrise, hkgSunset;
float milanTime, milanSunrise, milanSunset;
float minnTime, minnSunrise, minnSunset;
int y;
ofTrueTypeFont gillsans;

//--------------------------------------------------------------
void ofApp::setup(){
    gillsans.load("gillsans.ttf", 12);
    std::string urlMilan = "YOUR API KEY";
    std::string urlMinneapolis = "YOUR API KEY";
    std::string urlNyc = "YOUR API KEY";
    std::string urlNc = "YOUR API KEY";
    std::string urlHkg = "YOUR API KEY";
    bool milan = jsonMilan.open(urlMilan);
    bool minneapolis = jsonMinn.open(urlMinneapolis);
    bool nyc = jsonNyc.open(urlNyc);
    bool nc = jsonNc.open(urlNc);
    bool hkg = jsonHkg.open(urlHkg);
    nycLow = (((jsonNyc["daily"]["data"][0]["temperatureLow"].asFloat())-32)*5)/9;
    nycHigh = (((jsonNyc["daily"]["data"][0]["temperatureHigh"].asFloat())-32)*5)/9;
    nycCurrent = (((jsonNyc["currently"]["temperature"].asFloat())-32)*5)/9;
    nycUv = jsonNyc["daily"]["data"][0]["uvIndex"].asFloat();
    nycTime = jsonNyc["currently"]["time"].asFloat();
    nycSunrise = jsonNyc["daily"]["data"][0]["sunriseTime"].asFloat();
    nycSunset = jsonNyc["daily"]["data"][0]["sunsetTime"].asFloat();
    nycStart =jsonNyc["daily"]["data"][0]["time"].asFloat();
    nycEnd =jsonNyc["daily"]["data"][1]["time"].asFloat();
    gui.setup();
    gui.add(tempLow.setup("tempLow",nycLow,-50,50));
    gui.add(tempHigh.setup("tempHigh",nycHigh,-50,50));
    gui.add(tempCurrent.setup("tempCurrent",nycCurrent,-50,50));
    gui.add(uvIndex.setup("uvIndex",nycUv,0,10));
    gui.add(nycTime.setup("currentTime",nycTime,nycStart,nycEnd));
    gui.add(read.setup("aboutThis"));

}
//--------------------------------------------------------------

void ofApp::update(){
    x = ofGetScreenWidth()/50;
    milanCurrent = (((jsonMilan["currently"]["temperature"].asFloat())-32)*5)/9;
    milanLow = (((jsonMilan["daily"]["data"][y]["temperatureLow"].asFloat())-32)*5)/9;
    milanHigh = (((jsonMilan["daily"]["data"][y]["temperatureHigh"].asFloat())-32)*5)/9;
    milanUv = jsonMilan["daily"]["data"][0]["uvIndex"].asFloat();
    milanTime = jsonMilan["currently"]["time"].asFloat();
    milanSunrise = jsonMilan["daily"]["data"][0]["sunriseTime"].asFloat();
    milanSunset = jsonMilan["daily"]["data"][0]["sunsetTime"].asFloat();
    // milan
    
    minnLow = (((jsonMinn["daily"]["data"][0]["temperatureLow"].asFloat())-32)*5)/9;
    minnHigh = (((jsonMinn["daily"]["data"][0]["temperatureHigh"].asFloat())-32)*5)/9;
    minnCurrent = (((jsonMinn["currently"]["temperature"].asFloat())-32)*5)/9;
    minnUv = jsonMinn["daily"]["data"][0]["uvIndex"].asFloat();
    minnTime = jsonMinn["currently"]["time"].asFloat();
    minnSunrise = jsonMinn["daily"]["data"][0]["sunriseTime"].asFloat();
    minnSunset = jsonMinn["daily"]["data"][0]["sunsetTime"].asFloat();
    // minneapolis
    
    nycUv = jsonNyc["daily"]["data"][0]["uvIndex"].asFloat();
    nycAver = abs((tempLow+tempHigh)/100);
    // new york city
    
    ncLow = (((jsonNc["daily"]["data"][y]["temperatureLow"].asFloat())-32)*5)/9;
    ncHigh = (((jsonNc["daily"]["data"][y]["temperatureHigh"].asFloat())-32)*5)/9;
    ncCurrent = (((jsonNc["currently"]["temperature"].asFloat())-32)*5)/9;
    ncUv = jsonNc["daily"]["data"][0]["uvIndex"].asFloat();
    ncTime = jsonNc["currently"]["time"].asFloat();
    ncSunrise = jsonNc["daily"]["data"][0]["sunriseTime"].asFloat();
    ncSunset = jsonNc["daily"]["data"][0]["sunsetTime"].asFloat();
    // north carolina
    
    hkgLow = (((jsonHkg["daily"]["data"][y]["temperatureLow"].asFloat())-32)*5)/9;
    hkgHigh = (((jsonHkg["daily"]["data"][y]["temperatureHigh"].asFloat())-32)*5)/9;
    hkgCurrent = (((jsonHkg["currently"]["temperature"].asFloat())-32)*5)/9;
    hkgUv = jsonHkg["daily"]["data"][0]["uvIndex"].asFloat();
    hkgTime = jsonHkg["currently"]["time"].asFloat();
    hkgSunrise = jsonHkg["daily"]["data"][0]["sunriseTime"].asFloat();
    hkgSunset = jsonHkg["daily"]["data"][0]["sunsetTime"].asFloat();
    // hong kong
    
    cold = ofColor(44, 120, 227);
    hot = ofColor(245, 95, 29);
    day = ofColor(155,201,214);
    night = ofColor(20,72,131);
    uv = ofColor(255,0,0);
}
//-------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
    ofSetColor(122, 122, 122);
    for (float g = 0.2; g < 1.2; g += 0.2) {
        ofDrawRectangle(0, g*ofGetScreenHeight(), ofGetScreenWidth(), 0.5);
        ofDrawRectangle(g*ofGetScreenWidth(), 0, 0.5, ofGetScreenHeight());
        ofDrawRectangle((g-0.1)*ofGetScreenWidth(), 0, 0.2, ofGetScreenHeight());
    }
    ofSetColor(hot, 255*0.1);
    ofDrawBitmapString(5, 0.1*ofGetScreenWidth()+2, 15);
    ofSetColor(hot, 255*0.2);
    ofDrawBitmapString(10, 0.2*ofGetScreenWidth()+2, 15);
    ofSetColor(hot, 255*0.3);
    ofDrawBitmapString(15, 0.3*ofGetScreenWidth()+2, 15);
    ofSetColor(hot, 255*0.4);
    ofDrawBitmapString(20, 0.4*ofGetScreenWidth()+2, 15);
    ofSetColor(hot, 255*0.6);
    ofDrawBitmapString(30, 0.6*ofGetScreenWidth()+2, 15);
    ofSetColor(hot, 255*0.7);
    ofDrawBitmapString(35, 0.7*ofGetScreenWidth()+2, 15);
    ofSetColor(hot, 255*0.8);
    ofDrawBitmapString(40, 0.8*ofGetScreenWidth()+2, 15);
    ofSetColor(hot, 255*0.9);
    ofDrawBitmapString(45, 0.9*ofGetScreenWidth()+2, 15);
    ofSetColor(cold, 255*0.1);
    ofDrawBitmapString(-5, 0.9*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.2);
    ofDrawBitmapString(-10, 0.8*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.3);
    ofDrawBitmapString(-15, 0.7*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.4);
    ofDrawBitmapString(-20, 0.6*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.5);
    ofDrawBitmapString(-25, 0.5*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.6);
    ofDrawBitmapString(-30, 0.4*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.7);
    ofDrawBitmapString(-35, 0.3*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.8);
    ofDrawBitmapString(-40, 0.2*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    ofSetColor(cold, 255*0.9);
    ofDrawBitmapString(-45, 0.1*ofGetScreenWidth()-27, ofGetScreenHeight()-15);
    
    // NEW YORK CITY, NEW YORK
    ofSetColor(uv, 255*(uvIndex/10));
    ofDrawRectangle(ofGetScreenWidth()/2-35, 0.01*ofGetScreenHeight()-4, 70, 20);
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("New York", ofGetScreenWidth()/2-32,  0.02*ofGetScreenHeight()); //NYC
    if (tempLow >= 0 && tempHigh > 0) {
        color = hot;
        ofSetColor(color,255*nycAver);
        ofDrawRectangle(tempLow*x, 0.06*ofGetScreenHeight(), (tempHigh-tempLow)*x, 4);
    }
    if (tempHigh <= 0 && tempLow < 0) {
        color = cold;
        ofSetColor(color,255*nycAver);
        ofDrawRectangle(ofGetScreenWidth()-abs(tempLow)*x, 0.06*ofGetScreenHeight(), (abs(tempLow-tempHigh))*x, 4);
    }
    if (tempHigh >= 0 && tempLow <= 0) {
        ofSetColor(hot,(tempHigh/50)*255);
        ofDrawRectangle(0, 0.06*ofGetScreenHeight(), tempHigh*x, 4);
        ofSetColor(cold, ((abs(tempLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(tempLow))*x, 0.06*ofGetScreenHeight(), (abs(tempLow))*x, 4);
    }
    if (tempCurrent == 0) {
        ofSetColor(127, 127, 127);
        ofDrawCircle(0, 0.06*ofGetScreenHeight(), 6);
        ofDrawCircle(ofGetScreenWidth(), 0.06*ofGetScreenHeight(), 6);
    }else if (tempCurrent > 0) {
        ofSetColor(hot,255*(tempCurrent/50));
        ofDrawCircle(tempCurrent*x, 0.06*ofGetScreenHeight(), 3);
    }else if (tempCurrent < 0) {
        ofSetColor(cold,255*abs(tempCurrent/50));
        ofDrawCircle(ofGetScreenWidth()-abs(tempCurrent)*x, 0.06*ofGetScreenHeight(), 3);
    }
    float nycForecast [5] [2] = {
        {(((jsonNyc["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    
    for (int u = 0; u < 5; u++) {
        float nycFor = abs((nycForecast[u][0]+nycForecast[u][1])/100);
        float z=0.1;
        if (u == 0) {
            z = 0.1;
        } else if (u == 1){
            z = 0.12;
        } else if (u == 2){
            z = 0.14;
        } else if (u == 3){
            z = 0.16;
        } else if (u == 4){
            z = 0.18;
        }
        if (nycForecast[u][0] > 0 && nycForecast[u][1]>0) {
            color = hot;
            ofSetColor(color,255*nycFor);
            ofDrawRectangle(nycForecast[u][0]*x, z*ofGetScreenHeight(), (nycForecast[u][1]-nycForecast[u][0])*x, 2);
        }else if (nycForecast[u][0] < 0 && nycForecast[u][1]<0){
            color = cold;
            ofSetColor(color,255*nycFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(nycForecast[u][0]*x, z*ofGetScreenHeight(), (abs(nycForecast[u][0]-nycForecast[u][1]))*x, 2);
        }else if (nycForecast[u][1]>= 0 && nycForecast[u][0] <= 0){
            ofSetColor(hot,(nycForecast[u][1]/50)*255);
            ofDrawRectangle(0, z*ofGetScreenHeight(), nycForecast[u][1]*x, 2);
            ofSetColor(cold, ((abs(nycForecast[u][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(nycForecast[u][0]))*x, z*ofGetScreenHeight(), (abs(nycForecast[u][0]))*x, 2);
        }
    }
    if (nycSunrise<=nycTime && nycTime <= nycSunset) {
        ofSetColor(day);
    }else
        ofSetColor(night);
    if (nycX && nycY) {
        float g;
        if (tempLow > 0 && tempHigh > 0){
            g = 0.7;
        }else if(tempHigh < 0 && tempLow < 0){
            g = 0.2;
        }else
            g = 0.425;
        ofDrawRectangle(ofGetScreenWidth()*g, ofGetScreenHeight()*0.03, 280, 120);
        ofSetColor(255, 255, 255);
        std::string timezone = jsonNyc["timezone"].asString();
        std::string icon = jsonNyc["currently"]["icon"].asString();
        std::string summary = jsonNyc["daily"]["data"][0]["summary"].asString();
        gillsans.drawString("Timezone: ", ofGetScreenWidth()*g+15, (ofGetScreenHeight()*0.03)+25);
        gillsans.drawString(timezone, ofGetScreenWidth()*g+30, (ofGetScreenHeight()*0.03)+50);
        gillsans.drawString(icon, ofGetScreenWidth()*g+15, (ofGetScreenHeight()*0.03)+80); // change the position
        gillsans.drawString(summary, ofGetScreenWidth()*g+15, (ofGetScreenHeight()*0.03)+110); // change the position
    }
    
    // RALEIGH, NORTH CAROLINA
    float ncAver =abs((ncHigh+ncLow)/100);
    ofSetColor(uv, 255*(ncUv/10));
    ofDrawRectangle(ofGetScreenWidth()/2-32, 0.21*ofGetScreenHeight()-4, 64, 20);
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Raleigh", ofGetScreenWidth()/2-28,  0.22*ofGetScreenHeight()); //NC
    if (ncLow > 0 && ncHigh > 0) {
        color = hot;
        ofSetColor(color,255*ncAver);
        ofDrawRectangle(ncLow*x, 0.26*ofGetScreenHeight(), (ncHigh-ncLow)*x, 4);
    }
    if (ncHigh <= 0 && ncLow < 0) {
        color = cold;
        ofSetColor(color,255*ncAver);
        ofDrawRectangle(ofGetScreenWidth()-abs(ncLow)*x, 0.26*ofGetScreenHeight(), (abs(ncHigh-ncLow))*x, 4);
    }
    if (ncHigh >= 0 && ncLow <= 0) {
        ofSetColor(hot,(ncHigh/50)*255);
        ofDrawRectangle(0, 0.26*ofGetScreenHeight(), ncHigh*x, 4);
        ofSetColor(cold, ((abs(ncLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(ncLow))*x, 0.26*ofGetScreenHeight(), (abs(ncLow))*x, 4);
    }
    if (ncCurrent == 0) {
        ofSetColor(127, 127, 127);
        ofDrawCircle(0, 0.26*ofGetScreenHeight(), 6);
        ofDrawCircle(ofGetScreenWidth(), 0.26*ofGetScreenHeight(), 6);
    }else if (ncCurrent > 0) {
        ofSetColor(hot,255*(ncCurrent/50));
        ofDrawCircle(ncCurrent*x, 0.26*ofGetScreenHeight(), 3);
    }else if (ncCurrent < 0) {
        ofSetColor(cold,255*(ncCurrent/50));
        ofDrawCircle(ofGetScreenWidth()-abs(ncCurrent)*x, 0.26*ofGetScreenHeight(), 3);
    }
    float ncForecast [5] [2] = {
        {(((jsonNc["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    for (int w = 0; w < 5; w++) {
        float ncFor = abs((ncForecast[w][0]+ncForecast[w][1])/100);
        float u=0.3;
        if (w == 0) {
            u = 0.3;
        } else if (w == 1){
            u = 0.32;
        } else if (w == 2){
            u = 0.34;
        } else if (w == 3){
            u = 0.36;
        } else if (w == 4){
            u = 0.38;
        }
        if (ncForecast[w][0] > 0 && ncForecast[w][1]>0) {
            color = hot;
            ofSetColor(color,255*ncFor);
            ofDrawRectangle(ncForecast[w][0]*x, u*ofGetScreenHeight(), (ncForecast[w][1]-ncForecast[w][0])*x, 2);
        }else if (ncForecast[w][0] < 0 && ncForecast[w][1]<0){
            color = cold;
            ofSetColor(color,255*ncFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(ncForecast[w][0]*x, u*ofGetScreenHeight(), (abs(ncForecast[w][0]-ncForecast[w][1]))*x, 2);
        }else if (ncForecast[w][1]>= 0 && ncForecast[w][0] <= 0){
            ofSetColor(hot,(ncForecast[w][1]/50)*255);
            ofDrawRectangle(0, u*ofGetScreenHeight(), ncForecast[w][1]*x, 2);
            ofSetColor(cold, ((abs(ncForecast[w][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(ncForecast[w][0]))*x, u*ofGetScreenHeight(), (abs(ncForecast[w][0]))*x, 2);
        }
    }
    if (ncSunrise<=ncTime && ncTime <= ncSunset) {
        ofSetColor(day);
    }else
        ofSetColor(night);
    if (ncX && ncY) {
        float h;
        if (ncLow > 0 && ncHigh > 0){
            h = 0.7;
        }else if(ncHigh < 0 && ncLow < 0){
            h = 0.2;
        }else
            h = 0.425;
        ofDrawRectangle(ofGetScreenWidth()*h, ofGetScreenHeight()*0.23, 280, 120);
        ofSetColor(255, 255, 255);
        std::string timezone = jsonNc["timezone"].asString();
        std::string icon = jsonNc["currently"]["icon"].asString();
        std::string summary = jsonNc["daily"]["data"][0]["summary"].asString();
        gillsans.drawString("Timezone: ", ofGetScreenWidth()*h+15, (ofGetScreenHeight()*0.23)+25);
        gillsans.drawString(timezone, ofGetScreenWidth()*h+30, (ofGetScreenHeight()*0.23)+50);
        gillsans.drawString(icon, ofGetScreenWidth()*h+15, (ofGetScreenHeight()*0.23)+80); // change the position
        gillsans.drawString(summary, ofGetScreenWidth()*h+15, (ofGetScreenHeight()*0.23)+110); // change the position
    }
    
    // HONG KONG, CHINA
    float hkgAver =abs((hkgHigh+hkgLow)/100);
        color = hot;
        ofSetColor(color,255*hkgAver);
        ofDrawRectangle(hkgLow*x, 0.46*ofGetScreenHeight(), (hkgHigh-hkgLow)*x, 4);
        ofSetColor(color,255*(hkgCurrent/50));
        ofDrawCircle(hkgCurrent*x, 0.46*ofGetScreenHeight(), 3);
        ofSetColor(uv, 255*(hkgUv/10));
        ofDrawRectangle(ofGetScreenWidth()/2-39, 0.41*ofGetScreenHeight()-4, 78, 20);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Hong Kong", ofGetScreenWidth()/2-36,  0.42*ofGetScreenHeight()); //Twin cities

    // It is IMPOSSIBLE that Hong Kong is below 0 degree.

    float hkgForecast [5] [2] = {
        {(((jsonHkg["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    for (int e = 0; e < 5; e++) {
        float hkgFor = abs((hkgForecast[e][0]+hkgForecast[e][1])/100);
        float f=0.5;
        if (e == 0) {
            f = 0.5;
        } else if (e == 1){
            f = 0.52;
        } else if (e == 2){
            f = 0.54;
        } else if (e == 3){
            f = 0.56;
        } else if (e == 4){
            f = 0.58;
        }
        if (hkgForecast[e][0] > 0 && hkgForecast[e][1]>0) {
            color = hot;
            ofSetColor(color,255*hkgFor);
            ofDrawRectangle(hkgForecast[e][0]*x, f*ofGetScreenHeight(), (hkgForecast[e][1]-hkgForecast[e][0])*x, 2);
        }
    }
    if (hkgSunrise<=hkgTime && hkgTime <= hkgSunset) {
        ofSetColor(day);
    }else
        ofSetColor(night);
    if (hkgX && hkgY) {
        ofDrawRectangle(ofGetScreenWidth()*0.7, ofGetScreenHeight()*0.43, 280, 120);
        ofSetColor(255, 255, 255);
        std::string timezone = jsonHkg["timezone"].asString();
        std::string icon = jsonHkg["currently"]["icon"].asString();
        std::string summary = jsonHkg["daily"]["data"][0]["summary"].asString();
        gillsans.drawString("Timezone: ", ofGetScreenWidth()*0.7+15, (ofGetScreenHeight()*0.43)+25);
        gillsans.drawString(timezone, ofGetScreenWidth()*0.7+30, (ofGetScreenHeight()*0.43)+50);
        gillsans.drawString(icon, ofGetScreenWidth()*0.7+15, (ofGetScreenHeight()*0.43)+80); // change the position
        gillsans.drawString(summary, ofGetScreenWidth()*0.7+15, (ofGetScreenHeight()*0.43)+110); // change the position
    }
    
    // MILAN, ITALY
    float milanAver =abs((milanHigh+milanLow)/100);
    ofSetColor(uv, 255*(milanUv/10));
    ofDrawRectangle(ofGetScreenWidth()/2-22, 0.61*ofGetScreenHeight()-4, 44, 20);
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Milan", ofGetScreenWidth()/2-19,  0.62*ofGetScreenHeight()); //MILANO
    if (milanLow > 0 && milanHigh > 0) {
        color = hot;
        ofSetColor(color,255*milanAver);
        ofDrawRectangle(milanLow*x, 0.66*ofGetScreenHeight(), (milanHigh-minnLow)*x, 4);
    }
    if (milanHigh <= 0 && milanLow < 0) {
        color = cold;
        ofSetColor(color,255*milanAver);
        ofDrawRectangle(ofGetScreenWidth()-abs(milanLow)*x, 0.66*ofGetScreenHeight(), (abs(milanHigh-milanLow))*x, 4);
    }
    if (milanHigh >= 0 && milanLow <= 0) {
        ofSetColor(hot,(milanHigh/50)*255);
        ofDrawRectangle(0, 0.66*ofGetScreenHeight(), milanHigh*x, 4);
        ofSetColor(cold, ((abs(milanLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(milanLow))*x, 0.66*ofGetScreenHeight(), (abs(milanLow))*x, 4);
    }
    if (milanCurrent == 0) {
        ofSetColor(127, 127, 127);
        ofDrawCircle(0, 0.66*ofGetScreenHeight(), 6);
        ofDrawCircle(ofGetScreenWidth(), 0.66*ofGetScreenHeight(), 6);
    }else if (milanCurrent > 0) {
        ofSetColor(hot,255*(ncCurrent/50));
        ofDrawCircle(ncCurrent*x, 0.66*ofGetScreenHeight(), 3);
    }else if (milanCurrent < 0) {
        ofSetColor(cold,255*(ncCurrent/50));
        ofDrawCircle(ofGetScreenWidth()-abs(milanCurrent)*x, 0.66*ofGetScreenHeight(), 3);
    }
    float milanForecast [5] [2] = {
        {(((jsonMilan["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    for (int c = 0; c < 5; c++) {
        float milanFor = abs((milanForecast[c][0]+milanForecast[c][1])/100);
        float d=0.7;
        if (c == 0) {
            d = 0.7;
        } else if (c == 1){
            d = 0.72;
        } else if (c == 2){
            d = 0.74;
        } else if (c == 3){
            d = 0.76;
        } else if (c == 4){
            d = 0.78;
        }
        if (milanForecast[c][0] > 0 && milanForecast[c][1]>0) {
            color = hot;
            ofSetColor(color,255*milanFor);
            ofDrawRectangle(milanForecast[c][0]*x, d*ofGetScreenHeight(), (milanForecast[c][1]-milanForecast[c][0])*x, 2);
        }else if (milanForecast[c][0] < 0 && milanForecast[c][1]<0){
            color = cold;
            ofSetColor(color,255*milanFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(milanForecast[c][0]*x, d*ofGetScreenHeight(), (abs(milanForecast[c][0]-milanForecast[c][1]))*x, 2);
        }else if (milanForecast[c][1]>= 0 && milanForecast[c][0] <= 0){
            ofSetColor(hot,(milanForecast[c][1]/50)*255);
            ofDrawRectangle(0, d*ofGetScreenHeight(), milanForecast[c][1]*x, 2);
            ofSetColor(cold, ((abs(milanForecast[c][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(milanForecast[c][0]))*x, d*ofGetScreenHeight(), (abs(milanForecast[c][0]))*x, 2);
        }
    }
    if (milanSunrise<=milanTime && milanTime <= milanSunset) {
        ofSetColor(day);
    }else
        ofSetColor(night);
    if (milanX && milanY) {
        float k;
        if (milanLow > 0 && milanHigh > 0){
            k = 0.7;
        }else if(milanHigh < 0 && milanLow < 0){
            k = 0.2;
        }else
            k = 0.425;
        ofDrawRectangle(ofGetScreenWidth()*k, ofGetScreenHeight()*0.63, 280, 120);
        ofSetColor(255, 255, 255);
        std::string timezone = jsonMilan["timezone"].asString();
        std::string icon = jsonMilan["currently"]["icon"].asString();
        std::string summary = jsonMilan["daily"]["data"][0]["summary"].asString();
        gillsans.drawString("Timezone: ", ofGetScreenWidth()*k+15, (ofGetScreenHeight()*0.63)+25);
        gillsans.drawString(timezone, ofGetScreenWidth()*k+30, (ofGetScreenHeight()*0.63)+50);
        gillsans.drawString(icon, ofGetScreenWidth()*k+15, (ofGetScreenHeight()*0.63)+80); // change the position
        gillsans.drawString(summary, ofGetScreenWidth()*k+15, (ofGetScreenHeight()*0.63)+110); // change the position
    }
    
    // MINNEAPOLIS, MINNESOTA
    float minnAver =abs((minnHigh+minnLow)/100);
    ofSetColor(uv, 255*(minnUv/10));
    ofDrawRectangle(ofGetScreenWidth()/2-47, 0.81*ofGetScreenHeight()-4, 94, 20);
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Minneapolis", ofGetScreenWidth()/2-44,  0.82*ofGetScreenHeight()); //Twin cities
    if (minnLow > 0 && minnHigh > 0) {
        color = hot;
        ofSetColor(color,255*minnAver);
        ofDrawRectangle(minnLow*x, 0.86*ofGetScreenHeight(), (minnHigh-minnLow)*x, 4);
    }
    if (minnHigh <= 0 && minnLow < 0) {
        color = cold;
        ofSetColor(color,255*minnAver);
        ofDrawRectangle(ofGetScreenWidth()-abs(minnLow)*x, 0.86*ofGetScreenHeight(), (abs(minnHigh-minnLow))*x, 4);
    }
    if (minnHigh >= 0 && minnLow <= 0) {
        ofSetColor(hot,(minnHigh/50)*255);
        ofDrawRectangle(0, 0.86*ofGetScreenHeight(), minnHigh*x, 4);
        ofSetColor(cold, ((abs(minnLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(minnLow))*x, 0.86*ofGetScreenHeight(), (abs(minnLow))*x, 4);
    }
    if (minnCurrent == 0) {
        ofSetColor(127, 127, 127);
        ofDrawCircle(0, 0.86*ofGetScreenHeight(), 6);
        ofDrawCircle(ofGetScreenWidth(), 0.86*ofGetScreenHeight(), 6);
    }else if (minnCurrent > 0) {
        ofSetColor(hot,255*(minnCurrent/50));
        ofDrawCircle(minnCurrent*x, 0.86*ofGetScreenHeight(), 3);
    }else if (ncCurrent < 0) {
        ofSetColor(cold,255*(minnCurrent/50));
        ofDrawCircle(ofGetScreenWidth()-abs(minnCurrent)*x, 0.86*ofGetScreenHeight(), 3);
    }
    float minnForecast [5] [2] = {
        {(((jsonMinn["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    for (int a = 0; a < 5; a++) {
        float minnFor = abs((minnForecast[a][0]+minnForecast[a][1])/100);
        float b=0.9;
        if (a == 0) {
            b = 0.9;
        } else if (a == 1){
            b = 0.92;
        } else if (a == 2){
            b = 0.94;
        } else if (a == 3){
            b = 0.96;
        } else if (a == 4){
            b = 0.98;
        }
        if (minnForecast[a][0] > 0 && minnForecast[a][1]>0) {
            color = hot;
            ofSetColor(color,255*minnFor);
            ofDrawRectangle(minnForecast[a][0]*x, b*ofGetScreenHeight(), (minnForecast[a][1]-minnForecast[a][0])*x, 2);
        }else if (minnForecast[a][0] < 0 && minnForecast[a][1]<0){
            color = cold;
            ofSetColor(color,255*minnFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(minnForecast[a][0]*x, b*ofGetScreenHeight(), (abs(minnForecast[a][0]-minnForecast[a][1]))*x, 2);
        }else if (minnForecast[a][1]>= 0 && minnForecast[a][0] <= 0){
            ofSetColor(hot,(minnForecast[a][1]/50)*255);
            ofDrawRectangle(0, b*ofGetScreenHeight(), minnForecast[a][1]*x, 2);
            ofSetColor(cold, ((abs(minnForecast[a][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(minnForecast[a][0]))*x, b*ofGetScreenHeight(), (abs(minnForecast[a][0]))*x, 2);
        }
    }
    if (minnSunrise<=minnTime && minnTime <= minnSunset) {
        ofSetColor(day);
    }else
        ofSetColor(night);
    if (minnX && minnY) {
        float l;
        if (minnLow > 0 && minnHigh > 0){
            l = 0.7;
        }else if(minnHigh < 0 && minnLow < 0){
            l = 0.2;
        }else
            l = 0.425;
        ofDrawRectangle(ofGetScreenWidth()*l, ofGetScreenHeight()*0.83, 280, 120);
        ofSetColor(255, 255, 255);
        std::string timezone = jsonMinn["timezone"].asString();
        std::string icon = jsonMinn["currently"]["icon"].asString();
        std::string summary = jsonMinn["daily"]["data"][0]["summary"].asString();
        gillsans.drawString("Timezone: ", ofGetScreenWidth()*l+15, (ofGetScreenHeight()*0.83)+25);
        gillsans.drawString(timezone, ofGetScreenWidth()*l+30, (ofGetScreenHeight()*0.83)+50);
        gillsans.drawString(icon, ofGetScreenWidth()*l+15, (ofGetScreenHeight()*0.83)+80);
        gillsans.drawString(summary, ofGetScreenWidth()*l+15, (ofGetScreenHeight()*0.83)+110);
    }
    if (read) {
        ofSetColor(255,255,255);
        ofDrawRectangle(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
        ofSetColor(26, 84, 137);
        ofDrawRectangle(ofGetScreenWidth()/2-210, ofGetScreenHeight()/2-210, 423, 420);
        ofSetColor(255, 255, 255);
        float j = ofGetScreenWidth()/2-195;
        gillsans.drawString("HOW TO READ THIS", ofGetScreenWidth()/2-75, (ofGetScreenHeight()*0.5)-165);
        gillsans.drawString("This is a piece showing a five-day forecast at my five", ofGetScreenWidth()/2-170, (ofGetScreenHeight()*0.5)-130);
        gillsans.drawString("most frequently visited cities. The first city is where I am", j, (ofGetScreenHeight()*0.5)-105);
        gillsans.drawString("currently at, while the rest four places are in a order based", j, (ofGetScreenHeight()*0.5)-80);
        gillsans.drawString("on my travel frequency. A line is drawn from the lowest tem-", j, (ofGetScreenHeight()*0.5)-55);
        gillsans.drawString("-perature (in Celsius) to the highest temperature of a day.", j, (ofGetScreenHeight()*0.5)-30);
        gillsans.drawString("The current temperature is presented as a circle. The color", j, (ofGetScreenHeight()*0.5)-5);
        gillsans.drawString("of red and blue differenciates the temperature below or above", j, (ofGetScreenHeight()*0.5+20));
        gillsans.drawString("zero degree, while the coordinate axis mirrors itself furthur", j, (ofGetScreenHeight()*0.5)+45);
        gillsans.drawString("differenciates the temperature. The intensity of the backgr-", j, (ofGetScreenHeight()*0.5)+70);
        gillsans.drawString("-ound with the city name indicates the UV Index leve. If cl-", j, (ofGetScreenHeight()*0.5)+95);
        gillsans.drawString("-ick on the city, the color of the window suggests whether it", j, (ofGetScreenHeight()*0.5)+120);
        gillsans.drawString("is daytime or nighttime there with a little more detail of", j, (ofGetScreenHeight()*0.5)+145);
        gillsans.drawString("today's weather(including timezone, summary, etc.) written.", j, (ofGetScreenHeight()*0.5)+170);
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
    if (ofInRange(x, ofGetScreenWidth()/2-35, ofGetScreenWidth()/2+35)) nycX = true;
    if (ofInRange(y, 0.01*ofGetScreenHeight()-4, 0.01*ofGetScreenHeight()+16)) nycY = true;
    if (ofInRange(x, ofGetScreenWidth()/2-32, ofGetScreenWidth()/2+32)) ncX = true;
    if (ofInRange(y, 0.21*ofGetScreenHeight()-4, 0.21*ofGetScreenHeight()+16)) ncY = true;
    if (ofInRange(x, ofGetScreenWidth()/2-39, ofGetScreenWidth()/2+39)) hkgX = true;
    if (ofInRange(y, 0.41*ofGetScreenHeight()-4, 0.41*ofGetScreenHeight()+16)) hkgY = true;
    if (ofInRange(x, ofGetScreenWidth()/2-22, ofGetScreenWidth()/2+22)) milanX = true;
    if (ofInRange(y, 0.61*ofGetScreenHeight()-4, 0.61*ofGetScreenHeight()+16)) milanY = true;
    if (ofInRange(x, ofGetScreenWidth()/2-47, ofGetScreenWidth()/2+47)) minnX = true;
    if (ofInRange(y, 0.81*ofGetScreenHeight()-4, 0.81*ofGetScreenHeight()+16)) minnY = true;
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
