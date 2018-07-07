#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(39);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofPoint star_point;
	float star_size;
	ofColor star_color;
	for (int i = 0; i < 1024; i++) {

		star_point = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
		star_size = ofRandom(5, 30) * ofNoise(star_point.x * 0.005, star_point.y * 0.005, ofGetFrameNum() * 0.008);
		star_color.setHsb(ofRandom(255), 200, 255);

		ofPushMatrix();
		ofTranslate(star_point);
		ofRotate(ofRandom(360));

		ofSetColor(star_color);
		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 36) {

			if (deg % 72 == 0) {

				ofVertex(star_size * 0.5 * cos(deg * DEG_TO_RAD), star_size * 0.5 * sin(deg * DEG_TO_RAD));
			}
			else {

				ofVertex(star_size * cos(deg * DEG_TO_RAD), star_size * sin(deg * DEG_TO_RAD));
			}
		}
		ofEndShape();

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}