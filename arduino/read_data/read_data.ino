// Source from https://www.ioxhop.com/article/37/%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99%E0%B9%82%E0%B8%A1%E0%B8%94%E0%B8%B9%E0%B8%A5%E0%B8%AD%E0%B9%88%E0%B8%B2%E0%B8%99-rfid-%E0%B8%81%E0%B8%B1%E0%B8%9A-arduino-%E0%B9%81%E0%B8%9A%E0%B8%9A%E0%B8%87%E0%B9%88%E0%B8%B2%E0%B8%A2%E0%B9%86

#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
}
// -----------------Block of Last Name-----------------
int block=2;//block address of Last Name
byte readbackblock[18];//This array is used for reading out a block. The MIFARE_Read method requires a buffer that is at least 18 bytes to hold the 16 bytes of a block.

// -----------------Block of First Name-----------------
int block_fname=4;//block address of First Name 
byte readbackblock_fname[18];

// -----------------Block of AMKA-----------------
int block_amka=6;//block address of AMKA 
byte readbackblock_amka[18];

// -----------------Block of Blood Type-----------------
int block_blood=8;//block address of blood type 
byte readbackblock_blood[18];
// -----------------Block of Organ Donor-----------------
int block_don=10;//block address of organ donor
byte readbackblock_don[18];

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

  
  Serial.print("Tap card key: ");
  Serial.println(strID);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  //-----------------------------------------------------------------------------------------------------------
 /*****************************************establishing contact with a tag/card**********************************************************************/
        
    // Look for new cards (in case you wonder what PICC means: proximity integrated circuit card)
  if ( ! mfrc522.PICC_IsNewCardPresent()) {//if PICC_IsNewCardPresent returns 1, a new card has been found and we continue
    return;//if it did not find a new card is returns a '0' and we return to the start of the loop
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {//if PICC_ReadCardSerial returns 1, the "uid" struct (see MFRC522.h lines 238-45)) contains the ID of the read card.
    return;//if it returns a '0' something went wrong and we return to the start of the loop
  }

        
         
         Serial.println("card selected");
         Serial.println("");
         Serial.println("----------------------------");
 /***************************************** reading blocks on the card**********************************************************************/   
   
   //-----------------Read Last Name-----------------   
         readBlock(block, readbackblock);//read the block back
         Serial.print("Last Name: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock[j]);//Serial.write() transmits the ASCII numbers as human readable characters to serial monitor
         }
         Serial.println("");
         Serial.println("----------------------------");

   //----------------- Read First Name-----------------      
         
         readBlock(block_fname, readbackblock_fname);//read the block back
         Serial.print("First Name: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock_fname[j]);//Serial.write() transmits the ASCII numbers as human readable characters to serial monitor
         }
         Serial.println("");
         Serial.println("----------------------------");

   //----------------- Read AMKA-----------------      
         readBlock(block_amka, readbackblock_amka);//read the block back
         Serial.print("AMKA: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock_amka[j]);
         }
         Serial.println("");
         Serial.println("----------------------------");
         
   //----------------- & Read Blood Type-----------------      
        
         readBlock(block_blood, readbackblock_blood);//read the block back
         Serial.print("blood type: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock_blood[j]);
         }
         Serial.println("");
         Serial.println("----------------------------");
 

   //----------------- Read Donor-----------------      
         
         readBlock(block_don, readbackblock_don);//read the block back
         Serial.print("Organ Donor: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock_don[j]);
         }
         Serial.println("");
         Serial.println("----------------------------");
 
         
}

int readBlock(int blockNumber, byte arrayAddress[]) 
{
  int largestModulo4Number=blockNumber/4*4;
  int trailerBlock=largestModulo4Number+3;//determine trailer block for the sector

  /*****************************************authentication of the desired block for access***********************************************************/
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  //byte PCD_Authenticate(byte command, byte blockAddr, MIFARE_Key *key, Uid *uid);
  //this method is used to authenticate a certain block for writing or reading
  //command: See enumerations above -> PICC_CMD_MF_AUTH_KEY_A = 0x60 (=1100000),    // this command performs authentication with Key A
  //blockAddr is the number of the block from 0 to 15.
  //MIFARE_Key *key is a pointer to the MIFARE_Key struct defined above, this struct needs to be defined for each block. New cards have all A/B= FF FF FF FF FF FF
  //Uid *uid is a pointer to the UID struct that contains the user ID of the card.
  if (status != MFRC522::STATUS_OK) {
         Serial.print("PCD_Authenticate() failed (read): ");
         Serial.println(mfrc522.GetStatusCodeName(status));
         return 3;//return "3" as error message
  }
  //it appears the authentication needs to be made before every block read/write within a specific sector.
  //If a different sector is being authenticated access to the previous one is lost.


  /*****************************************reading a block***********************************************************/
        
  byte buffersize = 18;//we need to define a variable with the read buffer size, since the MIFARE_Read method below needs a pointer to the variable that contains the size... 
  status = mfrc522.MIFARE_Read(blockNumber, arrayAddress, &buffersize);//&buffersize is a pointer to the buffersize variable; MIFARE_Read requires a pointer instead of just a number
  if (status != MFRC522::STATUS_OK) {
          Serial.print("MIFARE_read() failed: ");
          Serial.println(mfrc522.GetStatusCodeName(status));
          return 4;//return "4" as error message
  }
  Serial.println("block was read");
}

