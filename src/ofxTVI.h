/*
 *  ofxTVI.h
 *  Touch Vision Interface
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

#define BORDER_SIZE	60

class ofxTVI {
public:
	ofxTVI();
	~ofxTVI();
	
	void setup(string ip_address);
	void draw();
	void kill();
	
	void setIPAddress(string ip_address);
	
protected:
	void keyPressed(ofKeyEventArgs & args);
	void update(ofEventArgs & args);
	void broadcast(int id);
	
	ofxTCPServer TCP;
	vector <string> storeText;
	
private:
	float _x;
	float _y;
	
	string _ip_address;
	bool _is_listening;
	
};

#endif
