/*
The MIT License (MIT)

Copyright (c) 2018 hikatech.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "ofMain.h"
#include "ofApp.h"

std::shared_ptr<ofAppGLFWWindow> getStereoGLFWWindow(ofGLFWWindowSettings &s) {

	shared_ptr<ofAppGLFWWindow> glfwWindow = shared_ptr<ofAppGLFWWindow>(new ofAppGLFWWindow());

	ofLogNotice() << "Try to setup STEREO-mode window";
	s.stereo = true;
	glfwWindow->setup(s);
	//if get error, setup MONO-mode window
	if (glfwWindow->getWidth() == 0) {
		ofLogNotice() << "Try to setup MONO-mode window";
		s.stereo = false;
		glfwWindow->setup(s);
	}

	//add window to mail loop for polling events
	ofGetMainLoop()->addWindow(glfwWindow);

	return glfwWindow;
}

//========================================================================
int main() {

	ofGLFWWindowSettings s;
	s.setPosition(ofVec2f(0, 0));
	s.width = 1280;
	s.height = 720;

	//get stereo-activated window if possible.
	auto glfwWindow = getStereoGLFWWindow(s); 

	std::shared_ptr<ofApp> app(new ofApp());

	ofRunApp(glfwWindow, app);
	ofRunMainLoop();
}

