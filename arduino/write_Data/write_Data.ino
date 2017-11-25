
/******************************************
        PURPOSE:  Learn to use the MF522-AN RFID card reader 
  Created by      Rudy Schlaf for www.makecourse.com
  DATE:   2/2014
*******************************************/

/*
 * This sketch uses the MFRC522 Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND R BY COOQROBOT.
 * The library file MFRC522.h has a wealth of useful info. Please read it.
 * The functions are documented in MFRC522.cpp.
 *
 * Based on code Dr.Leong   ( WWW.B2CQSHOP.COM )
 * Created by Miguel Balboa (circuitito.com), Jan, 2012.
 * Rewritten by Søren Thing Andersen (access.thing.dk), fall of 2013 (Translation to English, refactored, comments, anti collision, cascade levels.)
 * 
 * This library has been released into the public domain.
*/


#include <SPI.h>//include the SPI bus library
#include <MFRC522.h>//include the RFID reader library

#define SS_PIN 10  //slave select pin
#define RST_PIN 5  //reset pin
MFRC522 mfrc522(SS_PIN, RST_PIN);        // instatiate a MFRC522 reader object.
MFRC522::MIFARE_Key key;//create a MIFARE_Key struct named 'key', which will hold the card information


void setup() {
        Serial.begin(9600);        // Initialize serial communications with the PC
        SPI.begin();               // Init SPI bus
        mfrc522.PCD_Init();        // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
        Serial.println("Scan a MIFARE Classic card");
        
        // Prepare the security key for the read and write functions - all six key bytes are set to 0xFF at chip delivery from the factory.
        // Since the cards in the kit are new and the keys were never defined, they are 0xFF
        // if we had a card that was programmed by someone else, we would need to know the key to be able to access it. This key would then need to be stored in 'key' instead.
 
        for (byte i = 0; i < 6; i++) {
                key.keyByte[i] = 0xFF;//keyByte is defined in the "MIFARE_Key" 'struct' definition in the .h file of the library
        }

}
// -----------------Block of Last Name-----------------
int block=2;//this is the block number we will write into and then read. Do not write into 'sector trailer' block, since this can make the block unusable.
byte blockcontent[16] = {"PAPADOPOULOS"};//an array with 16 bytes to be written into one of the 64 card blocks is defined!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//byte blockcontent[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//all zeros. This can be used to delete a block.
byte readbackblock[18];//This array is used for reading out a block. The MIFARE_Read method requires a buffer that is at least 18 bytes to hold the 16 bytes of a block.

// -----------------Block of First Name-----------------
int block_fname=4;//block address of First Name 
byte blockcontent_fname[16] = {"NIKOLAOS"};
//byte blockcontent_fname[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
byte readbackblock_fname[18];

// -----------------Block of AMKA-----------------
int block_amka=31;//block address of AMKA 
//byte blockcontent_amka[16] = {"123456789"};
byte blockcontent_amka[16] = {1,2,3,4,5,0,0,0,0,0,0,0,0,0,0,0};
byte readbackblock_amka[18];

// -----------------Block of Blood Type-----------------
int block_blood=12;//block address of AMKA 
byte blockcontent_blood[16] = {"A+"};
//byte blockcontent_blood[16] = {1,2,3,4,5,0,0,0,0,0,0,0,0,0,0,0};
byte readbackblock_blood[18];

void loop()
{

  
        /*****************************************establishing contact with a tag/card**********************************************************************/
        
    // Look for new cards (in case you wonder what PICC means: proximity integrated circuit card)
  if ( ! mfrc522.PICC_IsNewCardPresent()) {//if PICC_IsNewCardPresent returns 1, a new card has been found and we continue
    return;//if it did not find a new card is returns a '0' and we return to the start of the loop
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {//if PICC_ReadCardSerial returns 1, the "uid" struct (see MFRC522.h lines 238-45)) contains the ID of the read card.
    return;//if it returns a '0' something went wrong and we return to the start of the loop
  }

        // Among other things, the PICC_ReadCardSerial() method reads the UID and the SAK (Select acknowledge) into the mfrc522.uid struct, which is also instantiated
        // during this process.
        // The UID is needed during the authentication process
          //The Uid struct:
          //typedef struct {
    //byte    size;     // Number of bytes in the UID. 4, 7 or 10.
    //byte    uidByte[10];            //the user ID in 10 bytes.
    //byte    sak;      // The SAK (Select acknowledge) byte returned from the PICC after successful selection.
          //} Uid;
         
         Serial.println("card selected");
         
         /*****************************************writing and reading a block on the card**********************************************************************/
         
         
         //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
         
         
         
   
   //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));//uncomment this if you want to see the entire 1k memory with the block written into it.
   
   //-----------------Write & Read Last Name-----------------  
         writeBlock(block, blockcontent);  //the blockcontent array is written into the card block  
         readBlock(block, readbackblock);//read the block back
         Serial.print("Last Name: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock[j]);//Serial.write() transmits the ASCII numbers as human readable characters to serial monitor
         }
         Serial.println("");
         Serial.println("---------------");

   //-----------------Write & Read First Name-----------------      
         readBlock(block_fname, readbackblock_fname);//read the block back
         Serial.print("First Name: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock_fname[j]);//Serial.write() transmits the ASCII numbers as human readable characters to serial monitor
         }
         Serial.println("");

   //-----------------Write & Read AMKA-----------------      
         readBlock(block_amka, readbackblock_amka);//read the block back
         Serial.print("AMKA: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock_amka[j]);
         }
         Serial.println("");
   //-----------------Write & Read Blood Type-----------------      
         readBlock(block_blood, readbackblock_blood);//read the block back
         Serial.print("blood type: ");
         for (int j=0 ; j<16 ; j++)//print the block contents
         {
           Serial.write (readbackblock_blood[j]);
         }
         Serial.println("");

   
         
 
}

int writeBlock(int blockNumber, byte arrayAddress[]) 
{
  //this makes sure that we only write into data blocks. Every 4th block is a trailer block for the access/security info.
  int largestModulo4Number=blockNumber/4*4;
  int trailerBlock=largestModulo4Number+3;//determine trailer block for the sector
  if (blockNumber > 2 && (blockNumber+1)%4 == 0){Serial.print(blockNumber);Serial.println(" is a trailer block:");return 2;}//block number is a trailer block (modulo 4); quit and send error code 2
  Serial.print(blockNumber);
  Serial.println(" is a data block:");
  
  /*****************************************authentication of the desired block for access***********************************************************/
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  //byte PCD_Authenticate(byte command, byte blockAddr, MIFARE_Key *key, Uid *uid);
  //this method is used to authenticate a certain block for writing or reading
  //command: See enumerations above -> PICC_CMD_MF_AUTH_KEY_A = 0x60 (=1100000),    // this command performs authentication with Key A
  //blockAddr is the number of the block from 0 to 15.
  //MIFARE_Key *key is a pointer to the MIFARE_Key struct defined above, this struct needs to be defined for each block. New cards have all A/B= FF FF FF FF FF FF
  //Uid *uid is a pointer to the UID struct that contains the user ID of the card.
  if (status != MFRC522::STATUS_OK) {
         Serial.print("PCD_Authenticate() failed: ");
         Serial.println(mfrc522.GetStatusCodeName(status));
         return 3;//return "3" as error message
  }
  //it appears the authentication needs to be made before every block read/write within a specific sector.
  //If a different sector is being authenticated access to the previous one is lost.


  /*****************************************writing the block***********************************************************/
        
  status = mfrc522.MIFARE_Write(blockNumber, arrayAddress, 16);//valueBlockA is the block number, MIFARE_Write(block number (0-15), byte array containing 16 values, number of bytes in block (=16))
  //status = mfrc522.MIFARE_Write(9, value1Block, 16);
  if (status != MFRC522::STATUS_OK) {
           Serial.print("MIFARE_Write() failed: ");
           Serial.println(mfrc522.GetStatusCodeName(status));
           return 4;//return "4" as error message
  }
  Serial.println("block was written");
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

