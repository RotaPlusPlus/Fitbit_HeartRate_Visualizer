import fitbit
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from ast import literal_eval
import time

# 用いるTokenについて
TOKEN_FILE  = "tokens.token"
ACCESS_TOKEN_FILE = "access.token"
CLIENT_ID = ""
CLIENT_SECRET = ""
ACCESS_TOKEN = ""
REFRESH_TOKEN = ""

# 取得したい日付
DATE = "2018-02-26"

# request token file が更新されるのでそれのupdater
def updateToken(token):
    f = open(TOKEN_FILE, 'w')
    f.write(str(token))
    f.close()
    return

def init():
    with open(ACCESS_TOKEN_FILE, "r") as f:  #token fileの読み込み
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

    # Refresh Token に関しては8時間しか有効でないので常に更新
    tokens = open(TOKEN_FILE).read()
    token_dict = literal_eval(tokens)
    # access_token = token_dict['access_token']
    REFRESH_TOKEN = token_dict['refresh_token']

    # ID等の設定
    authd_client = fitbit.Fitbit(CLIENT_ID, CLIENT_SECRET,access_token=ACCESS_TOKEN, refresh_token=REFRESH_TOKEN, refresh_cb = updateToken)

    return authd_client

# 繰り返すタスク
def task(authd_client):
    data_sec = authd_client.intraday_time_series('activities/heart', DATE, detail_level='1sec',start_time="15:45", end_time="16:00") #'1sec', '1min', or '15min'
    heart_sec = data_sec["activities-heart-intraday"]["dataset"]

    heart_df = pd.DataFrame.from_dict(heart_sec)
    heart_df.index = pd.to_datetime([DATE + " " + t for t in heart_df.time])
    heart_df = heart_df.drop("time", axis=1)
    print(heart_df[:10])

# 現在時刻が何秒更新されたか測定する関数
def get_updated_time():
    updated_time = time.asctime().split(" ")[3]
    return updated_time

# いろんな初期化を行う
client = init()

# main loop
while True:
    task(client)
    # print(time.asctime())　# Wed Feb 28 15:09:46 2018
    time.sleep(1)
