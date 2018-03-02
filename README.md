# Fitbit_HeartRate_Visualizer

## For Debug (avoid HTTP Too Many Requests)
use
https://github.com/RotaPlusPlus/Fitbit_HeartRate_Visualizer/blob/master/sandbox/osc_sender_sample.py

```bash

$ python osc_sender_sample.py

```

then, type some integer.
the integer you input will be sent via OSC

## For Release
use
https://github.com/RotaPlusPlus/Fitbit_HeartRate_Visualizer/blob/master/receiver/get_heart_rate.py

```bash

$ python get_heart_rate.py

```

Automatically, the heart rate acquired from fitbit as time series data is transmitted by OSC
