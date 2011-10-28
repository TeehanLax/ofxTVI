#include "ofxTVI.h"

ofxTVI::ofxTVI() {
	_is_listening = false;
}

ofxTVI::~ofxTVI(){
	if(_is_listening) kill();
}

void ofxTVI::setup(int color=0xffffff) {
	setBorderColor(color);
	
	TCP.setup(11999);
	TCP.setMessageDelimiter("\n");

	ofAddListener(ofEvents.update, this, &ofxTVI::update);
	ofAddListener(ofEvents.keyPressed, this, &ofxTVI::keyPressed);
	_is_listening = true;
}

void ofxTVI::setBorderColor(int color) {
	_border_color = color;
}

int ofxTVI::getBorderColor() {
	return _border_color;
}

void ofxTVI::draw() {
	_border_size = ofGetWidth() * OFX_TVI_BORDER_RATIO;
	
	ofFill();
	ofSetHexColor(_border_color);
	
	int h_size = (ofGetWidth() - (_border_size*2))/8;
	int v_size = (ofGetHeight() - (_border_size*2))/8;
	
	ofRect(0, 0, ofGetWidth(), _border_size);
	ofRect(ofGetWidth() - _border_size, _border_size, _border_size, ofGetHeight() - _border_size * 2);
	ofRect(0, ofGetHeight() - _border_size, ofGetWidth(), _border_size);
	ofRect(0, _border_size, _border_size, ofGetHeight() - _border_size * 2);
}

void ofxTVI::kill() {
	ofRemoveListener(ofEvents.update, this, &ofxTVI::update);
	ofRemoveListener(ofEvents.keyPressed, this, &ofxTVI::keyPressed);
	_is_listening = false;
}

void ofxTVI::keyPressed(ofKeyEventArgs & args){
	if(args.key == 27 && _is_listening) kill();	
}

void ofxTVI::update(ofEventArgs & args) {
	
	for(int i = 0; i < TCP.getLastID(); i++){
		if( !TCP.isClientConnected(i) ) continue;
		
		if(i >= storeText.size() ){
			storeText.push_back( string() );
		}
		
		string str = TCP.receive(i);
		
		if(str.length() > 0){
			storeText[i] = str;
			
			size_t separator = str.find(" ");
			
			float received_x = atof ( str.substr(0, separator).c_str() ); 
			float received_y = atof ( str.substr(separator+1, str.length()).c_str() ); 
			
			float translated_x = (float)ofGetWidth() * received_x;
			float translated_y = (float)ofGetHeight() * received_y;
			
			if(translated_x != 0 && translated_y !=0) {
				_x = translated_x;
				_y = translated_y;
				broadcast(i);
			}
		}

	}

}

void ofxTVI::broadcast(int id) {
	static ofTouchEventArgs touchEventArgs;  
	
	touchEventArgs.id = id;
	touchEventArgs.x = _x;  
	touchEventArgs.y = _y;    
	ofNotifyEvent( ofEvents.touchMoved, touchEventArgs ); 
}