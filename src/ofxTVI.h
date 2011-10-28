/*
 *  ofxTVI.h
 *  Touch Vision Interface server for a single screen
 *
 *  Created by Peter Nitsch on 30-09-11.
 *  Copyright 2011 Teehan+Lax Labs. All rights reserved.
 *
 */

#ifndef _OFX_TVI_CLIENT_
#define _OFX_TVI_CLIENT_

#include "ofMain.h"
#include "ofEvents.h"

#include "ofxNetwork.h"

#define OFX_TVI_BORDER_RATIO	0.03

#define OFX_TVI_COLOR_WHITE		0xffffff
#define OFX_TVI_COLOR_RED		0xff0000
#define OFX_TVI_COLOR_GREEN		0x00ff00
#define OFX_TVI_COLOR_BLUE		0x0000ff

class ofxTVI {
public:
	ofxTVI();
	~ofxTVI();
	
	void setup(int color);
	void draw();
	void kill();
	
	void setBorderColor(int color);
	int getBorderColor();
	
protected:
	void keyPressed(ofKeyEventArgs & args);
	void update(ofEventArgs & args);
	void broadcast(int id);
	
	ofxTCPServer TCP;
	vector <string> storeText;
	
private:
	float _x;
	float _y;
	
	int _border_color;
	int _border_size;
	
	bool _is_listening;
	
};

#endif
