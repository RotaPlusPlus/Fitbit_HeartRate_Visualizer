[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Fitbit_HeartRate_Visualizer
This repository contains servers and visualizers.

## Visualizer
https://github.com/RotaPlusPlus/Fitbit_HeartRate_Visualizer/tree/master/oscReceiver

```diff
├── Makefile
├── Project.xcconfig
├── bin
│   ├── data
│   └── oscReceiverDebug.app
├── manager
│   ├── FontManager.cpp
│   ├── FontManager.hpp
│   ├── MacroManager.cpp
│   ├── MacroManager.hpp
│   ├── OSCManager.cpp
│   └── OSCManager.hpp
├── model
│   ├── HeartRate.cpp
│   └── HeartRate.hpp
├── openFrameworks-Info.plist
├── oscReceiver.xcodeproj
│   ├── project.pbxproj
│   ├── project.xcworkspace
│   ├── xcshareddata
│   └── xcuserdata
├── src
│   ├── main.cpp
│   ├── ofApp.cpp
│   └── ofApp.h
+└── view
+    ├── CardiogramBackgroundView.cpp
+    ├── CardiogramBackgroundView.hpp
+    ├── ElectroCardiogramView.cpp
+    └── ElectroCardiogramView.hpp
```

## Receiver
Server sequentially acquire heart rate data from fitbit on the python server and send it to openFrameworks project in OSC.
OSC transmission server for virtual data for debugging is also prepared.


#### For Debug (avoid HTTP Too Many Requests)
use
https://github.com/RotaPlusPlus/Fitbit_HeartRate_Visualizer/blob/master/sandbox/osc_sender_sample.py

```bash

$ python osc_sender_sample.py
ip:127.0.0.1, port:8002, address:/data
[16:40:42]  heart_rate : 91
[16:40:44]  heart_rate : 93
[16:40:46]  heart_rate : 86
[16:40:48]  heart_rate : 89
[16:40:50]  heart_rate : 89
[16:40:52]  heart_rate : 87
[16:40:54]  heart_rate : 94
[16:40:56]  heart_rate : 97
```

then, type some integer.
the integer you input will be sent via OSC

#### For Release
use
https://github.com/RotaPlusPlus/Fitbit_HeartRate_Visualizer/blob/master/receiver/get_heart_rate.py

```bash

$ python get_heart_rate.py
DATE : 2018-02-26
CLIENT_ID = XXXXX
CLIENT_SECRET = XXXXXXXXXX
ACCESS_TOKEN = XXXXXXXXXX
REFRESH_TOKEN = XXXXXXXXXX
ip:127.0.0.1, port:8002, address:/data
update_time: ['16:55:01']
=== new updated value ===
                         time  value
2018-02-26 16:55:01  16:55:01    115
update_time: ['16:55:01']
update_time: ['16:55:01']
update_time: ['16:55:08']
=== new updated value ===
                         time  value
2018-02-26 16:55:08  16:55:08    115
update_time: ['16:55:08']
update_time: ['16:55:08']
update_time: ['16:55:08']
update_time: ['16:55:08']
update_time: ['16:55:08']
update_time: ['16:55:08']
update_time: ['16:55:08']
update_time: ['16:55:08']
update_time: ['16:55:23']
=== new updated value ===
                         time  value
2018-02-26 16:55:23  16:55:23    115
update_time: ['16:55:23']
update_time: ['16:55:23']
update_time: ['16:55:38']
=== new updated value ===
                         time  value
2018-02-26 16:55:38  16:55:38    115
update_time: ['16:55:38']
^CExit with Ctrl+C / sys.exit(0) 
```

Automatically, the heart rate acquired from fitbit as time series data is transmitted by OSC

## LISENSE

Copyright 2018 Hiroki11x(Hiroki Naganuma)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## CONTRIBUTORS
- https://github.com/Hiroki11x
- https://github.com/ma286
- https://github.com/JunNishimura
