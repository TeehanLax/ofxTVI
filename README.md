# ofxTVI - Touch Vision Interface client addon for openFrameworks

Receives touch events from TVI device via TCP socket connection. **Android app coming soon**. For more information about TVI, [read our blog post](http://www.teehanlax.com/labs/tvi/).

## Sample Usage

.h:

	ofxTVI tvi;

	int touchX;
	int touchY;

.cpp:

	void testApp::setup(){
		ofSetFullscreen(true);
		ofSetVerticalSync(true);
		
		tvi.setup( OFX_TVI_COLOR_WHITE );
		ofAddListener(ofEvents.touchMoved, this, &testApp::touchMoved);
	}

	void testApp::draw(){
		ofBackground(0, 0, 0);
		
		ofSetColor(255, 0, 0);
		ofCircle(touchX, touchY, 50);
		
		tvi.draw();
	}

	void testApp::touchMoved(ofTouchEventArgs &touch) {
		touchX = (int)touch.x;
		touchY = (int)touch.y;
	}
