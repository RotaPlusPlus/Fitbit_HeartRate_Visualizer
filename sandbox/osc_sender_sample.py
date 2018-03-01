import argparse

from pythonosc import osc_message_builder
from pythonosc import udp_client

# pip install python-osc

port_num = 8002

# セットアップ
parser = argparse.ArgumentParser()
parser.add_argument("--ip", default="127.0.0.1", help="The ip of th OSC Server")
parser.add_argument("--port", type=int, default=port_num, help="The port the OSC server is listening on")
args = parser.parse_args()
client = udp_client.UDPClient(args.ip, args.port)

# ip:127.0.0.1, port:8002, address:/filter
print("ip:127.0.0.1, port:" + str(port_num) + ", address:/data")

def main():
  print("type int:")
  input_str = input()
  msg = osc_message_builder.OscMessageBuilder(address="/data")
  msg.add_arg(int(input_str))
  print(input_str)
  msg = msg.build()
  client.send(msg)

if __name__ == "__main__":
  while True:
    main()
