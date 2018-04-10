#include <AESLib_TIC.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//Serial.begin(57600);
//uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
//uint8_t key[]="smart_sprinkler_TIC_IoT_Control_Sprinkler";
uint8_t key[]="TI";
char data[] = "{\"event\":\"Update\",\"device_id\":\"10C4:EA60\",\"battery\":100,\"temperature\":26.5,\"moisture\":80}"; //16 chars == 16 bytes
Serial.println("Data leng:" + String(sizeof(data)));
aes128_enc_single(key, data);
Serial.print("encrypted:");
Serial.println(data);
aes128_dec_single(key, data);
Serial.print("decrypted:");
Serial.println(data);
char datamul[] = "{\"event\":\"Update\",\"device_id\":\"10C4:EA60\",\"battery\":100,\"temperature\":26.5,\"moisture\":80#12345}"; //16 chars == 16 bytes
Serial.println("Data leng:" + String(sizeof(datamul)));
Serial.print("encrypted multiple:");
aes128_enc_multiple(key, datamul, sizeof(datamul));
Serial.println(datamul);
aes128_dec_multiple(key, datamul, sizeof(datamul));
Serial.print("decrypted multiple:");
Serial.println(datamul);


//Serial.begin(57600);
char data256[] = "{\"event\":\"Update\",\"device_id\":\"10C4:EA60\",\"battery\":100,\"temperature\":26.5,\"moisture\":80}"; //16 chars == 16 bytes
uint8_t key256[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
//char data[] = "Thai test data encryption and decryption";
aes256_enc_single(key256, data256);
Serial.print("encrypted 256:");
Serial.println(data256);
aes256_dec_single(key256, data256);
Serial.print("decrypted 256:");
Serial.println(data256);
}

void loop() {
  // put your main code here, to run repeatedly:

}
