void mode0 () {
    dht.begin();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Initializing...");
    float humi = dht.readHumidity();
    float temp = dht.readTemperature();
    lcd.clear();

    mode = 1;
}