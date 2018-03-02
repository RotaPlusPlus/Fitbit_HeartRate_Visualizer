[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Fitbit_HeartRate_Visualizer
This repository contains servers and visualizers.

## Visualizer
It is currently under development as a sample in another repository.
https://github.com/Hiroki11x/openFrameworksSample/tree/master/oscReceiver

## Receiver
Server sequentially acquire heart rate data from fitbit on the python server and send it to openFrameworks project in OSC.
OSC transmission server for virtual data for debugging is also prepared.


#### For Debug (avoid HTTP Too Many Requests)
use
https://github.com/RotaPlusPlus/Fitbit_HeartRate_Visualizer/blob/master/sandbox/osc_sender_sample.py

```bash

$ python osc_sender_sample.py

```

then, type some integer.
the integer you input will be sent via OSC

#### For Release
use
https://github.com/RotaPlusPlus/Fitbit_HeartRate_Visualizer/blob/master/receiver/get_heart_rate.py

```bash

$ python get_heart_rate.py

```

Automatically, the heart rate acquired from fitbit as time series data is transmitted by OSC

## License
MIT
