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
        dh = float(s1) - sum(list_hum)/max(len(list_hum), 1)
        humidity = float(s1)
        dt = float(s2) - sum(list_temp)/max(len(list_temp), 1)
        temperature = float(s2)
        ds = float(s3) - sum(list_sound)/max(len(list_sound), 1)
        sound_level = float(s3)
        list_hum.append(humidity)
        list_temp.append(temperature)
        list_sound.append(sound_level)

    with placeholder0.container():
        c1, c2, c3 = st.columns(3)
        c1.metric(label="Temperature", value=f"{temperature} °C", delta=f"{dt:.2f} °C")
        c1.area_chart(list_temp)
        c2.metric(label="Humidity", value=f"{humidity} %", delta=f"{dh:.2f} %")
        c2.line_chart(list_hum)
        c3.metric(label="Sound Level", value=f"{sound_level} L", delta=f"{ds:.2f} L")
        c3.area_chart(list_sound)
