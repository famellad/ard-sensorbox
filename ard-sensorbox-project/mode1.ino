void mode1 () {
    temp = dht.readTemperature();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    
    lcd.setCursor(3, 0);
    lcd.print((int)temp);

    lcd.setCursor(5, 0);
    lcd.write((byte)1);
}

void mode2 () {
    humi = dht.readHumidity();
    lcd.setCursor(0, 0);
    lcd.print("H:");
    
    lcd.setCursor(3, 0);
    lcd.print((int)humi);

    lcd.setCursor(5, 0);
    lcd.print("%");
}