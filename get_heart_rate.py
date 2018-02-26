import fitbit
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
# %matplotlib inline

CLIENT_ID=0
with open("access.token", "r") as f:  #token fileの読み込み
    for line in f:
        start_index=line.find("access_token")
        if start_index is 0:
            split_list = line.split()
            ACCESS_TOKEN = split_list[2]

        start_index=line.find("refresh_token")
        if start_index is 0:
            split_list = line.split()
            REFRESH_TOKEN = split_list[2]

        start_index=line.find("clientid")
        if start_index is 0:
            split_list = line.split()
            CLIENT_ID = split_list[2]

        start_index=line.find("clientsecret")
        if start_index is 0:
            split_list = line.split()
            CLIENT_SECRET = split_list[2]

# メモしたID等

print("CLIENT_ID = {0}".format(CLIENT_ID))
print("CLIENT_SECRET = {0}".format(CLIENT_SECRET))
print("ACCESS_TOKEN = {0}".format(ACCESS_TOKEN))
print("REFRESH_TOKEN = {0}".format(REFRESH_TOKEN))

# 取得したい日付
DATE = "2018-02-26"

# ID等の設定
authd_client = fitbit.Fitbit(CLIENT_ID, CLIENT_SECRET
                             ,access_token=ACCESS_TOKEN, refresh_token=REFRESH_TOKEN)
# 心拍数を取得（1秒単位）
data_sec = authd_client.intraday_time_series('activities/heart', DATE, detail_level='1sec') #'1sec', '1min', or '15min'
heart_sec = data_sec["activities-heart-intraday"]["dataset"]
heart_sec[:10]
