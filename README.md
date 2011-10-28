# ofxTVI - TVI client addon for openFrameworks

Receives touch events from TVI device via TCP. TVI Android app coming soon.

## Usage

.h:

	ofxTVI tvi;
	int touchX;
	int touchY;

setup():

	tvi.setup( OFX_TVI_COLOR_WHITE );
	ofAddListener(ofEvents.touchMoved, this, &testApp::touchMoved);

Event handler:

	void testApp::touchMoved(ofTouchEventArgs &touch) {
		touchX = (int)touch.x;
		touchY = (int)touch.y;
	}

draw():

	ofCircle(touchX, touchY, 50);
	tvi.draw(); // draw border