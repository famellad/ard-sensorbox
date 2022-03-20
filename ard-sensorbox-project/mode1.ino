void mode1 () {
    temp = dht.readTemperature();
    lcd.setCursor(0, 0);
    lcd.write((byte)2);
    
    lcd.setCursor(2, 0);
    lcd.print((int)temp);

    lcd.setCursor(4, 0);
    lcd.write((byte)1);
}

void mode2 () {
    humi = dht.readHumidity();
    lcd.setCursor(0, 0);
    lcd.write((byte)3);
    
    lcd.setCursor(2, 0);
    lcd.print((int)humi);

    lcd.setCursor(4, 0);
    lcd.print("%");
}
