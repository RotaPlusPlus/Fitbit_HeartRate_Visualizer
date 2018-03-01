import fitbit
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

from ast import literal_eval

# 更新時間管理など
import datetime
import time

# Ctrl+Cで終了時の処理のため
import signal
import sys

# モジュール変数の定義
import config

# OSC関係のため
import argparse
from pythonosc import osc_message_builder
from pythonosc import udp_client

# 用いるTokenについて
TOKEN_FILE  = "tokens.token"
ACCESS_TOKEN_FILE = "access.token"
CLIENT_ID = ""
CLIENT_SECRET = ""
ACCESS_TOKEN = ""
REFRESH_TOKEN = ""

# 取得したい日付(今日に設定) e.g. "2018-02-26"
DATE = datetime.datetime.now().strftime( '%Y-%m-%d' )
print(DATE)

# Ctrl+Cで終了時の処理
def handler(signal, frame):
        print('Exit with Ctrl+C / sys.exit(0) ')
        # config.output_file.close()
        sys.exit(0)


# request token file が更新されるのでそれのupdater
def updateToken(token):
    f = open(TOKEN_FILE, 'w')
    f.write(str(token))
    f.close()
    return

def init_fitbit():
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

    # メモしたID等の確認用
    print("CLIENT_ID = {0}".format(CLIENT_ID))
    print("CLIENT_SECRET = {0}".format(CLIENT_SECRET))
    print("ACCESS_TOKEN = {0}".format(ACCESS_TOKEN))
    print("REFRESH_TOKEN = {0}".format(REFRESH_TOKEN))

    # ID等の設定
    authd_client = fitbit.Fitbit(CLIENT_ID, CLIENT_SECRET,access_token=ACCESS_TOKEN, refresh_token=REFRESH_TOKEN, refresh_cb = updateToken)

    return authd_client

def init_osc():
    parser = argparse.ArgumentParser()
    parser.add_argument("--ip", default="127.0.0.1", help="The ip of th OSC Server")
    parser.add_argument("--port", type=int, default=config.port_num, help="The port the OSC server is listening on")
    args = parser.parse_args()
    osc_client = udp_client.UDPClient(args.ip, args.port)

    # 設定のログ出し
    print("ip:127.0.0.1, port:" + str(config.port_num) + ", address:/data")
    return osc_client

# 繰り返すタスク
def task(authd_client, start_time="16:15", end_time="16:40", osc_client=None):
    data_sec = authd_client.intraday_time_series('activities/heart', DATE, detail_level='1sec',start_time=start_time, end_time=end_time) #'1sec', '1min', or '15min'
    heart_sec = data_sec["activities-heart-intraday"]["dataset"]

    # 取得データをDataFrameに変換
    heart_df = pd.DataFrame.from_dict(heart_sec)
    heart_df.index = pd.to_datetime([DATE + " " + t for t in heart_df.time])

    # 現在のFitbit更新時刻取得
    update_time = str(heart_df[-2:-1]["time"].get_values())

    # DEBUG
    print("update_time: " + update_time)

    # 現在のFitbit更新時刻がOSC最終更新時刻と違う場合にファイル書き出し
    if(update_time != config.last_update_time):
        latest_heart_rate = str(int(heart_df["value"][-2:-1]))

        # ファイル書き出し
        # config.output_file.write(latest_heart_rate+"\n")

        # OSCでメッセージ送信
        msg = osc_message_builder.OscMessageBuilder(address="/data")
        msg.add_arg(int(latest_heart_rate))
        msg = msg.build()
        osc_client.send(msg)

        # DEBUG
        print("=== new updated value ===")
        print(heart_df[-2:-1])

        # OSC最終更新時刻を更新
        config.last_update_time = str(heart_df[-2:-1]["time"].get_values())

# 現在時刻が何秒更新されたか測定する関数
# updated_time = time.asctime().split(" ")[3]
def get_updated_time():
    now = datetime.datetime.now()
    updated_now = now + datetime.timedelta(minutes=-30)
    updated_time = updated_now.strftime('%H:%M:%S')
    old_now = now + datetime.timedelta(minutes=-60)
    old_time = old_now.strftime('%H:%M:%S')
    return old_time, updated_time


# メインここから
if __name__ == '__main__':

    # Ctrl+C終了時のイベント検知
    signal.signal(signal.SIGINT, handler)

    # いろんな初期化を行う
    fitbit_client = init_fitbit()

    # OSC周りの初期化
    osc_client = init_osc()

    # 心拍数書き込みFileをopen
    # config.output_file = open('heart_rate.txt', mode = 'a', encoding = 'utf-8')

    # main loop
    while True:
        old_time, updated_time = get_updated_time()
        task(fitbit_client, old_time, updated_time, osc_client)
        time.sleep(1)
