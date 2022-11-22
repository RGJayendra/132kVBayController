 
//Time parameters for CB close*******************************************************************************************
int CB_CLS_TIME     = 50;
int CB_CLS_WAIT_TIME= 1000;  //Time delay until CB close
int CB_i            = 0;

//Voltage Setting value 20%*********************************************************************************************
int Vol_Set         =700;  // 20V test ok
unsigned int max_v  =0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Unit Funtional Indicator
  int Logic_Controller       = 6;


//Defining inputs 22 to 53**********************************************************************************************
const int CB_ON_IN              = 22;  
const int CB_OFF_IN             = 24;
const int B_DS01_ON_IN          = 26;
const int B_DS01_OFF_IN         = 28;
const int B_DS02_ON_IN          = 30;
const int B_DS02_OFF_IN         = 32;
const int L_DS_ON_IN            = 34;
const int L_DS_OFF_IN           = 36;
const int ES_ON_IN              = 38;
const int ES_OFF_IN             = 40;
const int ES_BB1_ON_IN          = 42;
const int ES_BB1_OFF_IN         = 44;
const int ES_BB2_ON_IN          = 46;
const int ES_BB2_OFF_IN         = 48;
const int FEEDER_SYNC_IN        = 50;
const int BUS_COUP_ON_IN        = 52;
const int VT_MCBTRIP_ON_IN      = 53;
const int CB_OFF_ORDER_IN       = 45;  // defining by RGJ 
const int CB_ON_ORDER_IN        = 41;
const int BB1_VT_MCBTRIP_ON_IN  = 39;
const int BB2_VT_MCBTRIP_ON_IN  = 37;



//Defining outputs 01 to 19 **************************************************************************************************
const int CB_ON_CMD                       = 14;  
const int CB_PRE_ON_CMD                   = 2;
const int BUS01_DSQ01_RELEASE_ON_CMD      = 3;
const int BUS01_DSQ01_RELEASE_OFF_CMD     = 4;
const int BUS02_DSQ02_RELEASE_ON_CMD      = 5;
const int BUS02_DSQ02_RELEASE_OFF_CMD     = 6;
const int L_DS_RELEASE_ON_CMD             = 19;
const int L_DS_RELEASE_OFF_CMD            = 20;
const int ES_RELEASE_ON_CMD               = 18;
const int SYNC_REQUIRED                   = 17;
const int VT_MCB_TRIP                     = 16;


//Defining veriables **************************************************************************************************
boolean CB_ON=0;
boolean CB_ON_ORDER=0;
boolean CB_OFF=0;
boolean CB_OFF_ORDER=0;
boolean B_DS01_ON=0;
boolean B_DS01_OFF=0;
boolean B_DS02_ON=0;
boolean B_DS02_OFF=0;
boolean L_DS_ON=0;
boolean L_DS_OFF=0;
boolean ES_ON=0;
boolean ES_OFF=0;
boolean ES_BB1_ON=0;
boolean ES_BB1_OFF=0;
boolean ES_BB2_ON=0;
boolean ES_BB2_OFF=0;
boolean SYN_CHK_RELEASE_ON=0;
boolean BUS_COUP_ON=0;
boolean LINE_VOL=0 ;     
boolean BUS01_VOL=0;    
boolean BUS02_VOL=0 ;   
boolean VT_MCBTRIP_ON=0;
boolean BB1_MCBTRIP_ON=0;
boolean BB2_MCBTRIP_ON=0;
boolean FEEDER_SYNC=0;
boolean CB_SWITCHING_RELEASE=0;


//Defining veriables for CB ON cmd**************************************************************************************************
boolean CB_ON_A=0;
boolean CB_ON_B=0;
boolean CB_ON_C=0;
boolean CB_ON_D=0;
boolean CB_ON_E=0;
boolean CB_ON_F=0;
boolean CB_ON_G=0;
boolean CB_ON_H=0;
boolean CB_ON_I=0;
boolean CB_ON_J=0;
boolean CB_ON_K=0;
boolean CB_ON_L=0;
boolean CB_ON_M=0;
boolean CB_ON_N=0;
boolean CB_ON_O=0;
boolean CB_ON_P=0;
boolean CB_ON_Q=0;
boolean CB_ON_R=0;
boolean CB_ON_S=0;
boolean CB_ON_T=0;
boolean CB_ON_X=0;
boolean CB_ON_Y=0;
boolean CB_ON_Z=0;
boolean CB_ON_int=0;

//Defining veriables for analog inputs**************************************************************************************************

boolean Line_Voltage=0;
boolean BB1_Voltage=0;
boolean BB2_Voltage=0;
boolean Feeder_Voltage=0;

//Defining veriables for analog noise filter**************************************************************************************************

#define BUF_SIZE 40

float array_calculate_avg(int * buf, int len);

int   buf[BUF_SIZE]   = {0};
int   buf_index       = 0;
float buf_avg         = 0.0;




void setup() {
  Serial.begin(9600);
  //Assigning inputs to digital IO********************************************************************************************************  
  pinMode(CB_ON_IN, INPUT); // assigning inputs to digital IO
  pinMode(CB_OFF_IN, INPUT);
  pinMode(B_DS01_ON_IN, INPUT);
  pinMode(B_DS01_OFF_IN, INPUT);
  pinMode(B_DS02_ON_IN, INPUT);
  pinMode(B_DS02_OFF_IN, INPUT);
  pinMode(L_DS_ON_IN, INPUT);
  pinMode(L_DS_OFF_IN, INPUT);
  pinMode(ES_ON_IN, INPUT);
  pinMode(ES_OFF_IN, INPUT);
  pinMode(ES_BB1_ON_IN, INPUT);
  pinMode(ES_BB1_OFF_IN, INPUT);
  pinMode(ES_BB2_ON_IN, INPUT);
  pinMode(ES_BB2_OFF_IN, INPUT);
  pinMode(BUS_COUP_ON_IN, INPUT);
  pinMode(VT_MCBTRIP_ON_IN, INPUT);
  pinMode(BB1_VT_MCBTRIP_ON_IN, INPUT);
  pinMode(BB2_VT_MCBTRIP_ON_IN, INPUT);
  pinMode(CB_ON_ORDER_IN, INPUT);  
  pinMode(CB_OFF_ORDER_IN, INPUT);
  pinMode(FEEDER_SYNC_IN, INPUT);
  
  
  

  //Assigning outputs to digital IO********************************************************************************************************
  pinMode(CB_ON_CMD, OUTPUT);
  pinMode(CB_PRE_ON_CMD, OUTPUT);
  pinMode(BUS01_DSQ01_RELEASE_ON_CMD, OUTPUT);
  pinMode(BUS01_DSQ01_RELEASE_OFF_CMD, OUTPUT);
  pinMode(BUS02_DSQ02_RELEASE_ON_CMD, OUTPUT);
  pinMode(BUS02_DSQ02_RELEASE_OFF_CMD, OUTPUT);
  pinMode(L_DS_RELEASE_ON_CMD, OUTPUT);
  pinMode(L_DS_RELEASE_OFF_CMD, OUTPUT);
  pinMode(ES_RELEASE_ON_CMD, OUTPUT);
  pinMode(SYNC_REQUIRED, OUTPUT);
  pinMode(VT_MCB_TRIP, OUTPUT);
  
  
 digitalWrite(CB_ON_CMD, HIGH);
 digitalWrite(CB_PRE_ON_CMD, HIGH);
 digitalWrite(BUS01_DSQ01_RELEASE_ON_CMD,HIGH);
 digitalWrite(BUS01_DSQ01_RELEASE_OFF_CMD, HIGH);
 digitalWrite(BUS02_DSQ02_RELEASE_ON_CMD, HIGH);
 digitalWrite(BUS02_DSQ02_RELEASE_OFF_CMD, HIGH);
 digitalWrite(L_DS_RELEASE_ON_CMD, HIGH);
 digitalWrite(L_DS_RELEASE_OFF_CMD, HIGH);
 digitalWrite(ES_RELEASE_ON_CMD, HIGH);
 digitalWrite(SYNC_REQUIRED, HIGH);
 digitalWrite(VT_MCB_TRIP, HIGH);
 
  
  }

void loop() {

digitalWrite(Logic_Controller,HIGH);// Funtional Indicator
//Reading analog inputs ************************************************************************************************************

            max_v=0;
            for(uint16_t i = 0; i <20; i++){
            uint16_t r =analogRead (A2);//Read From analog channel 2 (A2)
            if (max_v <r) max_v=r;
            delayMicroseconds (1);}
            if (BUF_SIZE == buf_index){buf_index = 0;}
            buf[buf_index++] = max_v;
            buf_avg = array_calculate_avg(buf, BUF_SIZE);
            

if (buf_avg<0) {Line_Voltage=LOW;}
else if (buf_avg<(Vol_Set)) {Line_Voltage=HIGH;} 
else {Line_Voltage=LOW;}
Serial.println(buf_avg);



//Reading digital inputs ************************************************************************************************************
CB_ON = digitalRead(CB_ON_IN); // Reading digital inputs
CB_OFF = digitalRead(CB_OFF_IN);
B_DS01_ON=digitalRead(B_DS01_ON_IN);
B_DS01_OFF=digitalRead(B_DS01_OFF_IN);
B_DS02_ON=digitalRead(B_DS02_ON_IN);
B_DS02_OFF=digitalRead(B_DS02_OFF_IN);
L_DS_ON=digitalRead(L_DS_ON_IN);
L_DS_OFF=digitalRead(L_DS_OFF_IN);
ES_ON=digitalRead(ES_ON_IN);
ES_OFF=digitalRead(ES_OFF_IN);
ES_BB1_ON=digitalRead(ES_BB1_ON_IN);
ES_BB1_OFF=digitalRead(ES_BB1_OFF_IN);
ES_BB2_ON=digitalRead(ES_BB2_ON_IN);
ES_BB2_OFF=digitalRead(ES_BB2_OFF_IN);
BUS_COUP_ON=digitalRead(BUS_COUP_ON_IN);
VT_MCBTRIP_ON=digitalRead(VT_MCBTRIP_ON_IN);
BB1_MCBTRIP_ON=digitalRead(BB1_VT_MCBTRIP_ON_IN);
BB2_MCBTRIP_ON=digitalRead(BB2_VT_MCBTRIP_ON_IN);
CB_ON_ORDER=digitalRead(CB_ON_ORDER_IN);
CB_OFF_ORDER=digitalRead(CB_OFF_ORDER_IN);
FEEDER_SYNC=digitalRead(FEEDER_SYNC_IN);


//For testing by RGJ *****************************************************************************************************
                                                        //Line_Voltage=HIGH; 
                                                        //BB1_Voltage=HIGH;
                                                        //BB2_Voltage=HIGH;
                                                        Feeder_Voltage=HIGH;




//Q1 Open/Close Release Operation*******************************************************************************************

if  (((B_DS02_ON) && not(B_DS02_OFF) && not(ES_BB1_ON) && (ES_BB1_OFF) && (BUS_COUP_ON))
or ( (CB_OFF) && not(CB_ON)&&(B_DS02_OFF) && not (B_DS02_ON ) && not (ES_BB1_ON) && (ES_BB1_OFF))){  //(CB_OFF) && not(CB_ON)&&
  
  digitalWrite(BUS01_DSQ01_RELEASE_ON_CMD,LOW);
  digitalWrite(BUS01_DSQ01_RELEASE_OFF_CMD,LOW);
}
else{digitalWrite(BUS01_DSQ01_RELEASE_ON_CMD,HIGH);
     digitalWrite(BUS01_DSQ01_RELEASE_OFF_CMD,HIGH);}
 
  
//Q2 Open/Close Release Operation**********************************************************************************************

if  (((B_DS01_ON) && not(B_DS01_OFF) && not(ES_BB2_ON) && (ES_BB2_OFF) && (BUS_COUP_ON))
or ((CB_OFF) && not(CB_ON) && (B_DS01_OFF) && not (B_DS01_ON ) && not (ES_BB2_ON) && (ES_BB2_OFF))){
  
  digitalWrite(BUS02_DSQ02_RELEASE_ON_CMD,LOW);
  digitalWrite(BUS02_DSQ02_RELEASE_OFF_CMD,LOW);
}
else{digitalWrite(BUS02_DSQ02_RELEASE_ON_CMD,HIGH);
     digitalWrite(BUS02_DSQ02_RELEASE_OFF_CMD,HIGH);}


//Q8 - ES Release Operation***************************************************************************************************

if  ( Line_Voltage && L_DS_OFF && not(L_DS_ON) && not (VT_MCBTRIP_ON))
      {digitalWrite(ES_RELEASE_ON_CMD,LOW);}
else  {digitalWrite(ES_RELEASE_ON_CMD,HIGH);}

     
//Q0 Close *********************************************************************************************************************

// Switching release Q0 as per the logic given by PD-CEB

CB_ON_A = (B_DS01_OFF xor B_DS01_ON); 

CB_ON_B = (B_DS02_OFF xor B_DS02_ON); 

CB_ON_C = (L_DS_OFF xor L_DS_ON);

CB_ON_E = (B_DS01_ON && BB1_MCBTRIP_ON) ;

CB_ON_F = (B_DS02_ON && BB2_MCBTRIP_ON) ;

CB_ON_G = (VT_MCBTRIP_ON) ;

CB_ON_D = (CB_ON_E or CB_ON_F or CB_ON_G) ;

CB_SWITCHING_RELEASE = (CB_ON_A && CB_ON_B && CB_ON_C && not(CB_ON_D)) ;

if (CB_SWITCHING_RELEASE) { digitalWrite(CB_PRE_ON_CMD,LOW); } else { digitalWrite(CB_PRE_ON_CMD,HIGH);}
    

          /// Final CB_ON_CMD
            if ((CB_ON_ORDER or CB_ON_int) && (FEEDER_SYNC) && CB_SWITCHING_RELEASE && 
                     (not(CB_OFF_ORDER))&&(not(CB_ON)) ) {
                    CB_ON_int=1;
                    CB_i++;
                    
                    if (CB_i<CB_CLS_TIME){digitalWrite(CB_ON_CMD,LOW);}
                    else { digitalWrite(CB_ON_CMD,HIGH);}
                    
                    if (CB_CLS_WAIT_TIME<CB_i){CB_ON_int=0;}
           
            }else if (CB_OFF_ORDER or CB_ON) {
             digitalWrite(CB_ON_CMD,HIGH);
             CB_ON_int=0;
             CB_i=0;} 
             
             else {
               digitalWrite(CB_ON_CMD,HIGH);
               CB_ON_int=0;
               CB_i=0;}

//        //Testing of CB ON Order
//        
//        if (CB_ON_ORDER) {
//          Serial.println("CB_ON_ORDER");
//          if (CB_SWITCHING_RELEASE){Serial.println("CB_SWITCHING_RELEASE");}
//          if (not(CB_OFF_ORDER)){Serial.println("No CB Off Order");}
//          if (not(CB_ON)){Serial.println("No CB On");}
//          else {Serial.println("CB On");}}
//       
//       
//        if (FEEDER_SYNC){Serial.println("Feeder Sync ok");}
//         
//         delayMicroseconds (500);




//Q9 Release (L  D/S)*****************************************************************************************************************

if ((CB_OFF) && not(CB_ON) && not(ES_ON) && (ES_OFF)){
   digitalWrite(L_DS_RELEASE_ON_CMD, LOW); 
   digitalWrite(L_DS_RELEASE_OFF_CMD, LOW);} 
   else {
  digitalWrite(L_DS_RELEASE_ON_CMD, HIGH);
  digitalWrite(L_DS_RELEASE_OFF_CMD,HIGH);}

 //Sync ok signal***********************************************************************************************************************
if (FEEDER_SYNC){
   digitalWrite(SYNC_REQUIRED, LOW);} 
   else {
   digitalWrite(SYNC_REQUIRED,HIGH);}

//VT MCB on signal***********************************************************************************************************************

if (VT_MCBTRIP_ON){
   digitalWrite(VT_MCB_TRIP, LOW);} 
   else {
   digitalWrite(VT_MCB_TRIP,HIGH);}


  }

float array_calculate_avg(int * buf, int len)
{
    int sum = 0;

    for (int j=0; j<len; j++) {
      sum+=buf[j];
    }

 return ((float)sum)/((float)len);
}

 
