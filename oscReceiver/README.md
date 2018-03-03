# Visualizer created by using openFrameworks


Edit `ofxSuperLog/src/ofxSuperLogDisplay.cpp` 
as bellow.

```diff
void ofxSuperLogDisplay::log(ofLogLevel level, const string & module, const string & message) {
	
	if(message.find('\n')==-1) {
-		 logLines.push_back(module + ": " + ofGetLogLevelName(level) + ": " + message);
+    logLines.push_back(message);
	} else {
		vector<string> lines = ofSplitString(message,"\n");
		for(int i = 0; i < lines.size(); i++) {
			if(i==0) {
-				logLines.push_back(module + ": " + ofGetLogLevelName(level) + ": " + lines[0]);
+       logLines.push_back(lines[0]);
			} else {
				logLines.push_back("\t" + lines[i]);
			}
		}
		
	}
	while(logLines.size()>MAX_NUM_LOG_LINES) {
		logLines.pop_front();
	}
  ```
