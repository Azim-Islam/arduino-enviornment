import serial
import time
import streamlit as st

ser = serial.Serial('COM4', 9600, timeout=1)

time.sleep(2);

humidity, temperature, sound_level, dt, dh, ds = 0, 0, 0, 0, 0, 0

placeholder0 = st.empty()
placeholder1 = st.empty()
list_temp = []
list_hum = []
list_sound = []


while True:
    line = ser.readline().strip()
    if line:
        s1, s2, s3 = line.decode().split()
        dh = humidity - float(s1)
        humidity = float(s1)
        dt = temperature - float(s2)
        temperature = float(s2)
        ds = sound_level - float(s3)
        sound_level = float(s3)
        list_hum.append(humidity)
        list_temp.append(temperature)
        list_sound.append(sound_level)

    with placeholder0.container():
        c1, c2, c3 = st.columns(3)
        c1.metric(label="Temperature", value=f"{temperature} °C", delta=f"{dt} °C")
        c1.line_chart(list_temp)
        c2.metric(label="Humidity", value=f"{humidity} %", delta=f"{dh} %")
        c2.line_chart(list_hum)
        c3.metric(label="Sound Level", value=f"{sound_level} L", delta=f"{ds} L")
        c3.line_chart(list_sound)
