// https://kelasrobot.com/cara-mudah-mengirim-pesan-dari-nodemcu-ke-telegram-telegrambot-part1/

#include <ESP8266WiFi.h>          //include ke nodemcu
#include <WiFiClientSecure.h>     //sembung ke client dengan secure
#include <UniversalTelegramBot.h> //include bot telegram
#define BUTTON D1

char ssid[] = "Wifi-Prabayar";                                   // nama wifi
char password[] = "bukanwifigratismas";                          // password wifi
#define BOTtoken "881663171:AAHnbbTVRqoP7XaF83_gtJvyXa53E0oApSE" // bottoken telegram
String chatid = "-286303573";                                    // chatid bot telegram
int switchState, buffer_ = 1;

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setup()
{
    Serial.begin(115200);
    WifiStatus();
    pinMode(BUTTON, INPUT_PULLUP); //baca pin sensor pintu

    delay(3000);                                         //jarak waktu pesan
    bot.sendMessage(chatid, "== Bot Terkoneksi ==\n> "); //pesan diserial
    Serial.println("\n\nSudah Siap Di Gunakan\n");       //pesan diserial
}

void loop()
{
    switchState = digitalRead(BUTTON);

    if (switchState == 1)
    {
        Serial.print("Pintu TERBUKA .... Nilai Sensor => "); //pesan diserial
        Serial.println(switchState);

        if (buffer_ == 0)
        {
            Serial.print("\n\t\t VALUE BERUBAH ");   //pesan diserial
            String data = "[+] Pintu TERBUKA \n>  "; //pesan diserial
            bot.sendMessage(chatid, data);
            Serial.println("\t\t Notif Telegram Terkirim\n "); //pesan diserial
        }

        buffer_ = 1;
        delay(1000); //jarak waktu pesan
    }
    else if (switchState == 0)
    {
        Serial.print("Pintu tertutup .... Nilai Sensor => "); //pesan diserial
        Serial.println(switchState);

        if (buffer_ == 1)
        {
            Serial.print("\n\t\t VALUE BERUBAH ");    //pesan diserial
            String data = "[-] Pintu TERTUTUP \n>  "; //pesan diserial
            bot.sendMessage(chatid, data);
            Serial.println("\t\t Notif Telegram Terkirim\n "); //pesan diserial
        }

        buffer_ = 0;
        delay(1000); //jarak waktu pesan
    }
}

void WifiStatus()
{
    WiFi.mode(WIFI_STA); //mode station
    WiFi.disconnect();
    delay(100);                        //jarak waktu
    Serial.print("Connecting Wifi: "); //pesan diserial
    Serial.println(ssid);
    WiFi.begin(ssid, password); //mulai connect ke wifi

    while (WiFi.status() != WL_CONNECTED) //jika belum connect akan mengirim notif terus sampai connect
    {
        Serial.print(".");
        delay(500); //jarak waktu
    }

    Serial.println("");
    Serial.println("WiFi connected"); //pesan diserial
    Serial.print("IP address: ");     //pesan diserial
    Serial.println(WiFi.localIP());   //pesan ip dari wifi
}